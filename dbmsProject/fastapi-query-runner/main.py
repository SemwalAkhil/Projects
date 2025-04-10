from fastapi import FastAPI, HTTPException, Query
from database import get_mysql_connection, get_oracle_connection
from fastapi.responses import FileResponse
from fastapi.staticfiles import StaticFiles
from pydantic import BaseModel
import os
import uvicorn
from typing import Optional, Dict, Union
from mysql.connector.connection import MySQLConnection
# Import your Oracle connection class too if available, else use `Any`
from typing import Any

app = FastAPI()

# Directory to load SQL scripts dynamically
SQL_SCRIPTS_DIR = "./sql_scripts"

# Persistent DB connections
connections: Dict[str, Optional[Union[MySQLConnection, Any]]] = {
    "mysql": None,
    "oracle": None
}

class QueryRequest(BaseModel):
    db_type: str
    sql: str

# Mount 'static' directory for serving frontend assets
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
def get_script_content(category: str, script_name: str):
    """Retrieve the script content by category and name."""
    script_path = os.path.join(SQL_SCRIPTS_DIR, category, script_name)

    if not os.path.exists(script_path):
        raise HTTPException(status_code=404, detail="Script not found")

    with open(script_path, "r", encoding="utf-8") as file:
        content = file.read()

    return {"script_name": script_name, "content": content}

@app.post("/execute-query")
def execute_query(request: QueryRequest):
    """Execute SQL query and return results."""
    try:
        # Get the persistent database connection
        conn = connections.get(request.db_type)
        if not conn:
            raise HTTPException(status_code=500, detail=f"No {request.db_type} connection available.")

        cursor = conn.cursor()

        # Enable DBMS_OUTPUT for Oracle
        if request.db_type == "oracle":
            cursor.execute("BEGIN DBMS_OUTPUT.ENABLE(NULL); END;")

        queries = [q.strip() for q in request.sql.strip().split(";") if q.strip()]
        output_messages = []
        data = None
        columns = None

        for query in queries:
            if query.find("--") != -1:
                continue
            
            cursor.execute(query)

            if query.lower().startswith(("select", "desc", "show")):
                data = cursor.fetchall()
                columns = [desc[0] for desc in cursor.description] if cursor.description else []
                output_messages.append("Query executed successfully.")
            else:
                # conn.commit()
                output_messages.append(f"{cursor.rowcount} row(s) affected.")

            # Fetch DBMS_OUTPUT messages for Oracle
            if request.db_type == "oracle":
                output_cursor = conn.cursor()
                output_cursor.execute("""
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
                try:
                    output_messages.extend([row[0] for row in output_cursor.fetchall()])
                except:
                    pass  # No output to fetch
                output_cursor.close()

        cursor.close()

        return {
            "columns": columns,
            "data": data,
            "messages": output_messages
        }
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))

@app.on_event("startup")
def connect_to_databases():
    try:
        connections["mysql"] = get_mysql_connection()
        connections["oracle"] = get_oracle_connection()
    except Exception as e:
        print(f"Error connecting to databases: {e}")

@app.on_event("shutdown")
def close_database_connections():
    for conn in connections.values():
        if conn:
            try:
                conn.close()
            except:
                pass

# Configure application for Render deployment
if __name__ == "__main__":
    port = int(os.getenv("PORT", 10000))  # Render dynamically assigns a port
    uvicorn.run(app, host="0.0.0.0", port=port)