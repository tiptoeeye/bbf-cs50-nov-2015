<?php
    // configuration
    require("../includes/config.php"); 
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("deposit_form.php", ["title" => "Deposit"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (!preg_match("/^\d+\.\d\d$/", $_POST["funds"]) || $_POST["funds"] <= 0)
        {
            apologize("Please enter a positive amount of funds to deposit in your account, including cents.");
        }
        
        // set transaction type
        $transaction = 'DEPOSIT';
        
        // add funds
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["funds"], $_SESSION["id"]);
        
        //add to history
        CS50::query("INSERT INTO history (id, transaction, trans_value) VALUES (?, ?, ?)", $_SESSION["id"], $transaction, $_POST["funds"]);
        
        // redirect to portfolio 
        redirect("/"); 
    }
?>