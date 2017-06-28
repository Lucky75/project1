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


render("buy_form.php", ["cash" => $cashf, "positions" => $positions, "title" => "Buy"]);
}

    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["share"]))
        {
            apologize("You must write the name of share, you want to sell.");
        }
        
        if (!preg_match("/^\d+$/", $_POST["number"]))
        {
            apologize("Wrong number. Try again");
        }
        
        if (empty($_POST["number"]))
        {
            apologize("You must provide how much shares you want to sell.");
        }
        
        $stock1 = lookup($_POST["share"]);
        if ($stock1==false)
        {
            apologize("There are not such shares, try another name");
        }
        // query database for sell
        
        $rows = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $row=$rows[0];
        
        if ($stock1["price"]*$_POST["number"]>$row)
        {
            apologize("You must earn more money for it, it would better go to work");
        }
        // if we found the share, check the number of them
        
        $rows1 = query("SELECT shares FROM shares WHERE symbol = ? AND id = ?",strtoupper($_POST["share"]), $_SESSION["id"]);
        if (count($rows1)==0)
        {
            query("INSERT INTO  shares (id ,symbol ,shares)VALUES (?,  ?,  ?)",$_SESSION["id"],strtoupper($_POST["share"]),$_POST["number"]);
            query("UPDATE users SET cash = cash -? WHERE id = ?", $stock1["price"]*$_POST["number"], $_SESSION["id"]);
            query("INSERT INTO history (do, share, number, price, time, id)VALUES (?,?,?,?,?,?)","BUY",strtoupper($_POST["share"]),$_POST["number"],$stock1['price'],date("Y-m-d H:i:s"), $_SESSION["id"]);
        redirect("/index.php");
            
        }
        else if (count($rows1) == 1)
         {
               query("UPDATE shares SET shares = shares + ? WHERE symbol = ? AND id = ?", $_POST["number"], strtoupper($_POST["share"]), $_SESSION["id"]);
               query("UPDATE users SET cash = cash - ? WHERE id = ?", $stock1['price']*$_POST["number"], $_SESSION["id"]);
                query("INSERT INTO history (do, share, number, price, time, id)VALUES (?,?,?,?,?,?)","BUY",strtoupper($_POST["share"]),$_POST["number"],$stock1['price'],date("Y-m-d H:i:s"), $_SESSION["id"]);
            // redirect to portfolio
                redirect("/index.php");
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

?>