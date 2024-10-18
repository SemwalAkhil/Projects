window.onscroll = function() {
  toggleTopButton();
};

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
