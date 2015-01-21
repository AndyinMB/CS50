 <?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = query("SELECT date, action, symbol, shares, price FROM history WHERE id = ?", $_SESSION["id"]);
    
    if ($rows == null)
        {
            apologize("No history available.");
        }
    
    $positions = [];
    
    foreach ($rows as $row)
    {   
        $positions[] = [
            "date" => $row["date"],
            "action" => $row["action"],
            "symbol" => $row["symbol"],
            "shares" => $row["shares"],
            "price" => $row["shares"]
            ];
    }
    
    // render portfolio
    render("history_display.php", ["positions" => $positions, "title" => "History"]);

?>
