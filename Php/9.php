<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Madlib Game</title>
</head>

<body>
    <form action="9.php" method="get">
        <label for="noun">Enter noun: </label>
        <input type="text" name="noun">
        <label for="adjective">Enter adjective: </label>
        <input type="text" name="adjective">
        <label for="name">Enter name: </label>
        <input type="text" name="name">
        <button type="submit">Submit</button>
    </form>
    <?php
    if (isset($_GET["name"]) and isset($_GET["noun"]) and isset($_GET["adjective"])){
        $adjective = $_GET["adjective"];
        $noun = $_GET["noun"];
        $name = $_GET["name"];
        echo <<<VAR
    Roses are $adjective <br>
    $noun is blue <br>
    $name love you <br>
    VAR;
    } 
    else {
        echo "Please enter values before submitting.";
    }
    ?>
</body>

</html>
