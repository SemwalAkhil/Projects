import pandas as pd
import pymysql
import json

with open(r"D:\Projects\credentials\sqlCredentials.json","r") as inFile:
    creds = inFile.read()
creds = json.loads(creds)
HOST = creds["host"]
USER = creds["user"]
PASSWORD = creds["password"]
DATABASE = creds["database"]

# Connect to MySQL
conn = pymysql.connect(host=HOST, user=USER, password=PASSWORD, database=DATABASE)
cursor = conn.cursor()

cursor.execute("DROP TABLE users")
cursor.execute("CREATE TABLE users(roll bigint unsigned,name varchar(1000),fname varchar(1000),mname varchar(1000))")

# Read CSV
df = pd.read_csv(r"D:\Projects\May,2024Bachelor of Computer Applicationdata.csv")

def sanitize(value):
    if type(value) == int:
        return value
    if not value:
        return "NULL"
    # Use a variable to avoid backslashes in the f-string
    single_quote = "'"
    sanitized = str(value).replace(single_quote, single_quote * 2)
    return f"{sanitized}"

# Insert data
for _, row in df.iterrows():
    cursor.execute("INSERT INTO users VALUES (%s,%s, %s, %s)", tuple(sanitize(data) for data in row))

conn.commit()
conn.close()
print("Data inserted successfully!")
