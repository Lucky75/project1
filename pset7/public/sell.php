<?php

    // configuration
    require("../includes/config.php"); 
if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
    
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


render("sell_form.php", ["cash" => $cashf, "positions" => $positions, "title" => "Sell"]);
}

    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["share"]))
        {
            apologize("You must write the name of share, you want to sell.");
        }
        if (empty($_POST["number"]))
        {
            apologize("You must provide how much shares you want to sell.");
        }
        

        // query database for sell
        $rows = query("SELECT shares FROM shares WHERE symbol = ? AND id = ?", strtoupper($_POST["share"]), $_SESSION["id"]);

        // if we found the share, check the number of them
        if (count($rows) == 1)
        {
            // first (and only) row
            $row = $rows[0];
            $stock1 = lookup($_POST["share"]);
            if($row["shares"] == $_POST["number"])
            {
                query("DELETE FROM shares WHERE symbol = ? AND id = ?", strtoupper($_POST["share"]), $_SESSION["id"]);
                query("UPDATE users SET cash = cash +? WHERE id = ?",$stock1["price"]*$_POST["number"], $_SESSION["id"]);
                query("INSERT INTO history (do, share, number, price, time, id)VALUES (?,?,?,?,?,?)","SELL",strtoupper($_POST["share"]),$_POST["number"],$stock1['price'],date("Y-m-d H:i:s"), $_SESSION["id"]);
                
                      //    if( mail("50983-1@mail", "My Subject", "Line 1\nLine 2\nLine 3"))
                    //        apologize("1");

                // redirect to portfolio
                redirect("/sell.php");
            }
            else if($row["shares"] > $_POST["number"])
            {
                
               query("UPDATE shares SET shares = shares - ? WHERE symbol = ? AND id = ?", $_POST["number"], strtoupper($_POST["share"]), $_SESSION["id"]);
               query("UPDATE users SET cash = cash + ? WHERE id = ?", $stock1["price"]*$_POST["number"], $_SESSION["id"]);
                query("INSERT INTO history (do, share, number, price, time, id)VALUES (?,?,?,?,?,?)","SELL",strtoupper($_POST["share"]),$_POST["number"],$stock1['price'],date("Y-m-d H:i:s"), $_SESSION["id"]);

           // if( mail("50983-1@mail", "My Subject", "Line 1\nLine 2\nLine 3" ))
        //        apologize("2");

            // redirect to portfolio
                redirect("/sell.php");
            }
            else
            {
                apologize("You don't have enough shares/ such shares");
            }
        }
        else 
            {
                apologize("You don't have such shares");
            }
        
}

?>