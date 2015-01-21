<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["symbol"] == null)
        {
            apologize("You must enter a symbol");
        }
        
        if (preg_match("/^\d+$/", $_POST["amount"]) == false)
        {
            apologize("Share amount must be a whole positive number.");
        }      
             
    //check to see if there is enough money    
        $balance = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $stock = lookup($_POST["symbol"]);
        $value = ($stock["price"] * $_POST["amount"]);
        
        if ($balance[0]["cash"] < $value)
        {
            apologize("Sorry, not enough cash.");
        }

        else
        {
            query("UPDATE users SET cash = cash - ? where id = ?", $value, $_SESSION["id"]);
            query("INSERT INTO portfolio (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?",
            $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["amount"], $_POST["amount"]);
            query("INSERT INTO history (id, date, action, symbol, shares, price) VALUES (?, now(), ?, ?, ?, ?)"
                ,$_SESSION["id"], "Buy", strtoupper($_POST["symbol"]), $_POST["amount"], $stock["price"]);
            redirect("index.php");    
        }     
    }
    else
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }

?>
