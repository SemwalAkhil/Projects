window.onscroll = function() {
  toggleTopButton();
};
window.onload = function(){
  createFooter();
}
function toggleTopButton() {
  const topButton = document.getElementsByClassName("topBtn")[0];
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
 function createFooter() {
            // Create the footer container
            const footer = document.createElement("footer");
            footer.style.cssText = "color: #FEECB3; padding: 1px; text-align: center;";

            // Add content to the footer
            footer.innerHTML = `
                <p>Akhil Semwal 4033/23</p>
            `;

            // Append the footer to the body
            document.body.appendChild(footer);
        }