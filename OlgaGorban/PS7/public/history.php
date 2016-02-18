<?php

    // configuration
    require("../includes/config.php"); 
    
    $result = CS50::query("SELECT transaction, trans_date, symbol, shares, share_price, trans_value FROM history WHERE id = ? ORDER BY trans_date DESC", $_SESSION["id"]);
    $user = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]); 
        
    $history = [];
    foreach ($result as $row)
    {
        $history[] = [
            "transaction" => $row["transaction"],
            "trans_date"  => date_format(date_create($row["trans_date"]), 'm-d-Y g:i A'),
            "symbol"      => $row["symbol"],
            "shares"      => number_format($row["shares"]),
            "share_price" => number_format($row["share_price"], 2),
            "trans_value" => number_format($row["trans_value"], 2)
        ];
    }    
    
    // render history
    render("history_form.php", ["title" => "History", "history" => $history, "user" => $user]);
?>