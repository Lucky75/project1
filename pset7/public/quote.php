<?php
    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Buy the action"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["action"]))
        {
            apologize("You must provide the name of action");
        }
       else 
       {
           $stock = lookup($_POST["action"]);
           if ($stock != false)
            {
            $price = $stock['price'];
            $name = $stock['name'];
            
            render("message.php", ["title" => "Message", "price" => $stock["price"], "name" => $stock['name']]);
            
            }
            else
            apologize("action is not exist");
       }    
    }

?>
