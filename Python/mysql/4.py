# %%
import gspread
from google.oauth2.service_account import Credentials
from datetime import datetime
import pandas as pd
import hashlib
import random
import re
import pdfplumber
import os

def encrypt_code(code: str) -> str:
    if not code.isdigit() or len(code) != 4:
        raise ValueError("Input must be a 4-digit numeric string.")
    
    # Generate a random salt of 4 digits
    salt = str(random.randint(1000, 9999))
    
    # Hash the input code combined with the salt
    hash_digest = hashlib.sha256((code + salt).encode()).hexdigest()
    numeric_hash = ''.join(str(int(c, 16)) for c in hash_digest[:8])
    
    # Mix the hash and salt to create a 12-digit encrypted code
    encrypted_code = numeric_hash[:6] + salt[:2] + numeric_hash[6:] + salt[2:]
    
    return encrypted_code[:12]  # Ensure it's exactly 12 digits

def extract_text_from_pdf(pdf_path):
    """
    Extracts text from a PDF file.

    Args:
        pdf_path: The path to the PDF file.

    Returns:
        A string containing the extracted text, or None if an error occurs.
    """
    try:
        with pdfplumber.open(pdf_path) as pdf_file:
            dataList = []
            for page in (pdf_file.pages):
                text = page.extract_text()
                try:
                    roll = re.findall("Roll No. ([0-9]*)",text)[0]
                except:
                    # print("Skipped a roll")
                    continue
                try:
                    name = re.findall("Candidate Name ([A-Z ]*)",text)[0]
                    fname = re.findall("Father's Name ([A-Z ]*)",text)[0]
                    mname = re.findall("Mother's Name ([A-Z ]*)",text)[0]
                except:
                    print(f"Failed in evaluating roll no {roll} skipping to next")
                    continue
                if len(roll):
                    dataList.append([int(roll),name,fname,mname])
            # print(len(dataList))
            return dataList
    except FileNotFoundError:
        print(f"Error: File not found at {pdf_path}")
        return None
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        return None
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
    dataDict = {}
    for row in data:
        dataDict[row[3].strip().lower()] = [
            str(row[2]).split(sep="/")[0] or "NULL",
            row[4].strip(),
            row[7].strip(),
            row[8].strip(),
            row[9].strip()]
    return dataDict

def generate_sql_file(data:dict, output_file):
    if not (os.path.isdir("./batfiles")):
        os.mkdir("./batfiles")
    with open(output_file, "w") as f:
        hashRecords = open("hashRecords.txt","w")
        f.write("create table students (rollno bigint unsigned, name varchar(1000), dob date, fname varchar(1000), mname varchar(1000), age int unsigned, contact bigint unsigned, email varchar(1000), address varchar(1000));\nDELETE FROM students;\n")
        
        dataList = extract_text_from_pdf(r"D:\Downloads\bca2.pdf") or []
        # Insert data
        for dataEle in dataList:
            name = dataEle[1].lower()
            fname = dataEle[2].lower()
            mname = dataEle[3].lower()
            
            def setValue(data:dict,name:str,index:int):
                try:
                    val = data[name][index]
                except:
                    val = None
                return val
            
            rollno = setValue(data,name,0)
            
            dob_raw = setValue(data,name,1)
            contact_raw = setValue(data,name,2)
            email = setValue(data,name,3)
            address = setValue(data,name,4)
            if rollno:
                hashCode = encrypt_code(rollno)
                hashRecords.write(f"{rollno} {hashCode}\n")
                script =  open(f"./batFiles/insert_data{rollno}.bat","w")
                scriptOpen = True
            else:
                scriptOpen = False

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
            if scriptOpen:
                script.write(
                f"""@echo off
REM Usage: insert_data.bat [DB_USER] [DB_PASS] [DB_NAME] [HASH]

set DB_HOST=localhost
set DB_USER=%~1
set DB_PASS=%~2
set DB_NAME=%~3
set INPUT_HASH=%~4

REM Predefined hash
set PREDEFINED_HASH={hashCode}

REM Check if the provided hash matches the predefined hash
if NOT "%INPUT_HASH%"=="%PREDEFINED_HASH%" (
    echo Invalid hash. Exiting...
    exit /b 1
)

set SQL_FILE=insert_data.sql

REM Check if SQL file exists
if not exist "%SQL_FILE%" (
    echo SQL file %SQL_FILE% not found. Exiting...
    exit /b 1
)

REM Execute MySQL command with arguments
mysql -h %DB_HOST% -u %DB_USER% -p%DB_PASS% %DB_NAME% < "%SQL_FILE%"

if %ERRORLEVEL% NEQ 0 (
    echo MySQL execution failed. Exiting...
    exit /b 1
)

REM Remove SQL file after execution
del "%SQL_FILE%"

echo Data insertion completed!

REM Remove the line below if not intended, or correct the filename

del "insert_data{rollno}.bat"

exit /b 0
                """)
            
                script.close()
    print(f"SQL queries saved to {output_file}")
    print("Hashes saved at hashRecords.txt")
    hashRecords.close()

if __name__ == "__main__":
    # Replace with your Google Sheet name and range (e.g., "Sheet1!A2:I")
    google_sheet_name = "Untitled form (Responses)"
    data_range = "A2:J"  # Adjust range to match your sheet's data

    # Fetch data and generate SQL file
    sheet_data = fetch_data_from_google_sheet(google_sheet_name, data_range)
    # print(sheet_data)
    generate_sql_file(sheet_data, "insert_data.sql")