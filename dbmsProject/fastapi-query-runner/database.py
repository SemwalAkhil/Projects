import pymysql
import oracledb
from config import ORACLE_CONFIG, PYMYSQL_CONFIG

def get_mysql_connection():
    """Establish and return a connection to MySQL database using pymysql."""
    try:
        return pymysql.connect(**PYMYSQL_CONFIG)
    except pymysql.MySQLError as e:
        print("Error while connecting to MySQL:", e)
        return None

def get_oracle_connection():
    """Establish and return a connection to Oracle database."""
    try:
        return oracledb.connect(**ORACLE_CONFIG)
    except oracledb.Error as e:
        print("Error while connecting to Oracle:", e)
        return None
