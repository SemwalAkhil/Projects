keys = document.getElementsByClassName("keys")
text = 0
let bracket = []

function update(text){
    display = document.getElementsByClassName("display")
    display[0].innerHTML = text
}
function clear(array) {
    len = array.length
    for (let index = 0; index < len; index++) {
        array.pop()
    }
}

/*
for (const key of keys)(
    (key).addEventListener('click',function(){
        if (text == "0"){
            if ((key.id in [1,2,3,4,5,6,7,8,9,0]) || (key.id == '(') || (key.id == '√(') || (key.id == '1/(')){
                text = key.id    
                if ((key.id == '(') || (key.id == '√(') || (key.id == '√(')){
                    bracket.push('(')
                }
            }
            else if (key.id == '.'){
                text += key.id
            }
        }
        else if(key.id == 'C'){
            text = '0'
            clear(bracket)
        }
        else if(key.id == 'B'){
            if (text.slice(text.length-2,text.length-1) == '(') {
                bracket.pop()
            } 
            else if (text.slice(text.length-2,text.length-1) == ')') {
                bracket.push('(')    
            }
            if (text.length > 1){
                text = text.slice(0,text.length-1)
            } else { text = '0' }
        }
        else if (key.id == '.' ){
            if (text.slice(text.length-1,text.length) != '.'){
                text += key.id
            }
        }
        else if (key.id == '(') {
            bracket.push(key.id)
            text += key.id 
        }
        else if (key.id == ')'){
            if ((bracket.length > 0)) {
                bracket.pop()
                text += key.id    
            }
        }
        else if (key.id == '√(' || (key.id == '1/(')) {
            bracket.push('(','(')
            text += '(' + key.id
        }
        else {
            text += key.id
        }
        console.log(bracket)
        update(text)
    }) 
);
*/
for (const key of keys)(
    key.addEventListener('click',function(){
        if ('special' !== key.classList[2]){
            if (key.id == 'B'){
                if (text.length > 1){
                    text = text.slice(0,text.length-1)
                } else {
                    text = 0
                }
            }
            else if (text == 0){
                text = key.id
            }  
            else {
                text += key.id
            }
            update(text)
        } 
    })
);
