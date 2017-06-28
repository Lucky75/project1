<?php// список акций?>
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
        <td><h4>  <?= $position["price"]*$position["shares"] ?>$ &nbsp </h4></td>
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
        <td><h4> <?= $total_cost?>$ &nbsp  </h4></td>
    </tr>
</table>
 <h4> Your money: <?= $cash[0]["cash"] ?>$ </h4>
 
<h4> Your total money: <?= $cash[0]["cash"]+$total_cost ?>$ </h4>


<?php//форма для продажи?>

<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autofocus class="form-control" name="share" placeholder="Share" type="text"/>
            <input autofocus class="form-control" name="number" placeholder="number" type="text"/>
        </div>
               <div class="form-group">
            <button type="submit" class="btn btn-default">Sell</button>
        </div>
    </fieldset>
</form>




<?php//ссылки на страницы ?>
<div>
    <a href="index.php">Back </a> to the portfolio
</div>
<br>

<div>
    or <a href="logout.php">Log out</a> from the account
</div>

