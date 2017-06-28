<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["username"]) or empty($_POST["password"]) or empty($_POST["confirmation"])or empty($_POST["email"]))
        {
            apologize("You must provide your username and password twice and e-mail.");
        }
        
        else if (strcmp($_POST["password"], $_POST["confirmation"])!=0)
        {
            apologize("Passwords are different");
        }
        
        else if (query("INSERT INTO users (username, hash,email, cash) VALUES(?,?, ?, 1000.00)", $_POST["username"], crypt($_POST["password"]),$_POST["email"])===false)
        {
            apologize("Error, perhaps, the name or e-mail is registered, try another name or e-mail");
        }
        else 
        {
            $rows = query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
             $_SESSION["id"] = $id["id"];
            redirect("/index.php");   
        }
    }
?>