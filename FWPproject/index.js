// GETTING USER DETAILS
function getUser() {
    user = document.getElementById("userName1");
    pass = document.getElementById("passWord1");
    // IF USERNAME AND PASSWORD NOT EMPTY
    if (user.value !='' & pass.value != ''){
        if (user.value.indexOf(",") != -1 | user.value.indexOf("/") != -1 | pass.value.indexOf(",") != -1 | pass.value.indexOf("/") != -1){
            alert("( , ) AND ( / ) CANNOT BE USED IN USERNAMAE/PASSWORD")
            return
        }
        // IF NEW USER
        if (localStorage.getItem(user.value) == null){
            // STORING USERNAME AND PASSWORD TO LOCAL STORAGE
            localStorage.setItem(user.value,pass.value)
            // CREATING ID FROM USERNAME AND PASSWORD
            id = user.value + pass.value
            // APPENDING ID TO LOCAL STORAGE
            localStorage[user.value] += "/"+id
            // SETTING LOCATION TO MAIN PAGE
            window.location.href = "./main.html"
            // STORING USERNAME TO SESSION STORAGE
            sessionStorage.setItem(0,user.value)
        }
        // IF PASSWORD MISMATCH
        else if(pass.value != ((localStorage.getItem(user.value)).split("/"))[0]){
            alert("INCORRECT PASSWORD")
        }
        // IF OLD USER
        else{
            // GETTING ID
            id = ((localStorage.getItem(user.value)).split("/"))[1]
            // SETTING LOCATION TO MAIN PAGE
            window.location.href = "./main.html"
            // STORING USERNAME TO SESSION STORAGE
            sessionStorage.setItem(0,user.value)
        }
    }
    // IS USERNAME/PASSWORD EMPTY
    else{
        alert("USERNAME/PASSWORD CANNOT BE EMPTY")
    }
}
// ADDING TASKS
function addList() {
    taskTime = document.getElementById("taskTime1")
    taskArea = document.getElementById("taskArea1")
    // IF TASK ENTERED
    if (taskArea.value != ""){
        if (taskArea.value.indexOf(",") != -1 | taskArea.value.indexOf("/") != -1){
            alert("( , ) AND ( / ) CANNOT BE USED IN TASKS")
            return
        }
        task = (taskTime.value+","+taskArea.value)
        // STORING TASK TIME AND DESCRIPTION TO LOCAL STORAGE
        localStorage[sessionStorage[0]] += "/"+task
        // RESETING TIME AND TASK 
        taskTime.value = getTime()
        taskArea.value = ""
    // IF TASK NOT ENTERED
    } else{
        alert("PLEASE ENTER A TASK")
    }
}
// DISPLAYING LISTS
function displayList(){
    // GETTING TASKS FROM '/' SEPARATED STRING IN LOCAL STORAGE
    taskList = localStorage[sessionStorage[0]].split("/")
    // 0 -> PASSWORD 1-> ID
    taskList = taskList.slice(2)
    // ITERATING THROUGH EACH ELEMENT OF TASKLIST
    taskList.forEach(element => {
        createTask(element);
    });
}
// FUNCTIONS TO BE LOADED ON DOCUMENT LOAD
window.onload = function() {
    // CHECKING LOCATION OF WINDOW
    if (window.location.pathname === '/FWPproject/main.html') {
        displayList();
        sessionStorage.removeItem("myText")
        anchors = document.getElementsByClassName("logOut")
        for (let i = 0; i < anchors.length; i++) {
            // IF LOGOUT IS CLICKED CLEAR SESSION STORAGE REMOVING CURRENT STORAGE
            anchors[i].addEventListener('click', function() {
                sessionStorage.clear();
            });
        }
        // CHECKING TASK DEADLINE
        const intervalId = setInterval(checkTasks(), 1000);
    }
    if (window.location.pathname === '/FWPproject/profile.html') {
        sessionStorage.removeItem("myText")
        // DISPLAYING PENDING TASKS
        user = document.getElementById("userName")
        user.textContent = sessionStorage[0]
        taskList = localStorage[sessionStorage[0]].split("/")
        taskList = taskList.slice(2)
        pTask =  document.getElementById("pTasks")
        if (taskList.length > 1) {
            pTask.textContent = taskList.length + " TASKS PENDING"    
        }
        else{
            pTask.textContent = taskList.length + " TASK PENDING"
        }
        anchors = document.getElementsByClassName("logOut")
        for (let i = 0; i < anchors.length; i++) {
            // IF LOGOUT IS CLICKED CLEAR SESSION STORAGE REMOVING CURRENT STORAGE
            anchors[i].addEventListener('click', function() {
                sessionStorage.clear();
            });
        }
    }
    if (window.location.pathname === '/FWPproject/index.html') {
        sessionStorage.removeItem("myText")
        passVis = document.getElementById("passVisibility")
        pass = document.getElementById("passWord1")
        // IF PASSWORD VISIBILTY IS TOGGLED CHANGE PASSWORD VISIBILITY
        passVis.addEventListener('change',function () {
            if (pass.type === "password") {
                pass.type = "text"        
            } else{
                pass.type = "password"
            }
        })
    }
    if (window.location.pathname === '/FWPproject/list.html') {
        // SETTING DEFAULT INPUT TIME TO CURRENT SYSTEM TIME
        defaultTime = document.getElementById("taskTime1")
        defaultTime.value = getTime();
        if (sessionStorage.getItem("myText") && typeof sessionStorage.getItem("myText") === 'string'){
            const parts = sessionStorage.getItem("myText").split("/");
  document.getElementById('taskArea1').value = parts[1];
            (document.getElementById("addListBut")).addEventListener('click', function() {
            localStorage[sessionStorage[0]] = localStorage[sessionStorage[0]].replace(new RegExp("/"+(parts[0]), 'g'), '')
    sessionStorage.removeItem("myText")
            })
        }
    }
};
// DELETING ACCOUNT
function removeAcc(){
    let result = window.confirm('ARE YOU SURE YOU WANT TO DELETE ACCOUNT?');
    // CONFIRMATION
    if (result) {
        // REMOVE FROM LOCAL STORAGE
        localStorage.removeItem(sessionStorage[0])
        // CLEAR SESSION STORAGE
        sessionStorage.clear()
        alert('ACCOUNT DELETED!');
        // RETURNING TO LOGIN PAGE
        window.location.href = "./index.html"
    } else {
        alert('DELETION CANCELLED.');
    }
}
// FUNCTION TO GET CURRENT TIME
function getTime(){
    let currentTime = new Date().toLocaleTimeString('en-US', {hour12: false})
    return currentTime
}
// FUNCTION TO CALCULATE THE DIFFERENCE BETWEEN TWO TIMES IN SECONDS
function getTimeDifference(time1, time2) {
    // GET TODAY'S DATE
    const today = new Date(); 
    // CONVERT TIME STRINGS TO DATE OBJECTS
    const date1 = new Date(today.getFullYear(), today.getMonth(), today.getDate(), time1.split(':')[0], time1.split(':')[1], time1.split(':')[2]);
    const date2 = new Date(today.getFullYear(), today.getMonth(), today.getDate(), time2.split(':')[0], time2.split(':')[1], time2.split(':')[2]);
  
    // CALCULATE THE DIFFERENCE IN MILLISECONDS
    const differenceInMs = date2.getTime() - date1.getTime();
  
    // CONVERT MILLISECONDS TO MINUTES AND RETURN
    return differenceInMs / (1000*60);
  }
// FUNCTION TO CHECK IF TASK DEADLINE IS MET
function checkTasks() {
    taskList = localStorage[sessionStorage[0]].split("/")
    taskList = taskList.slice(2)
    taskList.forEach(element => {
        taskTime = document.getElementById(element+"textTime")
        taskTime.textContent = element.split(",")[0]
        containerDiv = document.getElementById(element)
        if (getTimeDifference(getTime(),taskTime.textContent) < 10) {
            containerDiv.classList.add("deadline")
        }
        if (getTimeDifference(getTime(),taskTime.textContent) < 0) {
            containerDiv.classList.add("dead")
            containerDiv.classList.remove("deadline")
        }
    })
}
// FUNCTION TO CREATE TASK LIST ON MAIN PAGE
function createTask(element){
    // CONTAINER DIV        
    let containerDiv = document.createElement('div')
    containerDiv.classList.add("task")
    containerDiv.id = element
    // TASK DIV WITH H2 TAG
    let taskDiv = document.createElement('h2')
    // TASK TIME WITH SPAN TAG
    let taskTime = document.createElement('span')
    taskTime.classList.add("taskText")
    taskTime.id = element+"textTime"
    taskTime.textContent = element.split(",")[0]
    // TASK WITH SPAN TAG
    let task = document.createElement('span')
    task.classList.add("taskText")
    task.id = element+"text"
    // GETTING TIME FROM TASKLIST ELEMENT
    task.textContent = element.split(",")[1]
    // TASKSET WITH IMAGE TAG
    let taskSet = document.createElement('img')
    taskSet.src = "./assets/setting.png"
    taskSet.classList.add("taskReset")
    taskSet.addEventListener('click', function(){
        sessionStorage["myText"] = element+"/"+task.textContent
        window.location.href = '/FWPproject/list.html'
    })
    // TASKSTAT WITH INPUT TAG 
    let taskStat = document.createElement('input')
    taskStat.classList.add("taskCheck")
    taskStat.id = element+"check"
    taskStat.type = "checkbox"
    // EVENTLISTENER TO CHECK IF THE TASKSTAT HAS BEEN CHANGED(CHECKED/UNCHECKED)
    taskStat.addEventListener('change', function() {
        // IF TASKSTAT HAS CHANGED THAN CORRESPONDINGLY CHANGE TASKTEXT AND TASKTIME
        document.getElementById(element+"text").classList.toggle("taskTextChecked")
        document.getElementById(element+"textTime").classList.toggle("taskTextChecked")
    });
    // REMOVETASK WITH BUTTON TAG
    let removeTask = document.createElement('button')
    removeTask.classList.add("taskButton")
    removeTask.id = element+"rem"
    removeTask.textContent = "X"
    // EVENTLISTENER TO CHECK IF THE REMOVETASK HAS BEEN CLICKED
    removeTask.addEventListener('click', function() {
        // REMOVE ELEMENT FROM HTML
        document.getElementById(element).remove();
        // REMOVE TASK FROM LOCAL STORAGE
        localStorage[sessionStorage[0]] = localStorage[sessionStorage[0]].replace(new RegExp("/"+element, 'g'), '');
        
    });
    // APPENDING CHILD CLASSSES TO TASKDIV
    taskDiv.appendChild(taskTime)
    taskDiv.appendChild(task)
    taskDiv.appendChild(removeTask)
    taskDiv.appendChild(taskStat)
    taskDiv.appendChild(taskSet)
    // APPENDING TASKDIV TO CONTAINERDIV
    containerDiv.appendChild(taskDiv)
    // APPENDING CONTAINERDIV TO DOCUMENT BODY
    document.body.appendChild(containerDiv)
}
// GO TO LIST HTML
function goList(){
    window.location.href = "./list.html"
}
