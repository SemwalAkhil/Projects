<?php
session_start();              // 1. Start the session
$_SESSION = array();          // 2. Clear all session variables
session_destroy();            // 3. Destroy the session
header("Location: login.php"); // 4. Redirect to login page
exit();
?>