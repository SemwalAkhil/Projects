from dotenv import load_dotenv
import os
import pymysql
load_dotenv(r".env.local")

# ORACLE XE DB
user2 = os.getenv("USER2")
pass2 = os.getenv("PASS2")

# AIVEN MYSQL
dsn = os.getenv("DSN")
db3 = os.getenv("pymysqldb")
host3 = os.getenv("pymysqlhost")
pass3 = os.getenv("pymysqlpassword")
user3 = os.getenv("user")
timeout = 30

ORACLE_CONFIG = {
    "user": user2,
    "password": pass2,
    "dsn": dsn
}

PYMYSQL_CONFIG = {
    "charset":"utf8mb4",
  "connect_timeout":timeout,
  "cursorclass":pymysql.cursors.DictCursor,
  "db":db3,
  "host":host3,
  "password":pass3,
  "read_timeout":timeout,
  "port":25218,
  "user":user3,
  "write_timeout":timeout,
}
