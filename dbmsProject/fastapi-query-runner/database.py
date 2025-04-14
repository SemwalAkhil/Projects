import mysql.connector
from mysql.connector import Error
import oracledb
import pymysql
from config import MYSQL_CONFIG, ORACLE_CONFIG, PYMYSQL_CONFIG

def get_mysql_connection():
    """Establish and return a connection to MySQL database."""
    # temp_config = MYSQL_CONFIG.copy()
    # temp_config.pop("database")  # Remove 'database' key to connect without specifying a DB
    
    try:
        # First, connect to MySQL server (without specifying a database)
        # conn = mysql.connector.connect(**PYMYSQL_CONFIG)
        # cursor = conn.cursor()

        # # Ensure that the target database exists, create it if necessary
        # # cursor.execute(f"CREATE DATABASE IF NOT EXISTS {MYSQL_CONFIG['database']}")
        # cursor.close()  # Close cursor after database check

        # conn.close()  # Close the connection after ensuring database existence

        # Now that we know the database exists, connect to the specific database
        return pymysql.connect(**PYMYSQL_CONFIG)
    
    except Error as e:
        # Handle MySQL connection errors
        print("Error while connecting to MySQL:", e)
        return None

def get_oracle_connection():
    """Establish and return a connection to Oracle database."""
    try:
        # Connect to Oracle using the provided configuration from the config file
        return oracledb.connect(**ORACLE_CONFIG)
    except Exception as e:
        # Handle Oracle connection errors
        print("Error while connecting to Oracle:", e)
        return None
