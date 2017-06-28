

<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];
    $geo = $_GET["geo"];
    $quest = [];
    
    $rows = explode(",",$geo);
    
    for($i = 0; $i<count($rows); $i++)
    {
        if(stristr($rows[$i], ' '))
            {
                $row = explode(" ",$rows[$i]);
                for($j=0; $j<count($row); $j++)
                {
                $quest[] = $row[$i];
                }
            }
            else
            $quest[] = $rows[$i];
        
    }

$geo = implode(" ", $quest);
    	// Search across multiple columns
    	$places = query("SELECT * FROM places WHERE MATCH(postal_code, place_name, admin_name1, admin_name2) AGAINST (? IN BOOLEAN MODE)", $geo."*");

    
    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>
