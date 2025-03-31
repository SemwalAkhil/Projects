let queryHistory = [];
let currentQueryIndex = -1;
const runBtn = document.getElementById("runBtn")
const query = document.getElementById("query")

// runBtn.addEventListener("click",runQuery(query.innerText))
// load sql scripts to form navbar when page loads  
document.addEventListener("DOMContentLoaded", () => {
    loadSQLScripts();
});
async function loadSQLScripts() {
    let response = await fetch("/get-sql-scripts");
    let data = await response.json();
    let navbar = document.getElementById("categories");
    navbar.innerHTML = "";

    for (let category in data.categories) {
        let categoryItem = document.createElement("li");
        categoryItem.innerText = category;
        categoryItem.onclick = () => {
            document.querySelectorAll("#categories li").forEach(li => li.classList.remove("selected"));
            loadScripts(category, data.categories[category])
            categoryItem.classList.add("selected");
        };
        navbar.appendChild(categoryItem);
    }
}

// load script content when script selected
async function loadScriptContent() {
    // console.log("change")
    let category = document.querySelector("#categories li.selected")?.innerText;
    let scriptName = document.getElementById("script-selector").value;
    // console.log(category)
    // console.log(scriptName)
    if (!category || !scriptName) return;

    let response = await fetch(`/get-script-content/?category=${category}&script_name=${scriptName}`);
    let data = await response.json();

    document.getElementById("query").innerText = data.content;
}

// Add event listener when the script is selected
document.getElementById("script-selector").addEventListener("click", loadScriptContent);

function loadScripts(category, scripts) {
    let selector = document.getElementById("script-selector");
    selector.innerHTML = "";

    scripts.forEach(script => {
        let option = document.createElement("option");
        option.value = script;
        option.text = script;
        selector.appendChild(option);
    });
}

// Execute query and display output on output panel
async function runQuery(query=document.getElementById("query").textContent) {
    const dbType = document.getElementById("dbType").value;
    const outputElement = document.getElementById("output");
    console.log(query)

    if (!query.trim()) {
        outputElement.textContent = "Please enter a SQL query.";
        return;
    }
    try {
        const response = await fetch("/execute-query", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ db_type: dbType, sql: query })
        });

        const result = await response.json();
        if (response.ok) {
            outputElement.innerHTML = "<pre>"
            if (result.data){
                outputElement.innerHTML += formatTable(result.columns, result.data) + "\n";
            }
            if (result.messages){
                outputElement.innerHTML += result.messages.join("\n");
            }
            outputElement.innerHTML +=  "</pre>";
        } else {
            outputElement.textContent = `Error: ${result.detail}`;
        }
    } catch (error) {
        console.log(error)
        outputElement.textContent = "Failed to execute query. Check server connection. ";
    }
}

// format the output table
function formatTable(columns, data) {
    
    let table = "<table border='1' style='width:100%; border-collapse: collapse;'>";
    
    // Extract column headers from API response
    if (columns && columns.length > 0) {
        table += "<tr>" + columns.map(col => `<th>${col}</th>`).join("") + "</tr>";
    }
    
    // Populate rows with data
    data.forEach(row => {
        table += "<tr>" + row.map(value => `<td>${value}</td>`).join("") + "</tr>";
    });
    
    table += "</table>";
    // console.log(table);
    return table;
}

// show table content by firing select query
async function showTableContent() {
    let tableName = prompt("Enter table name:");
    runQuery(`select * from ${tableName}`)
}

// show table structure by firing desc query
async function showTableMetadata() {
    let tableName = prompt("Enter table name:");
    runQuery(`desc ${tableName}`)
}
