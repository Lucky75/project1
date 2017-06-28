<?php
    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("change_p_form.php", ["title" => "Change password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["old_password"]))
        {
            apologize("You must provide your old password.");
        }
        else if (empty($_POST["password"])or empty($_POST["confirmation"]))
        {
            apologize("You must provide your new password and confirmation");
        }
        else if (strcmp($_POST["password"], $_POST["confirmation"])!=0)
        {
            apologize("Passwords are different");
        }
        
        // query database for user
        $rows = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);

        // if we found user, check password
        if (count($rows) == 1)
        {
            // first (and only) row
            $row = $rows[0];
            
            
           // apologize(crypt($_POST["old_password"],$row["hash"]));
            
            
            // compare hash of user's input against hash that's in database
            if (crypt($_POST["old_password"],$row["hash"]) == $row["hash"])
            {
               query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["password"]), $_SESSION["id"]); 
               
               // redirect to portfolio
                render("message_password.php", ["title" => "Change password"]);
            }
             else// else apologize
        {apologize("Invalid old password.");}
        }

       
    }

?>
