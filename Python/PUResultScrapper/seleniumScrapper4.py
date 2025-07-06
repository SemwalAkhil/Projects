# SPECIAL CASE OF SCRAPPER 3
from selenium import webdriver
from selenium.webdriver.common.by import By
import re
import os
from PIL import Image
import io
from selenium.webdriver.chrome.options import Options
import csv
import datetime

def clear_screen():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

def getResult(multiMode: bool = False):
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

    if not multiMode:
        rollStart = int(input("Enter Roll No.: "))
        rollEnd = rollStart + 1
    else:
        rollStart = int(input("Enter Start Roll No.: "))
        rollEnd = int(input("Enter End Roll No.: ")) + 1

    examKey = None
    for roll in range(rollStart, rollEnd):
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

        if roll == rollStart:
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

        if roll > rollStart:
            rollno.clear()
        rollno.send_keys(str(roll))

        try:
            submit = entryTable.find_element(By.ID, "ctl00_cph1_btnShowResult")
            submit.click()
            entryTable = driver.find_element(By.TAG_NAME, "table")
            name = driver.find_element(By.ID, "ctl00_cph1_lblCName").text.strip()
            resultLink = entryTable.find_element(By.TAG_NAME, "a")
        except:
            print(f"Result not found for roll no. {roll}, skipping")
            continue

        resultLink.click()

        try:
            fatherName = driver.find_element(By.ID, "lblFName").text
            motherName = driver.find_element(By.ID, "lblMName").text
            if global_headers is None:
                global_headers = ["Roll", "Name", "Father's Name", "Mother's Name"]
            row_data = [roll, name, fatherName, motherName]
            marksList.append(row_data)
        except Exception as e:
            print(f"Error processing roll {roll}: {e}")
            continue

        driver.back()
    
    if multiMode:
        if global_headers and marksList:
            filename = f"{sessionName}{ClassName}data.csv"
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

    getResult(bool(int(input("0> Single Mode 1> Multi Mode: "))))
    driver.quit()