# SPECIALIZED TO TAKE ROLL NO. FROM PDF
# SELENIUM SCRAPPER V
from selenium import webdriver
from selenium.webdriver.common.by import By
import re
import os
from PIL import Image
import io
from selenium.webdriver.chrome.options import Options
import csv
import datetime
from pypdf import PdfReader

def clear_screen():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

def extract_text_from_pdf(pdf_path):
    """
    Extracts text from a PDF file.

    Args:
        pdf_path: The path to the PDF file.

    Returns:
        A string containing the extracted text, or None if an error occurs.
    """
    try:
        with open(pdf_path, 'rb') as pdf_file:
            reader = PdfReader(pdf_file)  # Use PdfReader for newer PyPDF2 versions
            rollList = []
            for page_num in range(len(reader.pages)):
                page = reader.pages[page_num]
                text = re.findall("Roll No. ([0-9]*)",page.extract_text())
                if len(text):
                    rollList.append(int(text[0]))
            return rollList
    except FileNotFoundError:
        print(f"Error: File not found at {pdf_path}")
        return None
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        return None

def getResult(inputFile:str):
    rollList = extract_text_from_pdf(inputFile)
    if not rollList:
        print("Roll No. list not found")
        exit()
        
    result = []
    marksList = []
    global_headers = None

    try:
        links = driver.find_elements(By.CLASS_NAME, "MainLink")
    except:
        print("Links not found")
        exit(1)

    print("----------------------------------")
    for i, j in enumerate(links):
        print(i, " > ", j.text)
        if (i != 0) and (i % 10 == 0):
            if input("Hit enter for more any other key to start choosing: "):
                break

    link = int(input("Choose Link: "))
    try:
        link = links[link]
        sessionName = link.text.strip()
    except:
        print("Invalid link number")
        exit(1)

    link.click()

    try:
        course = driver.find_element(By.NAME, "ctl00$cph1$ddlCourse")
    except:
        print("Courses not found")
        exit(1)

    course.click()
    courses = course.find_elements(By.TAG_NAME, "option")

    print("----------------------------------")
    for i, j in enumerate(courses):
        if j.get_property("value") != "-- Select Class --":
            print(i, " > ", j.text)
        if (i != 0) and (i % 10 == 0):
            if input("Hit enter for more any other key to start choosing: "):
                break

    course_choice = int(input("Choose Course: "))
    clear_screen()
    course = courses[course_choice]

    try:
        class_element = driver.find_element(By.NAME, "ctl00$cph1$ddlClass")
    except:
        print("Classes not found")
        exit(1)

    class_element.click()
    classes = class_element.find_elements(By.TAG_NAME, "option")

    print("----------------------------------")
    for i, j in enumerate(classes):
        if j.get_property("value") != "--Select Course--":
            print(i, " > ", j.text)
        if (i != 0) and (i % 10 == 0):
            if input("Hit enter for more any other key to start choosing: "):
                break

    class_choice = int(input("Choose Class: "))
    clear_screen()
    try:
        selected_class = classes[class_choice]
        ClassName = selected_class.text.strip()
    except:
        print("Invalid class number")
        exit(1)

    selected_class.click()

    try:
        sems = driver.find_element(By.ID, "ctl00_cph1_tbLinks")
        sems = sems.find_elements(By.TAG_NAME, "a")
    except:
        print("Semester not found")
        exit(1)

    print("----------------------------------")
    for i, j in enumerate(sems):
        if j.text != "":
            print(i, " > ", j.text)
        if (i != 0) and (i % 10 == 0):
            if input("Hit enter for more any other key to start choosing: "):
                break

    sem_choice = int(input("Choose Semester: "))
    clear_screen()
    try:
        sem = sems[sem_choice]
        semNum = re.findall(r"\d+", sem.text)[0]
    except:
        print("Invalid semester number")
        exit(1)

    sem.click()

    examKey = None
    for roll in rollList:
        print(f"Checking roll no. {roll}")
        try:
            entryTable = driver.find_element(By.TAG_NAME, "table")
        except:
            print("Table not found")
            exit(1)

        try:
            sem_select = entryTable.find_element(By.ID, "ctl00_cph1_ddlSemester")
            sem_options = sem_select.find_elements(By.TAG_NAME, "option")
            for opt in sem_options:
                if opt.get_attribute("value") == semNum:
                    opt.click()
                    break
        except:
            print("Semester selection failed")
            exit(1)

        try:
            exams = entryTable.find_element(By.ID, "ctl00_cph1_ddlCollCode")
            exam_options = exams.find_elements(By.TAG_NAME, "option")
        except:
            print("Exam not found")
            exit(1)

        if roll == rollList[0]:
            print("----------------------------------")
            for i, j in enumerate(exam_options):
                print(i, " > ", j.text)
                if (i != 0) and (i % 10 == 0):
                    if input("Hit enter for more any other key to start choosing: "):
                        break
            examKey = int(input("Choose Exam Type: "))

        try:
            exam = exam_options[examKey]
            examType = exam.text.strip()
            exam.click()
        except:
            print("Invalid Exam Key")
            exit(1)

        try:
            rollno = entryTable.find_element(By.ID, "ctl00_cph1_txtRollNo")
        except:
            print(f"Roll no input not found for {roll}, skipping")
            continue

        if roll != rollList[0]:
            rollno.clear()
        rollno.send_keys(str(roll))

        try:
            submit = entryTable.find_element(By.ID, "ctl00_cph1_btnShowResult")
            submit.click()
            entryTable = driver.find_element(By.TAG_NAME, "table")
            name = driver.find_element(By.ID, "ctl00_cph1_lblCName").text.strip()
            totalScore = driver.find_element(By.ID, "ctl00_cph1_lblMarks").text.strip()
            resultLink = entryTable.find_element(By.TAG_NAME, "a")
        except:
            print(f"Result not found for roll no. {roll}, skipping")
            continue

        resultLink.click()

        try:
            marksTable = driver.find_element(By.ID, "grdResult")
            header_row = marksTable.find_element(By.TAG_NAME, "tr")
            subject_headers = [th.text.strip() for th in header_row.find_elements(By.TAG_NAME, "th")]
            data_rows = marksTable.find_elements(By.TAG_NAME, "tr")[1:]
            marks_data = []
            for row in data_rows:
                cells = row.find_elements(By.TAG_NAME, "td")
                marks_data.extend([cell.text.strip() for cell in cells])
            subject_headers_repeated = []
            for i in range(len(data_rows)):
                for header in subject_headers:
                    subject_headers_repeated.append(f"{header} {i+1}")
            if global_headers is None:
                global_headers = ["Session", "Class", "Semester", "Exam Type", "Date", "Roll", "Name", "Total Score"] + subject_headers_repeated
            current_date = datetime.date.today().strftime("%Y-%m-%d")
            row_data = [sessionName, ClassName, semNum, examType, current_date, roll, name, totalScore] + marks_data
            marksList.append(row_data)
            image = Image.open(io.BytesIO(driver.get_screenshot_as_png()))
            if image.mode != "RGB":
                image = image.convert("RGB")
            result.append(image)
        except Exception as e:
            print(f"Error processing roll {roll}: {e}")
            continue

        driver.back()

    if result:
        result[0].save(f"{sessionName}{ClassName}Result.pdf", save_all=True, append_images=result[1:])
        print(f"Saved result to {sessionName}{ClassName}Result.pdf")
        if global_headers and marksList:
            filename = f"{sessionName}{ClassName}Result.csv"
            with open(filename, "w", newline="", encoding="utf-8") as file:
                writer = csv.writer(file)
                writer.writerow(global_headers)
                writer.writerows(marksList)
            print(f"CSV created as {filename}")
if __name__ == "__main__":
    options = Options()
    options.add_argument("--headless")
    options.add_argument("--disable-gpu")
    options.add_argument("--no-sandbox")
    options.add_argument("--log-level=3")
    options.add_argument("--disable-software-rasterizer")
    options.add_argument("--disable-webgl")

    driver = webdriver.Chrome(options=options)
    try:
        driver.get("https://results.puexam.in/")
    except:
        print("Invalid URL")
        exit(1)
    path = r"D:\Downloads\bca2.pdf"
    getResult(path)
    driver.quit()