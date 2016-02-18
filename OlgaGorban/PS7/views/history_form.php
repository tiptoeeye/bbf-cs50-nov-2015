<div>
<table>
    <thead>
        <tr>
            <th>Date/Time</th>
            <th>Transaction</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
            <th>Transaction Value</th>
        </tr>
    </thead>

    <tbody>
    <?php if (!empty($history)): ?>    
        <?php foreach ($history as $row): ?>
            <tr>
                <td><?= $row["trans_date"] ?></td>
                <td><?= $row["transaction"] ?></td>
                <td><?= $row["symbol"] ?></td>
                <td><?php print($row["shares"] == 0 ? "" : $row["shares"]) ?></td>
                <td><?php print($row["share_price"] == 0 ? "" : "$" . $row["share_price"]) ?></td>
                <td><?= "$" . $row["trans_value"] ?></td>
            </tr>
        <?php endforeach ?>    
            <tr>
                <td colspan="5">Remainder</td>
                <td>$<?=number_format($user[0]["cash"], 2)?></td>
            </tr>
    <?php else: ?>
        <tr>
            <td colspan="6"> No transaction history </td>
        </tr>
    <?php endif ?>
    </tbody>
</table>
</div>