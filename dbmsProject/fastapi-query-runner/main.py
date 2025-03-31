from fastapi import FastAPI, HTTPException, Query
from database import get_mysql_connection, get_oracle_connection
from fastapi.responses import HTMLResponse
import os
from fastapi.staticfiles import StaticFiles
from fastapi.responses import FileResponse
from pydantic import BaseModel
import re
import uvicorn

app = FastAPI()

# Load SQL scripts dynamically from a folder
SQL_SCRIPTS_DIR = "./sql_scripts"

class QueryRequest(BaseModel):
    db_type: str
    sql: str

# Mount 'static' directory for serving static files
app.mount("/static", StaticFiles(directory="static"), name="static")

# Serve index.html as the homepage
@app.get("/")
def home():
    return FileResponse("static/index.html")

@app.get("/get-sql-scripts")
def get_sql_scripts():
    """Fetch available SQL scripts categorized by folders."""
    categories = {}
    for category in os.listdir(SQL_SCRIPTS_DIR):
        category_path = os.path.join(SQL_SCRIPTS_DIR, category)
        if os.path.isdir(category_path):
            categories[category] = [
                file for file in os.listdir(category_path) if file.endswith(".sql")
            ]
    return {"categories": categories}

@app.get("/get-script-content/")
async def get_script_content(category: str, script_name: str):
    """Get the script content by the name and folder category"""
    script_path = os.path.join(SQL_SCRIPTS_DIR, category, script_name)

    if not os.path.exists(script_path):
        raise HTTPException(status_code=404, detail="Script not found")

    with open(script_path, "r", encoding="utf-8") as file:
        content = file.read()

    return {"script_name": script_name, "content": content}

@app.post("/execute-query")
async def execute_query(request: QueryRequest):
    """Execute query as requested"""
    output_messages = []
    columns = None
    try:
        if request.db_type == "mysql":
            conn = get_mysql_connection()
        elif request.db_type == "oracle":
            conn = get_oracle_connection()
        else:
            raise HTTPException(status_code=400, detail="Unsupported database type")

        if not conn:
            raise HTTPException(status_code=400, detail="Connection Failed")

        cursor = conn.cursor()
        
        # Enable DBMS_OUTPUT buffer (for Oracle)
        if request.db_type == "oracle":
            cursor.execute("BEGIN DBMS_OUTPUT.ENABLE(NULL); END;")
        
        queries = request.sql.strip().split(";")
        messages = []
        for query in queries:
            query = query.strip()
            if not cursor:
                raise HTTPException(status_code=400, detail="Cursor creation failed")
            cursor.execute(query)
            # Fetch column names if query returns rows
            if query.lower().startswith(("select","desc","show")):
                data = cursor.fetchall()
                columns = [desc[0] for desc in cursor.description]  # Fetch column names
                output_messages.append("Query executed successfully.")
            else:
                conn.commit()  # Commit for INSERT, UPDATE, DELETE
                output_messages.append(f"{cursor.rowcount} row(s) affected.")


            if request.db_type == "oracle":
                output_var = conn.cursor()
                # Execute the procedure to get DBMS_OUTPUT messages
                output_var.execute("""
                DECLARE 
                    l_line VARCHAR2(32767);
                    l_done NUMBER;
                BEGIN 
                    LOOP
                        DBMS_OUTPUT.GET_LINE(l_line, l_done);
                        EXIT WHEN l_done = 1;
                        DBMS_OUTPUT.PUT_LINE(l_line);
                    END LOOP;
                END;
            """)
                # Extract the messages from the output variable
                try:
                    for i in output_var.fetchall():
                        output_messages.append(i[0])
                except:
                    print("failed fetching")

                output_var.close()

        cursor.close()
        conn.close()

        return {
            "columns": columns or None,
            "data": data if request.sql.strip().lower().startswith(("select","desc","show")) else None,
            "messages": [msg for msg in output_messages]  # Extract messages from tuples
        }

    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))

if __name__ == "__main__":
    port = int(os.getenv("PORT", 10000))  # Use Render's port if available
    uvicorn.run(app, host="0.0.0.0", port=port)