
<table border = "1"  align="center">
   <h4> You have such shares: </h4>
     <tr>
        <td><h4> Symbol:   &nbsp </h4></td>  
        <td><h4> Name:   &nbsp </h4></td>
        <td><h4> Number:  &nbsp  </h4></td>  
        <td><h4> Price:  &nbsp </h4></td>
        <td><h4> Cost:   &nbsp </h4></td>
    </tr>
    <?php
    $total_number = 0;
    $total_price = 0;
    $total_cost = 0;
    
    foreach ($positions as $position): ?>
    <tr>
        <td><h4>  <?= $position["symbol"] ?>  &nbsp </h4></td>  
        <td><h4>  <?= $position["name"] ?>  &nbsp </h4></td>
        <td><h4>  <?= $position["shares"] ?> &nbsp  </h4></td>  
        <td><h4>  <?= $position["price"] ?>$  &nbsp </h4></td>
        <td><h4>  <?= $position["price"]*$position["shares"] ?>$  &nbsp </h4></td>
    </tr>
    


<?php
$total_number+=$position["shares"];
$total_price+=$position["price"];
$total_cost+=$position["price"]*$position["shares"];
endforeach?>
<tr>
        <td><h4> Total &nbsp </h4></td>  
        <td><h4>  &nbsp </h4></td>
        <td><h4>  <?= $total_number ?> &nbsp  </h4></td>  
        <td><h4>  &nbsp </h4></td>
        <td><h4> <?= $total_cost?>$  &nbsp </h4></td>
    </tr>
</table>
 <h4> Your money: <?= $cash[0]["cash"] ?>$</h4>
 
<h4> Your total money: <?=$cash[0]["cash"]+$total_cost?>$</h4>


<table  align="center"> 
    <td><h5><a href="buy.php">Buy </a> new shares &nbsp &nbsp &nbsp </h5></td>

    <td><h5><a href="quote.php">Find out </a> about shares &nbsp &nbsp &nbsp</h5></td>

    <td><h5><a href="sell.php">Sell </a>your shares &nbsp &nbsp &nbsp</h5></td>
    
    <td><h5><a href="history.php">History </a> &nbsp &nbsp &nbsp </h5></td>
</table>
<br>
<div>
<a href="change_p.php">Change password</a>
</div>

<br>
<div>
<a href="logout.php">Log Out</a>
</div>