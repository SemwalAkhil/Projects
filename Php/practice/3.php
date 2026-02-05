<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form action="3.php" method="get">
        First Number: <input type="number" name="a"><br>
        Second Number: <input type="number" name="b"><br>
        Third Number: <input type="number" name="c"><br>
        <button type="submit">Compare</button>
    </form>
    <?php 
        if (isset($_GET["a"]) and isset($_GET["b"])  and isset($_GET["c"]) ) {
            $a = $_GET["a"];
            $b = $_GET["b"];
            $c = $_GET["c"];
            if ($a > $b) {
                if ($a > $c) {
                    echo "$a is greatest";
                }
                else{
                    echo "$c is greatest";
                }
            }
            else{
                if ($b > $c) {
                    echo "$b is greatest";
                }
                else{
                    echo "$c is greatest";
                }
            }
        }
    ?>
</body>

</html>