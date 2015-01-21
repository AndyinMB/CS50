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
    //get shares and lookup current stock price    
        $shares = query("SELECT shares FROM portfolio WHERE id = ? and symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        $stock = lookup($_POST["symbol"]);
        
        if ($shares != null)
        {
            $query = query("DELETE FROM portfolio where id = ? and symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            if ($query === false)
            {
                apologize("Error while selling shares.");
            }
            $value = ($stock["price"] * $shares[0]["shares"]);
            query("UPDATE users SET cash = cash + ? where id = ?", $value, $_SESSION["id"]);
            query("INSERT INTO history (id, date, action, symbol, shares, price) VALUES (?, now(), ?, ?, ?, ?)"
                ,$_SESSION["id"], "Sell", strtoupper($_POST["symbol"]), $shares[0]["shares"], $stock["price"]);
            redirect("index.php");
        }
        else
        {
            apologize("No shares found");     
        }     
    }
    else
    {
        // else render form
        render("sell_form.php", ["title" => "Sell"]);
    }

?>
