<?php// список акций?>
    <?php
    $total_number = 0;
    $total_price = 0;
    $total_cost = 0;
    
    foreach ($positions as $position):
$total_number+=$position["shares"];
$total_price+=$position["price"];
$total_cost+=$position["price"]*$position["shares"];
endforeach?>
 <h4> Your money: <?= $cash[0]["cash"] ?>$</h4>
 
<h4> Your total money: <?= $cash[0]["cash"]+$total_cost ?>$</h4>


<?php//форма для купивли?>

<form action="buy.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autofocus class="form-control" name="share" placeholder="Share" type="text"/>
            <input autofocus class="form-control" name="number" placeholder="number" type="text"/>
        </div>
               <div class="form-group">
            <button type="submit" class="btn btn-default">Buy</button>
        </div>
    </fieldset>
</form>




<?php//ссылки на страницы ?>
<div>
    <a href="index.php">Back </a> to the portfolio
</div>
<br>
<div>
    <a href="quote.php">You can find out about shares</a>
</div>
<div>
    or <a href="logout.php">Log out</a> from the account
</div>

