const sessionInput = document.getElementById("session")
const courseInput = document.getElementById("course")
const classInput = document.getElementById("class")
const semInput = document.getElementById("sem")
const examInput = document.getElementById("exam")
const rollInput = document.getElementById("rollno")
const submitInput = document.getElementById("submit")
const resultElement = document.getElementById("result")

const updateChild = (parentEle,childEle,valueStr) => {
  parentEle.addEventListener("change",()=>{
    var selectedValue = parentEle.value;
    fetch('/update-form', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({ name: valueStr, value: selectedValue }),
  })
    .then(response => response.json())
    .then(data => {
      childEle.innerHTML = data.html;
    });
  })
}

updateChild(sessionInput,courseInput,"session");
updateChild(courseInput,classInput,"course")
updateChild(classInput,semInput,"class")
updateChild(semInput,rollInput,"sem")

rollInput.addEventListener("keydown", event =>{
  if (event.key === "Enter" && semInput.value !== ""){
    event.preventDefault()
  }
})

examInput.addEventListener("click", () =>{
  if (sessionInput.value !== "" && semInput.value !== "" && courseInput.value !== "" && classInput.value && rollInput.value !== ""){
    // event.preventDefault()
    var selectedValue1 = startRollInput.value;
    var selectedValue2 = endRollInput.value;
  fetch('/update-form', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({ name: "rollno", value1: selectedValue1, value2: selectedValue2, sem: semInput.value }),
  })
    .then(response => response.json())
    .then(data => {
      examInput.innerHTML = data.html;
    });
  }
})

submitInput.addEventListener("click", event =>{
  event.preventDefault()
  resultElement.innerHTML = "Fetching results please wait ....."
  fetch('/update-form', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({ sem: semInput.value ,rollno: rollInput.value, exam: examInput.value}),
  })
    .then(response => response.json())
    .then(data => {
      resultElement.innerHTML = data.html;
    });
})