# import oracledb
# from config import ORACLE_CONFIG

# try:
#     print(ORACLE_CONFIG)
#     conn = oracledb.connect(**ORACLE_CONFIG)
#     print("✅ Successfully connected to Oracle!")
#     conn.close()
# except Exception as e:
#     print("❌ Connection failed:", e)

import pymysql

conn = pymysql.connect(
    host="192.168.1.5",
    user="seka",
    password="seka297",
    database="bca_2nd",
    port=3306
)
print("Connected!")
