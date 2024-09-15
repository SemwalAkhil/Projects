document.addEventListener("DOMContentLoaded", function() {
    // Loop through the numbers 1 to 9
    for (let i = 1; i <= 9; i++) {
        // Fetch each corresponding C++ file (e.g., 1.cpp, 2.cpp, ..., 9.cpp)
        fetch(`codes/${i}.cpp`)
            .then(response => response.text())
            .then(data => {
                // Find the <code> element with the matching id and insert the code
                const cppCode = document.getElementById("code"+i.toString());
                cppCode.textContent = data; // Set the content inside the <code> tag
                // Highlight the inserted code using Highlight.js
                hljs.highlightElement(cppCode);
            })
            .catch(error => console.error(`Error fetching ${i}.cpp:`, error));
    }
});