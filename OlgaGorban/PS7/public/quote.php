<?php
    // configuration
    require("../includes/config.php"); 
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        //render form
        render("quote_form.php", ["title" => "Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
    
        // lookup the stock price
        $stock = lookup($_POST["symbol"]);
        if ($stock != false)
        {
            // display the quote
            render("quote_result.php", ["title" => "Guote", "stock" => $stock]);
        }
        else
        {
            apologize("Symbol not found.");
        }
    }
?>