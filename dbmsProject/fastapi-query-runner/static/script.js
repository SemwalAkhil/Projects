// Global variables to track query history
let queryHistory = [];
let currentQueryIndex = -1;

// Main initialization when document loads
document.addEventListener("DOMContentLoaded", () => {
    loadSQLScripts();
    setupEventListeners();
    setupMobileNavigation();
});

// Function to handle mobile navigation toggle
function setupMobileNavigation() {
    const menuToggle = document.getElementById("menuToggle");
    const navbar = document.getElementById("navbar");
    
    if (menuToggle) {
        menuToggle.addEventListener("click", () => {
            navbar.classList.toggle("active");
            // Change icon based on menu state
            const icon = menuToggle.querySelector("i");
            if (navbar.classList.contains("active")) {
                icon.className = "fas fa-times";
                
            } else {
                icon.className = "fas fa-bars";
            }
        });
    }
    
    // Close menu when a category is selected on mobile
    const categories = document.getElementById("categories");
    if (categories) {
        categories.addEventListener("click", (e) => {
            if (window.innerWidth <= 992 && e.target.tagName === "LI") {
                navbar.classList.remove("active");
                const icon = menuToggle.querySelector("i");
                icon.className = "fas fa-bars";
            }
        });
    }
}

// Function to highlight code
function highlightCode() {
    // Check if Prism is loaded
    if (window.Prism) {
        // Highlight all SQL elements
        Prism.highlightElement(document.getElementById('query'));
    }
}

/**
 * Set up all event listeners for the application
 */
function setupEventListeners() {
    // Script selector change event
    document.getElementById("script-selector").addEventListener("change", loadScriptContent);
    
    // Add keyboard shortcuts for the query editor
    document.getElementById("query").addEventListener("keydown", function(e) {
        // Execute query with Ctrl+Enter
        if (e.ctrlKey && e.key === "Enter") {
            runQuery();
            e.preventDefault();
        }
    });
    
    // Add resize event listener for responsive adjustments
    window.addEventListener("resize", handleResize);
}

/**
 * Handle window resize events
 */
function handleResize() {
    const navbar = document.getElementById("navbar");
    const menuToggle = document.getElementById("menuToggle");
    
    // Reset navbar styles when switching between mobile and desktop views
    if (window.innerWidth > 992) {
        navbar.classList.remove("active");
        if (menuToggle && menuToggle.querySelector("i")) {
            menuToggle.querySelector("i").className = "fas fa-bars";
        }
    }
}

/**
 * Load SQL scripts and populate the sidebar navigation
 */
async function loadSQLScripts() {
    try {
        const response = await fetch("/get-sql-scripts");
        const data = await response.json();
        const navbar = document.getElementById("categories");
        navbar.innerHTML = "";

        // Create category items in the sidebar
        for (let category in data.categories) {
            let categoryItem = document.createElement("li");
            categoryItem.innerHTML = `<i class="fas fa-folder"></i> ${category}`;
            categoryItem.onclick = () => {
                document.querySelectorAll("#categories li").forEach(li => li.classList.remove("selected"));
                categoryItem.classList.add("selected");
                loadScripts(category, data.categories[category]);
            };
            navbar.appendChild(categoryItem);
        }
        
        // Show status message in output area
        document.getElementById("output").textContent = "Ready. Select a script category and file to begin.";
    } catch (error) {
        console.error("Error loading SQL scripts:", error);
        document.getElementById("output").textContent = "Failed to load SQL scripts. Please check server connection.";
    }
}

/**
 * Load the content of the selected script
 */
async function loadScriptContent() {
    const category = document.querySelector("#categories li.selected")?.innerText.replace(/^\s*\S+\s+/, '').trim(); // Remove icon
    const scriptName = document.getElementById("script-selector").value;
    console.log(category,scriptName);
    if (!category || !scriptName) return;

    try {
        const response = await fetch(`/get-script-content/?category=${encodeURIComponent(category)}&script_name=${encodeURIComponent(scriptName)}`);
        const data = await response.json();

        document.getElementById("query").textContent = data.content;

        // Highlight the code after setting content
        highlightCode();

        // Add to query history
        queryHistory.push(data.content);
        currentQueryIndex = queryHistory.length - 1;
    } catch (error) {
        console.error("Error loading script content:", error);
        document.getElementById("output").textContent = "Failed to load script content.";
    }
}

/**
 * Populate script selector dropdown with scripts from the selected category
 * @param {string} category - The selected category
 * @param {Array} scripts - List of scripts in the category
 */
function loadScripts(category, scripts) {
    const selector = document.getElementById("script-selector");
    selector.innerHTML = "";

    scripts.forEach(script => {
        const option = document.createElement("option");
        option.value = script;
        option.text = script;
        selector.appendChild(option);
    });
    
    // Load the first script content if available
    loadScriptContent();
    
}

/**
 * Execute the current SQL query
 * @param {string} query - SQL query to execute (optional, defaults to query editor content)
 */
async function runQuery(query = document.getElementById("query").textContent) {
    const dbType = document.getElementById("dbType").value;
    const outputElement = document.getElementById("output");
    
    if (!query.trim()) {
        outputElement.textContent = "Please enter a SQL query.";
        return;
    }
    
    // Show loading indicator
    outputElement.innerHTML = "<div style='text-align:center; padding: 20px;'><i class='fas fa-spinner fa-spin'></i> Executing query...</div>";
    
    try {
        const response = await fetch("/execute-query", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ db_type: dbType, sql: query })
        });

        const result = await response.json();
        
        if (response.ok) {
            outputElement.innerHTML = "";
            
            // Display table results if available
            if (result.data && result.data.length > 0) {
                outputElement.innerHTML += formatTable(result);
                outputElement.innerHTML += `<div class="query-info">${result.data.length} rows returned</div>`;
            } else if (result.data) {
                outputElement.innerHTML += "<div class='no-results'>Query executed successfully. No rows returned.</div>";
            }
            
            // Display query messages if available
            if (result.messages && result.messages.length > 0) {
                outputElement.innerHTML += "<div class='query-messages'>" + result.messages.join("<br>") + "</div>";
            }
        } else {
            outputElement.innerHTML = `<div class="error-message"><i class="fas fa-exclamation-triangle"></i> Error: ${result.detail}</div>`;
        }
    } catch (error) {
        console.error("Query execution error:", error);
        outputElement.innerHTML = `<div class="error-message"><i class="fas fa-exclamation-triangle"></i> Failed to execute query. Check server connection.</div>`;
    }
}

/**
 * Format query results as an HTML table
 * @param {Array} columns - Column names
 * @param {Array} data - Table data rows
 * @returns {string} HTML table
 */
function formatTable(result) {
    console.log("Format table function");
    console.log("Creating table : ", result);
    if (!result || !result.data || result.data.length === 0) return "";
    
    const { columns, data } = result;
    let table = "<div class='table-responsive'><table class='results-table'>";

    // Table header
    if (columns && columns.length > 0) {
        table += "<thead><tr>" + columns.map(col => `<th>${escapeHTML(col)}</th>`).join("") + "</tr></thead>";
    }
    
    // Table body
    table += "<tbody>";
    data.forEach(row => {
        table += "<tr>" + columns.map(col =>
            `<td>${row[col] === null ? '<span class="null-value">NULL</span>' : escapeHTML(String(row[col]))}</td>`
        ).join("") + "</tr>";
    });
    table += "</tbody></table></div>";
    console.log(table);
    return table;
}

/**
 * Escape HTML special characters to prevent XSS
 * @param {string} str - String to escape
 * @returns {string} Escaped string
 */
function escapeHTML(str) {
    return str
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;")
        .replace(/"/g, "&quot;")
        .replace(/'/g, "&#039;");
}

/**
 * Show table content by prompting for table name
 */
async function showTableContent() {
    const tableName = prompt("Enter table name:");
    if (tableName) {
        runQuery(`SELECT * FROM ${tableName};`);
    }
}

/**
 * Show table structure by prompting for table name
 */
async function showTableMetadata() {
    const tableName = prompt("Enter table name:");
    if (tableName) {
        runQuery(`DESC ${tableName};`);
    }
}

/**
 * Rollback the current transaction
 */
async function rollbackQuery() {
    runQuery("ROLLBACK;");
}

/**
 * Commit the current transaction
 */
async function commitQuery() {
    runQuery("COMMIT;");
}

/**
 * Drop table after confirming with user
 */
async function dropTable() {
    const tableName = prompt("Enter table name to DROP:");
    if (!tableName) return;
    
    // Double confirm with user to prevent accidents
    const confirmed = confirm(`Are you sure you want to DROP table ${tableName}? This action cannot be undone.`);
    if (confirmed) {
        runQuery(`DROP TABLE ${tableName};`);
    }
}