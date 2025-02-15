from flask import Flask
import main
from flask import render_template, request, jsonify
import re

app = Flask(__name__)
driver = None
sessions = []
courses = []
classes = []
sems = []
semNum = []


@app.route("/")
def home():
    """
    Render home page
    """
    return render_template("index.html")

@app.route("/single-mode",methods=["POST","GET"])
def single():
    """
    Render single mode home page, initialize driver and get sessions dropdown
    """
    global sessions
    global driver
    driver = main.getDriver()
    driver.get("https://results.puexam.in/")
    sessions = main.getSessions(driver=driver)
    return render_template("singleMode.html",sessions=[i.text for i in sessions])

@app.route("/multi-mode",methods=["POST","GET"])
def multi():
    """
    Render multi mode home page, initialize driver and get sessions dropdown
    """
    global sessions
    global driver
    driver = main.getDriver()
    driver.get("https://results.puexam.in/")
    sessions = main.getSessions(driver=driver)
    return render_template("multiMode.html",sessions=[i.text for i in sessions])

@app.route("/update-form",methods=["POST","GET"])
def update_form():
    """
    Update form after each entry
    """
    global courses
    global sessions
    global classes
    global sems
    global semNum
    data = request.get_json()
    html =""
    # getting key name and value in json
    try:
        valType = data["name"]
        val = data["value"]
        method = 1
    except:
        # multi mode roll no.
        try:
            val1 = data["value1"]
            val2 = data["value2"]
            sem = data["sem"]
            method = 1
        # getting values in all dropdowns when submit button clicked
        except:
            # Single Mode
            try:
                rollnoS = data["rollno1"]
                rollnoE = data["rollno2"]
                exam = data["exam"]
                sem = data["sem"]
                sem = semNum[int(sem)]
                method = 0
            # Multi Mode
            except:
                rollno = data["rollno"]
                exam = data["exam"]
                sem = data["sem"]
                sem = semNum[int(sem)]
                method = 0
    # method 1 populating next input element based on current input 
    if (method == 1):
        if valType=="session":
            try:
                currSession = sessions[int(val)]
            except:
                currSession = sessions[0]
            currSession.click()
            courses = main.getCourse(driver)
            for i,j in enumerate(courses):
                html += f'<option value="{i}">{j.text}</option>'
        elif valType=="course":
            try:
                currCourse = courses[int(val)]
            except:
                currCourse = courses[0]
            currCourse.click()
            classes = main.getClass(driver)
            for i,j in enumerate(classes):
                html += f'<option value="{i}">{j.text}</option>'
        elif valType=="class":
            try:
                currClass = classes[int(val)]
            except:
                currClass = classes[0]
            currClass.click()
            sems = main.getSem(driver)
            semNum = [re.findall(r"\d+", i.text)[0] for i in sems]
            for i,j in enumerate(sems):
                html += f'<option value="{i}">{j.text}</option>'
        elif valType=="rollno":
            try:
                if (int(val1) > int(val2)):
                    val1,val2 = val2,val1
            except:
                pass
            try:
                currSem = sems[int(data["sem"])]
            except:
                currSem = sems[0]
            currSem.click()
            try:
                examType = main.getExam(driver,semNum[int(data["sem"])] or semNum[0],val)
            except:
                examType = main.getExam(driver,semNum[int(data["sem"])] or semNum[0],val1,val2)
            for i,j in enumerate(examType):
                html += f'<option value="{i}">{j.text}</option>'
        else:
            html = '<option value="" disabled selected>Select an option</option>'
    # method 0 populating result element based on inputs
    else:
        try:
            scoreDict = main.getRes(driver,sem,exam,rollno)
        except:
            scoreDict = main.getRes(driver,sem,exam,rollnoS,rollnoE)
        if len(scoreDict.keys()):
            html += """
                <div class="container mt-4">
                    <div class="table-responsive">
                        <table class="table table-striped table-bordered">
                            <thead class="thead-dark">
                                <tr>
                                    <th scope="col">Roll No.</th>
                                    <th scope="col">Name</th>
                                    <th scope="col">Link</th>
                                    <th scope="col">Total Score</th>
                                </tr>
                            </thead>
                            <tbody>
            """
            for j in scoreDict.keys():
                link = j
                score = scoreDict[j][0]
                rollno = scoreDict[j][1]
                name = scoreDict[j][2]
                html += f"""
                        <tr>
                            <td>{rollno}</td>
                            <td>{name}</td>
                            <td><a href="{link}">Show Result</a></td>
                            <td>{score}</td>
                        </tr>
                """
            html += """
                            </tbody>
                        </table>
                    </div>
                </div>
            """
        else:
            html += "<p>Result Not Found</p>"
        
    return jsonify({'html': html})