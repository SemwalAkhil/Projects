<?php 
    $arr = array(1,2,5,2,3,3,4);
    sort($arr);
    foreach ($arr as $key => $value) {
        echo $value;
    };
    echo "<br>";
    rsort($arr);
    foreach ($arr as $key => $value) {
        echo $value;
    }
?>