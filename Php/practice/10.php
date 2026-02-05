<?php
    function func(){
        static $num = 10; 
        if ($num > 0){
            $num -= 1;
            echo $num;
            func();
        }
    }
    echo func();
?>