<?php
echo "include <br><br>";
include("6.php");
include("non_existing_include.php");

echo "require <br><br>";
require("6.php");
require("non_existing_require.php"); // This will cause a fatal error
?>
