document.addEventListener("DOMContentLoaded", function() {
    const programsContainer = document.getElementById('programsContainer');

    // Loop through the numbers 1 to 25 to dynamically create each program block
    for (let i = 1; i <= 25; i++) {
        // Create the outer div for each program
        const programDiv = document.createElement('div');
        programDiv.classList.add('programs');
        programDiv.id = `prg${i}`;

        // Create the inner div for each programTop
        const programTop = document.createElement('div');
        programTop.classList.add('programsTop');

        // Create the label for the program
        const label = document.createElement('label');
        label.htmlFor = `code${i}`;
        label.textContent = `Program ${i}`; // You can set a more descriptive label if needed

        // Create the Copy button
        const copyButton = document.createElement('button');
        copyButton.classList.add('copyBtn');
        copyButton.textContent = 'Run Code';
        copyButton.setAttribute('data-code', `code${i}`);

        // Create the pre/code block to display the C++ code
        const pre = document.createElement('pre');
        const code = document.createElement('code');
        code.id = `code${i}`;
        code.classList.add('language-cpp');
        pre.appendChild(code);

        // Append top to the program div
        programTop.appendChild(label);
        programTop.appendChild(copyButton);

        // Append everything to the program div
        programDiv.appendChild(programTop);
        programDiv.appendChild(pre);

        // Append the entire program div to the container
        programsContainer.appendChild(programDiv);

        // Fetch the C++ file and insert it into the <code> element
        fetch(`codes/${i}.cpp`)
            .then(response => response.text())
            .then(data => {
                code.textContent = data; // Set the content inside the <code> tag
                // Highlight the inserted code using Highlight.js
                hljs.highlightElement(code);
            })
            .catch(error => console.error(`Error fetching ${i}.cpp:`, error));
    }

    // Add the copy functionality
    const copyButtons = document.querySelectorAll('.copyBtn');
    copyButtons.forEach(button => {
        button.addEventListener('click', function() {
            const codeId = this.getAttribute('data-code');
            const codeElement = document.getElementById(codeId);

            if (codeElement) {
                const codeText = codeElement.innerText;

                // Create a temporary textarea element to copy the code
                const tempTextArea = document.createElement('textarea');
                tempTextArea.value = codeText;
                document.body.appendChild(tempTextArea);

                // Select and copy the code
                tempTextArea.select();
                document.execCommand('copy');

                // Remove the temporary element
                document.body.removeChild(tempTextArea);

                // Inform the user the code has been copied
                alert('Code copied to clipboard!');

                // Ask if the user wants to be redirected to the Programiz compiler
                const userConfirmation = confirm('Do you want to open Programiz online compiler to run this code?');

                // If user agrees, open Programiz in a new tab
                if (userConfirmation) {
                    window.open('https://www.programiz.com/cpp-programming/online-compiler/', '_blank');
                }
            }
        });
    });
});

// Scroll functionality for "Top" button
window.onscroll = function() {
  toggleTopButton();
};

function toggleTopButton() {
  const topButton = document.getElementById("topBtn");
  if (document.body.scrollTop > 100 || document.documentElement.scrollTop > 100) {
    topButton.style.display = "block"; // Show button when scrolled
  } else {
    topButton.style.display = "none"; // Hide button when not scrolled
  }
}

function scrollToTop() {
  document.body.scrollTop = 0; // For Safari
  document.documentElement.scrollTop = 0; // For Chrome, Firefox, IE, and Opera
}
