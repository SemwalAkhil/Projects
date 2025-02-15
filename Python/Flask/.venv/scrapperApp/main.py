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

def getDriver(headless:bool=True,disableGPU:bool=True,noSandbox:bool=True,logLevel:int=3,disableSoftwareRasterizer:bool=True,disableWebgl:bool=True):
    options = Options()
    if headless:
        options.add_argument("--headless")
    if disableGPU:
        options.add_argument("--disable-gpu")
    if noSandbox:
        options.add_argument("--no-sandbox")
    options.add_argument(f"--log-level={logLevel}")
    if disableSoftwareRasterizer:
        options.add_argument("--disable-software-rasterizer")
    if disableWebgl:
        options.add_argument("--disable-webgl")
    driver = webdriver.Chrome(options=options)
    return driver

def clear_screen():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

def getSessions(driver):
    try:
        links = driver.find_elements(By.CLASS_NAME, "MainLink")
    except:
        print("Links not found")
    return links or []

def getCourse(driver):
    try:
        course = driver.find_element(By.NAME, "ctl00$cph1$ddlCourse")
        course.click()
        courses = course.find_elements(By.TAG_NAME, "option")
    except:
        print("Courses not found")
    return courses or []

def getClass(driver):
    try:
        class_element = driver.find_element(By.NAME, "ctl00$cph1$ddlClass")
        class_element.click()
        classes = class_element.find_elements(By.TAG_NAME, "option")
    except:
        print("Classes not found")
    return classes or []

def getSem(driver):
    try:
        sems = driver.find_element(By.ID, "ctl00_cph1_tbLinks")
        sems = sems.find_elements(By.TAG_NAME, "a")
    except:
        print("Semester not found")
        return []
    return sems

def getExam(driver,semNum:int,rollStart:int,rollEnd = None):
    if not rollEnd:
        print(f"Checking roll no. {rollStart}")
        try:
            entryTable = driver.find_element(By.TAG_NAME, "table")
        except:
            print("Table not found")
        try:
            sem_select = entryTable.find_element(By.ID, "ctl00_cph1_ddlSemester")
            sem_options = sem_select.find_elements(By.TAG_NAME, "option")
            for opt in sem_options:
                if opt.get_attribute("value") == semNum:
                    opt.click()
                    break
        except:
            print("Semester selection failed")
        try:
            exams = entryTable.find_element(By.ID, "ctl00_cph1_ddlCollCode")
            exam_options = exams.find_elements(By.TAG_NAME, "option")
        except:
            print("Exam not found")
        return exam_options or []
    else:
        for roll in range(int(rollStart),int(rollEnd)+1):
            print(f"Checking roll no. {roll}")
            try:
                entryTable = driver.find_element(By.TAG_NAME, "table")
            except:
                continue
            try:
                sem_select = entryTable.find_element(By.ID, "ctl00_cph1_ddlSemester")
                sem_options = sem_select.find_elements(By.TAG_NAME, "option")
                for opt in sem_options:
                    if opt.get_attribute("value") == semNum:
                        opt.click()
                        break
            except:
                continue
            try:
                exams = entryTable.find_element(By.ID, "ctl00_cph1_ddlCollCode")
                exam_options = exams.find_elements(By.TAG_NAME, "option")
            except:
                continue
            break
        return exam_options or []

def getRes(driver,sem:int,examKey:int,rollStart:int,rollEnd = None)->dict:
    data = {}
    if not rollEnd:
        try:
            entryTable = driver.find_element(By.TAG_NAME, "table")
            sem_select = entryTable.find_element(By.ID, "ctl00_cph1_ddlSemester")
            sem_options = sem_select.find_elements(By.TAG_NAME, "option")
            for opt in sem_options:
                if opt.get_attribute("value") == sem:
                    opt.click()
                    break
            exams = entryTable.find_element(By.ID, "ctl00_cph1_ddlCollCode")
            exam_options = exams.find_elements(By.TAG_NAME, "option")
        except:
            print("Table not found")
            return data
        try:
            exam = exam_options[int(examKey)]
            exam.click()
        except:
            print("Invalid Exam Key")
            return data
        try:
            rollno = entryTable.find_element(By.ID, "ctl00_cph1_txtRollNo")
        except:
            print(f"Roll no input not found skipping")
            return data
        rollno.send_keys(str(rollStart))
        try:
            submit = entryTable.find_element(By.ID, "ctl00_cph1_btnShowResult")
            submit.click()
            entryTable = driver.find_element(By.TAG_NAME, "table")
            name = driver.find_element(By.ID, "ctl00_cph1_lblCName").text.strip()
            totalScore = driver.find_element(By.ID, "ctl00_cph1_lblMarks").text.strip()
            tempLink = entryTable.find_element(By.TAG_NAME, "a")
            tempLink.click()
            resultLink = driver.current_url
            data[resultLink] = (totalScore,rollno,name)
        except:
            print(f"Result not found for roll no. {rollStart}, skipping")
            return data
        return data
    else:
        for roll in range(int(rollStart),int(rollEnd)+1):
            try:
                entryTable = driver.find_element(By.TAG_NAME, "table")
                sem_select = entryTable.find_element(By.ID, "ctl00_cph1_ddlSemester")
                sem_options = sem_select.find_elements(By.TAG_NAME, "option")
                for opt in sem_options:
                    # print(opt.get_attribute("value"),sem)
                    if opt.get_attribute("value") == sem:
                        opt.click()
                        break
                exams = entryTable.find_element(By.ID, "ctl00_cph1_ddlCollCode")
                exam_options = exams.find_elements(By.TAG_NAME, "option")
            except:
                print("Table not found")
                continue
            try:
                exam = exam_options[int(examKey)]
                exam.click()
            except:
                print("Invalid Exam Key")
                continue
            try:
                rollno = entryTable.find_element(By.ID, "ctl00_cph1_txtRollNo")
            except:
                print(f"Roll no input not found for skipping")
                continue
            rollno.clear()
            rollno.send_keys(str(roll))
            try:
                submit = entryTable.find_element(By.ID, "ctl00_cph1_btnShowResult")
                submit.click()
                entryTable = driver.find_element(By.TAG_NAME, "table")
                name = driver.find_element(By.ID, "ctl00_cph1_lblCName").text.strip()
                totalScore = driver.find_element(By.ID, "ctl00_cph1_lblMarks").text.strip()
                tempLink = entryTable.find_element(By.TAG_NAME, "a")
                tempLink.click()
                resultLink = driver.current_url
                data[resultLink] = (totalScore,roll,name)
                driver.back()
            except:
                print(f"Result not found for roll no. {roll}, skipping")
                continue
        return data

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
            # totalScore = driver.find_element(By.ID, "ctl00_cph1_lblMarks").text.strip()
            resultLink = entryTable.find_element(By.TAG_NAME, "a")
        except:
            print(f"Result not found for roll no. {roll}, skipping")
            continue

        resultLink.click()

        try:
            # marksTable = driver.find_element(By.ID, "grdResult")
            # header_row = marksTable.find_element(By.TAG_NAME, "tr")
            # subject_headers = [th.text.strip() for th in header_row.find_elements(By.TAG_NAME, "th")]
            # data_rows = marksTable.find_elements(By.TAG_NAME, "tr")[1:]
            # marks_data = []
            # for row in data_rows:
            #     cells = row.find_elements(By.TAG_NAME, "td")
            #     marks_data.extend([cell.text.strip() for cell in cells])
            # subject_headers_repeated = []
            # for i in range(len(data_rows)):
            #     for header in subject_headers:
            #         subject_headers_repeated.append(f"{header} {i+1}")
            fatherName = driver.find_element(By.ID, "lblFName").text
            motherName = driver.find_element(By.ID, "lblMName").text
            if global_headers is None:
                global_headers = ["Roll", "Name", "Father's Name", "Mother's Name"]
            # current_date = datetime.date.today().strftime("%Y-%m-%d")
            row_data = [roll, name, fatherName, motherName]
            marksList.append(row_data)
            # image = Image.open(io.BytesIO(driver.get_screenshot_as_png()))
            # if image.mode != "RGB":
            #     image = image.convert("RGB")
            # result.append(image)
        except Exception as e:
            print(f"Error processing roll {roll}: {e}")
            continue

        driver.back()
    
    if multiMode:
        # result[0].save(f"{sessionName}{ClassName}Result.pdf", save_all=True, append_images=result[1:])
        # print(f"Saved result to {sessionName}{ClassName}Result.pdf")
        if global_headers and marksList:
            filename = f"{sessionName}{ClassName}data.csv"
            with open(filename, "w", newline="", encoding="utf-8") as file:
                writer = csv.writer(file)
                writer.writerow(global_headers)
                writer.writerows(marksList)
            print(f"CSV created as {filename}")

if __name__ == "__main__":
    driver = getDriver()
    try:
        driver.get("https://results.puexam.in/")
    except:
        print("Invalid URL")
        exit(1)

    getResult(bool(int(input("0> Single Mode 1> Multi Mode: "))))
    driver.quit()