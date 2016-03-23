<?php
    // configuration
    require("../includes/config.php"); 
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
        
        $stock = lookup($_POST["symbol"]);
        
        if ($stock != false)
        {
            if (empty($_POST["shares"]))
            {
                apologize("You must provide shares.");
            }
            
            // if shares is invalid
            if (preg_match("/^\d+$/", $_POST["shares"]) == false)
            {
            // apologize
            apologize("Please enter a valid number of shares to purchase.");
            }
            
            // set transaction type
            $transaction = 'BUY';
            
            $cost = $stock["price"] * $_POST["shares"];
            
            $cash =	CS50:: query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
            
            //check if user can afford this
            if ($cash[0]["cash"] < $cost)
            {
                apologize("You can't afford this purchase.");
            }
            
            else
            {
                // capitalize symbol
                $_POST["symbol"] = strtoupper($_POST["symbol"]);
                
                //update shares
                CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) 
                ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);
            
                //update cash
                CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);
                
                //add to history
                CS50::query("INSERT INTO history (id, transaction, symbol, shares, share_price, trans_value) VALUES (?, ?, ?, ?, ?, ?)", $_SESSION["id"], $transaction, $_POST["symbol"], $_POST["shares"], $stock["price"], $cost);
                
                // redirect to portfolio 
                redirect("/"); 
            }
        }
        else
        {
            apologize("Symbol not found.");
        }
   
    }
?>