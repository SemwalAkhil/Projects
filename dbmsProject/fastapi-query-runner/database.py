import mysql.connector
from mysql.connector import Error
import oracledb
from config import MYSQL_CONFIG, ORACLE_CONFIG

def get_mysql_connection():
    temp_config = MYSQL_CONFIG.copy()
    temp_config.pop("database")  # Remove 'database' key to connect without specifying a DB
    
    try:
        # Connect to MySQL without specifying a database
        conn = mysql.connector.connect(**temp_config)
        cursor = conn.cursor()
        
        # Check if database exists
        cursor.execute(f"CREATE DATABASE IF NOT EXISTS {MYSQL_CONFIG['database']}")
        cursor.close()
        conn.close()
        
        # Now, connect to the specified database
        return mysql.connector.connect(**MYSQL_CONFIG)
    
    except Error as e:
        print("Error while connecting to MySQL:", e)
        return None

def get_oracle_connection():
    return oracledb.connect(**ORACLE_CONFIG)
