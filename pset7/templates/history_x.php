
<table border = "1"  align="center">
   <h4> You have such shares: </h4>
     <tr>
        <td><h4> Buy/Sell:   &nbsp </h4></td>  
        <td><h4> Name:   &nbsp </h4></td>
        <td><h4> Number:  &nbsp  </h4></td>  
        <td><h4> Price:  &nbsp </h4></td>
        <td><h4> Cost:   &nbsp </h4></td>
        <td><h4> Time:   &nbsp </h4></td>    
    </tr>
    <?php
    $total_number = 0;
    $total_price = 0;
    $total_cost = 0;
    
    foreach ($positions as $position): ?>
    <tr>
        <td><h4>  <?= $position["do"] ?>  &nbsp </h4></td>  
        <td><h4>  <?= $position["share"] ?>  &nbsp </h4></td>
        <td><h4>  <?= $position["number"] ?> &nbsp  </h4></td>  
        <td><h4>  <?= $position["price"] ?>$  &nbsp </h4></td>
        <td><h4>  <?= $position["price"]*$position["number"] ?>$  &nbsp </h4></td>
        <td><h4>  <?= $position["time"] ?>  &nbsp </h4></td>
    </tr>
    


<?php
$total_number+=$position["number"];
$total_price+=$position["price"];
$total_cost+=$position["price"]*$position["number"];
endforeach?>
</table>
 
<br>
    
<div>
    <a href="index.php">Back </a> to the portfolio
</div>
<br>
<div>
<a href="logout.php">Log Out</a>
</div>