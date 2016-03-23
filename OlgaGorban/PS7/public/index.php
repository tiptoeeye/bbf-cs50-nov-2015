<?php

    // configuration
    require("../includes/config.php"); 
    
    $user = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    
    $positions = [];
    
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "symbol" => $row["symbol"],
                "name" => $stock["name"],
                "shares" => $row["shares"],
                "price" => $stock["price"],
                "total" => $stock["price"]*$row["shares"],
            ];
        }
    }
    
    
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "user" => $user]);
?>
