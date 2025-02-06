const text = document.getElementById("text");
const apiUrl = "https://gist.githubusercontent.com/camperbot/5a022b72e96c4c9585c32bf6a75f62d9/raw/e3c6895ce42069f0ee7e991229064f167fe8ccdc/quotes.json"

async function loadData(){
    const response = await fetch(apiUrl);
    const data = await response.json();
    console.log(Object.values(data.quotes));
    return data.quotes;
}


const quotes = loadData();
console.log(quotes);