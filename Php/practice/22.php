<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form action="22.php" method="get">
        First Number: <input type="number" name="a"><br>
        Second Number: <input type="number" name="b"><br>
        Third Number: <input type="number" name="c"><br>
        <button type="submit">Store</button>
    </form>
    <?php 
        if(isset($_GET["a"]) and isset($_GET["b"]) and isset($_GET["c"])){
            if (!is_dir()) {
                # code...
            }
        }
    ?>
</body>

</html>