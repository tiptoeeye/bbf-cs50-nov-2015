<?php
    // configuration
    require("../includes/config.php"); 
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("sell_form.php", ["title" => "Sell"]);
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
        
        // capitalize symbol
        $_POST["symbol"] = strtoupper($_POST["symbol"]);
            
        if ($stock != false)
        {
            if (empty($_POST["shares"]))
            {
                apologize("You must provide shares.");
            }
            
            // set transaction type
            $transaction = 'SELL';
            
            $shares = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            if($_POST["shares"]>$shares[0]["shares"])
            {
                apologize("You must provide a valid number of shares. You have only ". $shares[0]["shares"]. " such shares.");
            }
            
            $value = $stock["price"] * $_POST["shares"];
            if ($_POST["shares"]==$shares[0]["shares"])
                //sell the stock
                CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            
            else
                CS50::query("UPDATE portfolios SET shares = shares - ? WHERE user_id = ? AND symbol = ?", $_POST["shares"], $_SESSION["id"], $_POST["symbol"]); 
            
            //change cash
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $value, $_SESSION["id"]);
            
            //add to history
            CS50::query("INSERT INTO history (id, transaction, symbol, shares, share_price, trans_value) VALUES (?, ?, ?, ?, ?, ?)", $_SESSION["id"], $transaction, $_POST["symbol"], $shares[0]["shares"], $stock["price"], $value);
            
            // redirect to portfolio 
            redirect("/"); 
            
        }
        else
        {
            apologize("Symbol not found.");
        }
   
    }
?>