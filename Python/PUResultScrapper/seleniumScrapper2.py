# SELENIUM SCRAPPER II
from selenium import webdriver # driver to open browser
from selenium.webdriver.common.by import By
import re
import os
from PIL import Image # for image to pdf
import io # for byte conversion
from selenium.webdriver.chrome.options import Options
import csv

def clear_screen():
    # Clear command based on the operating system
    if os.name == 'nt':  # For Windows
        os.system('cls')
    else:  # For Linux/Unix/MacOS
        os.system('clear')

def getResult(multiMode:bool = False):
    
    result = []
    if multiMode:
        marksList = []

    # GETTING MAIN LINKS
    try:
        links = driver.find_elements(By.CLASS_NAME,"MainLink")
    except:
        print("Links not found")
        exit(1)

    print("----------------------------------")
    for i,j in enumerate(links):
        print(i," > ",j.text)
        if ((i != 0) and ((i % 10) == 0)):
            try:
                if (int(input("Hit enter for more any other key to start choosing :"))):
                    break
            except:
                pass

    link = int(input("Choose Link : "))
    try:
        link = links[link]
        sessionName = link.text.strip()
    except:
        print("Invalid link number")
        exit(1)

    link.click()

    # CHOOSING COURSE
    try:
        course = driver.find_element(By.NAME,"ctl00$cph1$ddlCourse")
    except:
        print("Courses not found")
        exit(1)

    course.click()

    try:
        courses = course.find_elements(By.TAG_NAME,"option")
    except:
        print("Courses not found")
        exit(1)

    print("----------------------------------")
    for i,j in enumerate(courses):
        if(j.get_property("value") != "-- Select Class --"):
            print(i," > ",j.text)
        if ((i != 0) and ((i % 10) == 0)):
            try:
                if (int(input("Hit enter for more any other key to start choosing :"))):
                    break
            except:
                pass

    course = int(input("Choose Course : "))
    clear_screen()
    course = courses[course]

    # CHOOSING CLASS
    try:
        Class = driver.find_element(By.NAME,"ctl00$cph1$ddlClass")
    except:
        print("Classes not found")
        exit(1)

    Class.click()
    
    try:
        classes = Class.find_elements(By.TAG_NAME,"option")
    except:
        print("Classes not found")
        exit(1)

    print("----------------------------------")
    for i,j in enumerate(classes):
        if(j.get_property("value") != "--Select Course--"):
            print(i," > ",j.text)
        if ((i != 0) and ((i % 10) == 0)):
            try:
                if (int(input("Hit enter for more any other key to start choosing :"))):
                    break
            except:
                pass

    Class = int(input("Choose Class : "))
    clear_screen()

    try:
        Class = classes[Class]
        ClassName = Class.text.strip()
    except:
        print("Invalid class number found")
        exit(1)

    Class.click()

    # CHOOSING SEMESTER
    try:
        sems = driver.find_element(By.ID,"ctl00_cph1_tbLinks")
        sems = sems.find_elements(By.TAG_NAME,"a")
    except:
        print("Semester not found")
        exit(1)

    print("----------------------------------")
    for i,j in enumerate(sems):
        if (j.text != ""):
            print(i," > ",j.text)
        if ((i != 0) and ((i % 10) == 0)):
            try:
                if (int(input("Hit enter for more any other key to start choosing :"))):
                    break
            except:
                pass
        
    sem = int(input("Choose Semester : "))
    clear_screen()
    
    try:
        sem = sems[sem]
    except:
        print("Invalid semester number")
        exit(1)

    semNum = re.findall("[0-9]",sem.text)[0]
    sem.click()

    if (not multiMode):
        rollStart = int(input("Enter Roll No. : "))
        rollEnd = rollStart + 1
    else:
        rollStart = int(input("Enter Start Roll No. : "))
        rollEnd = int(input("Enter End Roll No. : "))

    for roll in range(rollStart,rollEnd):
        print("checking roll no. {}".format(roll))
        # FINAL DATA TABLE
        try:
            entryTable = driver.find_element(By.TAG_NAME,"table")
        except:
            print("Table not found")
            exit(1)

        # SEMESTER
        try:
            sems = entryTable.find_element(By.ID,"ctl00_cph1_ddlSemester")
            sems = sems.find_elements(By.TAG_NAME,"option")
        except:
            print("Semester not found")
            exit(1)

        for i,j in enumerate(sems):
            if(j.get_property("value") == str(semNum)):
                j.click()

        # EXAM
        try:
            exams = entryTable.find_element(By.ID,"ctl00_cph1_ddlCollCode")
            exams = exams.find_elements(By.TAG_NAME,"option")
        except:
            print("Exam not found")
            exit(1)

        if (roll <= rollStart):
            print("----------------------------------")
            for i,j in enumerate(exams):
                print(i," > ",j.text)
            if ((i != 0) and ((i % 10) == 0)):
                try:
                    if (int(input("Hit enter for more any other key to start choosing :"))):
                        break
                except:
                    pass
        
            examKey = int(input("Choose Exam Type : "))
        try:
            exam = exams[examKey]
        except:
            print("Invalid Exam Key")
            exit(1)

        exam.click()

        # ROLL NO.
        try:
            rollno = entryTable.find_element(By.ID,"ctl00_cph1_txtRollNo")
        except:
            print("Result not found for roll no. {} skipping to next".format(roll))
            continue

        if (roll > rollStart):
            rollno.clear()
    
        rollno.send_keys(str(roll))
        try:
            submit = entryTable.find_element(By.ID,"ctl00_cph1_btnShowResult")
            submit.click()
            entryTable = driver.find_element(By.TAG_NAME,"table")
            name = driver.find_element(By.ID,"ctl00_cph1_lblCName").text.strip()
            totalScore = driver.find_element(By.ID,"ctl00_cph1_lblMarks").text.strip()
            resultLink = entryTable.find_element(By.TAG_NAME,"a")
        except:
            print("Result not found for roll no. {} skipping to next".format(roll))
            continue
        resultLink.click()
        
        try:
            marksTable = driver.find_element(By.ID,"grdResult")
            subjectMarks = marksTable.find_elements(By.TAG_NAME,"tr")
            marksRow = [marks.text.strip() for subjects in subjectMarks for marks in subjects.find_elements(By.TAG_NAME,"td")]

            # TAKING SCREENSHOT
            image = Image.open(io.BytesIO(driver.get_screenshot_as_png()))
            if image.mode != "RGB":
                image.convert("RGB")
            result.append(image)
            marksList.append([roll,name,totalScore]+marksRow)
        except:
            print("Result not found for roll no. {} skipping to next".format(roll))
        # GO TO LAST VISITED PAGE
        driver.back()
        # break
    # save to pdf
    if multiMode:
        result[0].save(f"{sessionName}{ClassName}Result.pdf",save_all=True,append_images=result[1:])
        print(f"Saved result to {sessionName}{ClassName}Result.pdf")
        with open(f"{sessionName}{ClassName}Result.csv","a",newline="") as file:
            writer = csv.writer(file)
            writer.writerows(marksList)
        print(f"CSV created as {sessionName}{ClassName}Result.csv")
    else:
        result[0].save(f"{sessionName}{roll}.pdf")
        print(f"Saved result to {sessionName}{roll}.pdf")

if __name__ == "__main__":
    options = Options()
    options.add_argument("--headless")  # Run browser in headless mode
    options.add_argument("--disable-gpu")  # Disable GPU usage (optional, for compatibility)
    options.add_argument("--no-sandbox")  # Disable sandbox (useful in some environments)
    options.add_argument("--log-level=3")  # Reduce logging output
    options.add_argument("--disable-software-rasterizer")  # Prevents software rendering
    options.add_argument("--disable-webgl")  # Disables WebGL rendering

    # DRIVER INITIALISATION
    driver = webdriver.Chrome(options=options)
    try:
        driver.get(r"https://results.puexam.in/")
    except:
        print("Invalid URL")
        exit(1)

    getResult(bool(int(input("0> Single Mode 1> Multi Mode : "))))

    driver.quit()