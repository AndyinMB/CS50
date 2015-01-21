<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["deposit"] == null)
        {
            apologize("You must enter an amount");
        }
        
        if (preg_match("/^\d+$/", $_POST["deposit"]) == false)
        {
            apologize("Share amount must be a whole positive number.");
        }      
             
        query("UPDATE users SET cash = cash + ? where id = ?", $_POST["deposit"], $_SESSION["id"]);
        redirect("index.php");    
         
    }
    else
    {
        // else render form
        render("deposit_form.php", ["title" => "Deposit"]);
    }

?>
