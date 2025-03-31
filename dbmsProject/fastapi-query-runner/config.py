from dotenv import load_dotenv
import os
load_dotenv(r".\.env.local")

user1 = os.getenv("USER1")
pass1 = os.getenv("PASS1")
user2 = os.getenv("USER2")
pass2 = os.getenv("PASS2")
host = os.getenv("HOST")
db = os.getenv("DB")
dsn = os.getenv("DSN")

print(user2,pass2)

MYSQL_CONFIG = {
    "host": host,
    "user": user1,
    "password": pass1,
    "database": db,
    "port": 3306  # Default MySQL port
}

ORACLE_CONFIG = {
    "user": user2,
    "password": pass2,
    "dsn": dsn
}
