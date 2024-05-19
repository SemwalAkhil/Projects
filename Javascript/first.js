//SINGLE_LINE_COMMENTS
/*
    MULTILINE 
    COMMENTS
*/

// VARIABLES
/*
var num1 = 34
var num2 = 25
console.log(num1 + num2)
*/
// DATA_TYPES
    //STRING
    /*
    var str1 = "String"
    console.log(str1)
    var str2 = 'String'
    console.log(str2)
    */
    //NUMBER
    /*
    var num1 = 123
    console.log(num1)
    var num2 = 12.3
    console.log(num2)
    */
    //OBJECTS
    /*
    var marks = {
        ravi: 34,
        shubham: 78,
        akhil: 85
    }
    console.log(marks)
    */
    //BOOL
    /*
    var a = true
    console.log(a)
    var b = false
    console.log(b)
    */
    //UNDEFINED
    /*
    var c
    console.log(c)
    var d = undefined
    console.log(d)
    */
    //NULL
    /*
    var e = null
    console.log(e)
    */
    /*
    TYPES_OF_DATA_TYPES
    -> PRIMITIVE: undefined, null, number, string, boolean, symbol
    -> REFERENCE: arrays, objects
    */

    //ARRAY
    /*
    var arr = [1,'ele2',3,true,5]
    console.log(arr)
    console.log(arr[0])
    console.log(arr[1])
    console.log(arr[2])
    console.log(arr[3])
    console.log(arr[4])
    console.log(arr[5])
    */

    //OPERATORS

    //ARITHEMETIC
    //var a = 36
    //var b = 24
    /*
    console.log("The value of a + b is ", a+b)
    console.log("The value of a - b is ", a-b)
    console.log("The value of a * b is ", a*b)
    console.log("The value of a / b is ", a/b)
    */
   
    //ASSIGNMENT
    //var c = b
    /*
    console.log("The value of c is ", c)
    c += 2
    console.log("The value of c+=2 is ", c)
    c -= 2
    console.log("The value of c-=2 is ", c)
    c *= 2
    console.log("The value of c*=2 is ", c)
    c /= 2
    console.log("The value of c/=2 is ", c)
    */

    //COMPARISON
    /*
    console.log(a == b)
    console.log(a != b)
    console.log(a >= b)
    console.log(a <= b)
    console.log(a > b)
    console.log(a < b)
    console.log(b == c)
    */

    //LOGICAL
    /*
    //logical and (&&)
    console.log(true && true)
    console.log(true && false)
    console.log(false && true)
    console.log(false && false)
    //logical or (||)
    console.log(true || true)
    console.log(true || false)
    console.log(false || true)
    console.log(false || false)
    //logical not (!)
    console.log(!true)
    console.log(!false)
    */

    //FUNCTION
    function avg(a,b){
        return (a+b)/2
    }

    //INVOKING_FUNCTION
    /*
    c1 = avg(4,6)
    c2 = avg(14,16)
    console.log(c1)
    console.log(c2)
    */
    //on chrome console if output is blue then it is number type else if it is black in color then it is string

    //DECISION_CONTROL
    /*
    var age = 18;
    //if
    if (age > 18){
        console.log("You can drive")
    }
    //else
    else{
        console.log("You can't drive")
    }
    //if else ladder
    if (age > 18){
        console.log("You can go")
    }
    else if (age == 18){
        console.log("You can go with an adult")
    }
    else{
        console.log("You can't go")
    }
    console.log("End of ladder")
    */

    //LOOPS
    // var arr = [1,2,3,4,5,6,7]
    // console.log(arr)
    //FOR
    /*
    for (var i = 0; i < arr.length; i++) {
        console.log(arr[i]);
    }
    */
        //ALTERNATIVE_METHOD
        /*
        arr.forEach(
            function(element){
                console.log(element)
            }
        )
        */
    
    /*
    let j = 0 
    console.log(j)
    //let -> a block level scope and is used instead of var in modern javascript
    const a = 0
    //const -> value can't be assigned to constant 
    a++
    console.log(a)
    */

    //WHILE
    /*
    let j = 0
    while (j < arr.length) {
        console.log(arr[j])
        j++
    }
    */

    //DO_WHILE
    /*
    let j = 7
    do{
        console.log(arr[j])
        j++
    }while(j < arr.length)
    */

    //BREAK_AND_CONTINUE
    /*
    for (let i = 0; i < 7; i++) {
        if (i == 2) {
            continue
        }
        if (i == 5) {
            break
        }
        console.log(i);
    }
    */

    /*
    let myArr = ["Fan",'Camera',34,null,true]

    // ARRAY_METHODS
    console.log("MyArr",myArr)
    myArr.pop()
    // REMOVES_FROM_END
    console.log("Pop",myArr)
    myArr.push("akhil")
    // ADDS_TO_END
    console.log("Push",myArr)
    myArr.shift()
    //REMOVES_FROM_FRONT
    console.log("Shift",myArr)
    myArr.unshift("Akhil")
    // ADD_TO_FRONT
    console.log("Unshift",myArr)
    console.log("Unshift length",myArr.unshift(1))
    //RETURNS_LENGTH_AFTER_ADDING_TO_FRONT
    console.log(myArr.toString())
    // CONVERTS_ARRAY_TO_STRING
    d = [1,222,12,43,32,552,23,41,0]
    // NOT_RELEVANT_FOR_NUMBERS_AS_IT_STORES_AFTER_CONVERTING_TO_STRING
    d.sort()
    console.log(d)
    e = ['a','c','e','m','b','d','f']
    e.sort()
    console.log(e)
    */

    /*
    let myString = "Hello world this is me"
    
    // STRING_METHODS
    console.log(myString.length)
    console.log(myString.indexOf("is"))
    console.log(myString.lastIndexOf("is"))
    console.log(myString.slice(1,4))
    // REPLACE_NOT_PERMANENT
    console.log(myString.replace("me","Akhil"))
    console.log(myString.replace("is","at"))
    // REPLACE_AT_ORIGINAL_LOCATION
    myString = myString.replace("me","Akhil")
    console.log(myString)
    */

    /*
    let myDate = new Date()
    console.log(myDate)

    // DATE_METHODS
    console.log(myDate.getTime()) 
    //TIME_SINCE_1ST_JAN_1970_IN_MILLISECONDS
    console.log(myDate.getFullYear())
    // GETS_YEAR_USING_LOCAL_TIME
    console.log(myDate.getDay())
    // GETS_DAY_USING_LOCAL_TIME
    //  M T W T F S S
    //  1 2 3 4 5 6 7
    console.log(myDate.getMinutes())
    // GETS_MINUTES_USING_LOCAL_TIME
    console.log(myDate.getHours())
    // GETS_HOURS_USING_LOCAL_TIME
    */
   
    // DOM -> DOCUMENT_OBJECT_MODEL

    // DOM_MANIPULATION

    /*
    let elem = document.getElementById("click")
    // console.log(elem)

    let elemClass = document.getElementsByClassName("container")
    // console.log(elemClass)

    // elemClass[0].style.background = "yellow"
    // -> ADDS_YELLOW_BACKGROUND_TO_ELEM_CLASS_0TH_ELEMENT

    elemClass[0].classList.add("bg-primary")
    // -> ADDS_BG_PRIMARY_CLASS_TO_0TH_ELEMENT_OF_CLASS   
    
    elemClass[0].classList.remove("bg-primary")
    // -> REMOVES_BG_PRIMARY_CLASS_TO_0TH_ELEMENT_OF_CLASS
    
    console.log(elem.innerHTML)
    console.log(elem.innerText)

    console.log(elemClass[1].innerHTML)
    console.log(elemClass[1].innerText)

    elemTag = document.getElementsByTagName('div')
    //console.log(elemTag)

    createdElement = document.createElement('p')
    createdElement.innerText = "Lorem ipsum dolor sit amet consectetur adipisicing elit. Fuga iste necessitatibus voluptatem molestias, laborum illo perferendis consequuntur sapiente eaque ex ipsa unde ab qui possimus blanditiis! Ducimus nisi, obcaecati consequuntur, dolorem soluta quo placeat fugiat veniam animi officiis eius rerum nulla necessitatibus cum ullam. Cumque molestiae mollitia quaerat veritatis aspernatur ab, vitae incidunt vel maxime fuga esse modi. Accusamus voluptates repellendus voluptate quas quod qui laboriosam beatae incidunt quae culpa quia iure, sint soluta deleniti enim. Quasi et odio nobis nulla provident amet modi aut ipsam fugiat quaerat ipsa quisquam perferendis, vitae eum, labore dolore pariatur laboriosam, cupiditate illo porro."

    elemTag[1].appendChild(createdElement)

    createdElement2 = document.createElement('p')
    createdElement2.innerText = "Plain Replaced Text"

    // elemTag[1].replaceChild(createdElement2,createdElement)
    // replaces createdElement2 by createdElement

    // elemTag[1].removeChild(createdElement)
    // removes created element
    */

    // SELECTING_USING_QUERY
    /*
    sel = document.querySelector('.container')
    // uses css selector to select element
    console.log(sel)
    sel = document.querySelectorAll('.container')
    // uses css selector to select node element list
    console.log(sel)
    */

    function clicked(){
        console.log('Button was clicked')
    }

    // EVENTS_IN_JAVASCRIPT
    /*
    window.onload = function(){
        console.log("Document Loaded")
    }
    */
    // LOADS_WHEN_WINDOW_WAS_LOADED
    /*
//  < id >                 <event>
    click.addEventListener('click',function () {
        console.log("Clicked")
    })
    click.addEventListener('mouseover',function () {
        console.log("Hovering")
    })
    click.addEventListener('mouseout',function () {
        console.log("Not Hovering")
    })
    text.addEventListener('click',function () {
        console.log("Clicked Text")
    })
    text.addEventListener('mouseup',function () {
        console.log("Click removed from Text")
    })
    text.addEventListener('mousedown',function () {
        console.log("Click held on Text")
    })
    */

    // AFFECTING_INNER_HTML
    /*
    let prevHtml = document.querySelector('#click').innerHTML
    click.addEventListener('mouseover',function(){
        document.querySelector('#click').innerHTML = "<b> Hovering </b>"
    })

    click.addEventListener('mouseout',function(){
        document.querySelector('#click').innerHTML = prevHtml
    })
    */

    // ARROW_FUNCTION
    function sum(a,b){
        return a+b
    }
    // ALT_METHOD_FOR_ABOVE_FUNCTION
    summ = (a,b) =>{
        return a+b
    }

    // SET_TIMEOUT/SET_INTERVAL
    logFunc = ()=>{
        alert("log")
    }

    //        <function> <time(ms)>
    // setTimeout( logFunc , 2000 )
    // CALLS_FUNCTION_AFTER_DELAY_OF_2000_MILLISECONDS

    // setInterval( logFunc , 5000 )
    // CALLS_FUNCTION_REPETITIVELY_AFTER_DELAY_OF_5000_MILLISECONDS

    // WE_STOP_SET_TIMEOUT_AND_SET_INTERVAL_BY
        // sT = setTimeout(logFunc, 2000)
        //sI = setInterval(logFunc, 2000)

        // RUNNING_CLEAR_TIMEOUT_S_T_OR_CLEAR_INTERVAL_S_I

    // LOCAL_STORAGE
    /*
//->    Helps to store data in user's computer
            localStorage.setItem("hey","hello")
            console.log(localStorage)
            localStorage.getItem("hey")
            // localStorage.removeItem('hey')
            // localStorage.clear()
    */

    // JSON (JavaScript Object Notation)
    /*
        JSON_IS_OFTEN_USED_TO_TRANSMIT_DATA_BETWEEN_A_SERVER_AND_A_WEB_APPLICATION_AS_IT_IS_LANGUAGE_INDEPENDENT_AND_CAN_BE_PARSED_BY_VARIOUS_PROGRAMMING_LANGUAGES
    */
    /*
    obj = {name: "akhil", length:1, this: 'tha"t"', it: "i's'"}
    jso = JSON.stringify(obj)
    // CONVERTS_OBJECT_TO_JSON_STRING
    console.log(jso)
    // WE_CAN_CONFIRM_CONVERSION_BY typeof(jso)
    // JSON_SUPPORTS_ONLY_DOUBLE_QUOTE
    // BACK_TICKS(`) CAN_ALSO_BE_USED_TO_DECLARE_STRING_THEY_ARE_ALSO_CALLED_TEMPLATE_LITERALS
    parsed = JSON.parse(`{"name":"ak", "length":1, "a":{"this":"that\\"t"}}`)
    console.log(parsed);
    */

    // TEMPLATE_LITERALS (`)
    /*
    a = 34
    console.log(`this is my ${a}`)
    */
    