<?php 
include_once('dbconnect.php'); 
$qry="SELECT * FROM tbempmst1 ORDER BY EmpSal desc"; 
$result= mysqli_query($conn, $qry);
if ($result){ 
    echo "<table border='1'>"; 
    echo "<tr>"; 
    echo "<th>Employee Id</th>"; 
    echo "<th>Employee Name</th>"; 
    echo "<th>Employee Salary</th>"; 
    echo "<th>Update</th>"; 
    echo "<th>Delete</th>"; 
    echo "</tr>"; 
        while ($row = mysqli_fetch_array($result)) {  
            echo"<tr>"; 
            echo"<td>" .$row['EmpCod']. "</td>"; 
            echo"<td>" .$row['EmpNam']. "</td>"; 
            echo"<td>" .$row['EmpSal']. "</td>"."<br>"; 
            echo"<td><a href='update.php?qEmpCod=" .$row['EmpCod'] .">Update</a></td>"; 
            echo"<td><a href='delete.php?qEmpCod=" .$row['EmpCod'] .">Delete</a></td>";
            echo"</tr>"; 
        } 
    echo"</table>";
} 
mysqli_free_result($result); 
mysqli_close($conn); 
?> 