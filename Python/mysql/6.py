# 4th without hash & pdf check
# %%
import gspread
from google.oauth2.service_account import Credentials
from datetime import datetime
import re

# %%
def fetch_data_from_google_sheet(sheet_name, sheet_range):
    # Define the scope (permissions required)
    scope = [
        "https://www.googleapis.com/auth/spreadsheets.readonly",
        "https://www.googleapis.com/auth/drive.readonly"
    ]

    # Authenticate using the service account credentials JSON file
    credentials = Credentials.from_service_account_file(r"D:\Projects\credentials\credentials.json", scopes=scope)

    # Authorize with Google Sheets API
    client = gspread.authorize(credentials)

    # Open the Google Sheet by name
    sheet = client.open(sheet_name).sheet1
    # sheet = client.open_by_url("https://docs.google.com/spreadsheets/d/YOUR_SPREADSHEET_ID")


    # Fetch data from the specified range
    data = sheet.get(sheet_range)
    # dataDict = {}
    return data
    # for row in data:
    #     dataDict[row[3].strip().lower()] = [
    #         str(row[2]).split(sep="/")[0] or "NULL",
    #         row[4].strip(),
    #         row[7].strip(),
    #         row[8].strip(),
    #         row[9].strip()]
    # return dataDict

def setValue(data:list,index:int):
    try:
        val = data[index]
    except:
        val = None
    return val
# %%
def generate_sql_file(data:list, output_file):
    with open(output_file, "w") as f:
        f.write("create table students (rollno bigint unsigned, name varchar(1000), dob date, fname varchar(1000), mname varchar(1000), age int unsigned, contact bigint unsigned, email varchar(1000), address varchar(1000));\nDELETE FROM students;\n")
        
        
        # Insert data
        for row in data:
            rollno = setValue(row,2)
            name = setValue(row,3)
            dob_raw = setValue(row,4)
            fname = setValue(row,5)
            mname = setValue(row,6)
            contact_raw = setValue(row,7)
            email = setValue(row,8)
            address = setValue(row,8)

            try:
                dob_datetime = datetime.strptime(dob_raw, "%d/%m/%Y")
                dob = dob_datetime.strftime("'%Y-%m-%d'")
            except:
                dob = "NULL"

            # Sanitize contact (digits only)
            try:
                contact = "".join(filter(str.isdigit, contact_raw)) 
            except:
                contact = "NULL"

            # Sanitize and quote values (handle empty strings)
            def sanitize(value):
                if not value:
                    return "NULL"
                # Use a variable to avoid backslashes in the f-string
                single_quote = "'"
                sanitized = str(value).replace(single_quote, single_quote * 2)
                return f"'{sanitized}'"

            values = [
                rollno if rollno != None else "NULL",  # rollno (bigint or NULL)
                sanitize(name),
                dob,
                sanitize(fname),
                sanitize(mname),
                "NULL",  # age
                contact if contact != "NULL" else "NULL",  # contact (bigint or NULL)
                sanitize(email),
                sanitize(address)
            ]

            query = f"INSERT INTO students (rollno, name, dob, fname, mname, age, contact, email, address) VALUES ({', '.join(values)});\n"
            f.write(query)
    print(f"SQL queries saved to {output_file}")
    f.close()

if __name__ == "__main__":
    # Replace with your Google Sheet name and range (e.g., "Sheet1!A2:I")
    google_sheet_name = "Untitled form (Responses)"
    data_range = "A2:J"  # Adjust range to match your sheet's data

    # Fetch data and generate SQL file
    sheet_data = fetch_data_from_google_sheet(google_sheet_name, data_range)
    # print(sheet_data)
    generate_sql_file(sheet_data, "insert_data.sql")