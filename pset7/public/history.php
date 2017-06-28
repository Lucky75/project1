<?php

    // configuration
    require("../includes/config.php"); 
    
$rows = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);
$positions = [];

foreach ($rows as $row)
{

        $positions[] = [
            "do" => $row["do"],
            "share" => $row["share"],
            "number" => $row["number"],
            "time" => $row["time"],
            "price" => $row["price"],
        ];
}


render("history_x.php", ["positions" => $positions, "title" => "History"]);
?>