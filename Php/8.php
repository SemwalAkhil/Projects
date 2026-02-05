<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Basic Calculator</title>
</head>

<body>
    <form action="8.php" method="get">
        <label for="num1">Enter first number : </label>
        <input type="number" name="num1" value="0">
        <label for="num2">Enter second number : </label>
        <input type="number" name="num2" value="0">
        <label for="opr"></label>
        <select name="opr">
            <option value="1" selected>Add</option>
            <option value="2" >Subtract</option>
            <option value="3" >Multiply</option>
            <option value="4" >Divide</option>
        </select>
        <button type="submit">Submit</button>
    </form>
    <?php
        if(isset($_GET["opr"]) and isset($_GET["num1"]) and isset($_GET["num2"])){
            $opr = $_GET["opr"];
            $num1 = $_GET["num1"];
            $num2 = $_GET["num2"];
            if ($opr == 1) {
                echo $num1 + $num2;
            }
            elseif ($opr == 2) {
                echo $num1 - $num2;
            }
            elseif ($opr == 3) {
                echo $num1 * $num2;
            }
            elseif ($opr == 4) {
                try {
                    echo $num1 / $num2;
                } catch (\DivisionByZeroError $th) {
                    echo "Error: Divide by Zero";
                }
            }
            else{
                echo "Choose a valid operation";
            }
        }
    ?>
</body>

</html>