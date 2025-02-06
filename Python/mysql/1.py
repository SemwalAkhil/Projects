import mysql.connector
from mysql.connector import Error
import json
table_name = "students"
with open(r"D:\Projects\credentials\sqlCredentials.json","r") as inFile:
    creds = inFile.read()
creds = json.loads(creds)
HOST = creds["host"]
USER = creds["user"]
PASSWORD = creds["password"]
DATABASE = creds["database"]

try:
    # Establish connection to the database
    connection = mysql.connector.connect(
        host=HOST,
        user=USER,
        password=PASSWORD,
        database=DATABASE
    )

    if connection.is_connected():
        cursor = connection.cursor()
        try:
            query = f"select count(*) from {table_name}"
            cursor.execute(query)
            cursor.fetchone()
            if cursor.rowcount:
                print("Removing old data")
                query = f"delete from {table_name}" # emptying table before insertion
                print(1)
                cursor.execute(query)
                print(2)
                cursor.fetchone()
                print(3)
        except:
            print(f"Table not found creating new table {table_name}")
            query = f"create table {table_name} (rollno bigint unsigned, name varchar(1000), dob date, fname varchar(1000), mname varchar(1000), age int unsigned, contact bigint unsigned, email varchar(1000), address varchar(1000));"
            cursor.execute(query)
            cursor.fetchone()

        # SQL query to insert data
            
        insert_query = """
                insert into {} values (%s, %s, %s, %s, %s, %s, %s, %s, %s)
        """.format(table_name)

        # Data to be inserted
        data = [
            ("1234","abcd","2005-07-29","def","lmno",None,"9000000000","abcd@gmail.com","#123, abc city, def state, 100000")
        ]

        # # Execute the query with multiple rows
        cursor.executemany(insert_query, data)

        # Commit the transaction
        connection.commit()

        print(f"{cursor.rowcount} rows inserted successfully!")

except Error as e:
    print(f"Error: {e}")

finally:
    # Close the connection
    if connection.is_connected():
        cursor.close()
        connection.close()
        print("MySQL connection is closed.")
