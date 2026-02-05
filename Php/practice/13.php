<?php 
    $myarr = array(array("1","2","3"),array("4","5","6"),array("7","8","9"));
    foreach ($myarr as $key => $value) {
        foreach ($value as $key => $v) {
            echo $v;
        }
    }
?>