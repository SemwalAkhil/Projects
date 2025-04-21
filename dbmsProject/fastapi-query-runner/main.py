from fastapi import FastAPI, HTTPException
from database import get_mysql_connection, get_oracle_connection
from fastapi.responses import FileResponse
from fastapi.staticfiles import StaticFiles
from pydantic import BaseModel
import os
import uvicorn
from typing import Optional, Dict, Union
from mysql.connector.connection import MySQLConnection
from oracledb import Connection
import oracledb
import re
from typing import Any

app = FastAPI()

# Directory where SQL scripts are stored
SQL_SCRIPTS_DIR = "./sql_scripts"

# Persistent DB connections to avoid opening/closing connections repeatedly
connections: Dict[str, Optional[Union[MySQLConnection, Connection, Any]]] = {
    "mysql": None,
    "oracle": None
}

class QueryRequest(BaseModel):
    db_type: str
    sql: str

# Mount 'static' directory to serve frontend assets like JS, CSS, etc.
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
    """Retrieve the content of a specific SQL script by category and name."""
    script_path = os.path.join(SQL_SCRIPTS_DIR, category, script_name)

    if not os.path.exists(script_path):
        raise HTTPException(status_code=404, detail="Script not found")

    with open(script_path, "r", encoding="utf-8") as file:
        content = file.read()
    print(content.count("\n"))
    return {"script_name": script_name, "content": content}

@app.post("/execute-query")
def execute_query(request: QueryRequest):
    """Execute SQL query and return the results or status message."""
    try:
        # Get the persistent database connection based on db_type
        conn = connections.get(request.db_type)
        if not conn:
            raise HTTPException(status_code=500, detail=f"No {request.db_type} connection available.")

        cursor = conn.cursor()

        # Enable DBMS_OUTPUT for Oracle queries
        if request.db_type == "oracle":
            cursor.callproc("dbms_output.enable")

            # Split queries and keep track of DECLARE/BEGIN blocks for Oracle
            queries = []
            for match in re.finditer(
                r"(.*?)(?=(?:declare|begin|create or replace (?:trigger|function))|$)((?:declare|begin|create or replace (?:trigger|function)).*?end;)?",
                request.sql.strip(), re.DOTALL | re.IGNORECASE):
                queries.extend([i for i in match.group(1).split("\n") if i] + [match.group(2)])
        else:
            # For MySQL, split by semicolons to separate queries
            queries = [q.strip() for q in request.sql.strip().split("\n") if q.strip()]

        output_messages = []
        data = None
        columns = None
        tempQuery = ""
        # Execute each query and process the results
        for query in queries:
            if query is None or query.startswith("--"):  # Skip empty or comment lines
                continue
            query = query.lower()
            tempQuery += query
            if (not query.strip().endswith(";")) and query != queries[-1]:
                continue
            else:
                query = tempQuery
                tempQuery = ""
            # Clean up any unnecessary slashes from queries (specific to Oracle or other systems)
            query = re.sub(r"(?:^\s*/|/\s*$|(?<!END)\s*;$)", "", query)

            print(f"<-----\n{query}\n----->")

            # Execute the query
            cursor.execute(query)

            if query.lower().startswith(("select", "desc", "show")):
                # If the query is a SELECT statement, fetch the result data
                data = cursor.fetchall()
                columns = [desc[0] for desc in cursor.description] if cursor.description else []
                output_messages.append("Query executed successfully.")
            elif query.lower().startswith(("begin", "declare")) and isinstance(cursor, oracledb.Cursor):
                try:
                    # Fetch DBMS_OUTPUT messages for Oracle
                    statusVar = cursor.var(int)
                    lineVar = cursor.var(str)
                    while True:
                        cursor.callproc("dbms_output.get_line", (lineVar, statusVar))
                        if statusVar.getvalue() != 0:
                            break
                        output_messages.append(lineVar.getvalue())
                except Exception as e:
                    output_messages.append(f"Error fetching DBMS_OUTPUT: {e}")
            else:
                output_messages.append(f"{cursor.rowcount} row(s) affected.")

        cursor.close()

        # Return the results of the query execution
        return {
            "columns": columns,
            "data": data,
            "messages": output_messages
        }
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))

@app.on_event("startup")
def connect_to_databases():
    """Connect to MySQL and Oracle databases on startup."""
    try:
        connections["mysql"] = get_mysql_connection()
        connections["oracle"] = get_oracle_connection()
    except Exception as e:
        print(f"Error connecting to databases: {e}")

@app.on_event("shutdown")
def close_database_connections():
    """Close all open database connections on shutdown."""
    for conn in connections.values():
        if conn:
            try:
                conn.close()
            except Exception as e:
                print(f"Error closing connection: {e}")

# Run the application using Uvicorn with dynamic port from the environment
if __name__ == "__main__":
    port = int(os.getenv("PORT", 8080))
    uvicorn.run(app, host="0.0.0.0", port=port)
