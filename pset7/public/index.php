<?php

    // configuration
    require("../includes/config.php"); 
    
$cashf = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
$rows = query("SELECT symbol, shares FROM shares WHERE id = ?", $_SESSION["id"]);
$positions = [];

foreach ($rows as $row)
{
    $stock = lookup($row["symbol"]);
    if ($stock !== false)
    {
        $positions[] = [
            "name" => $stock["name"],
            "price" => $stock["price"],
            "shares" => $row["shares"],
            "symbol" => $row["symbol"],
        ];
    }
}


render("portfolio.php", ["cash" => $cashf, "positions" => $positions, "title" => "Portfolio"]);
?>