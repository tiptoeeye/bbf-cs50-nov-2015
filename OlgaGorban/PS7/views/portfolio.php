<div>
<table>
    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>

    <tbody>
        <?php if (!empty($positions)): ?>
            <?php foreach ($positions as $position): ?>

            <tr>
                <td><?= $position["symbol"] ?></td>
                <td><?= $position["name"] ?></td>
                <td><?= $position["shares"] ?></td>
                <td><?= "$" .number_format($position["price"],2) ?></td>
                <td><?= "$" .number_format($position["total"],2) ?></td>
            </tr>
            <?php endforeach ?>
        <?php else: ?>
            <tr>
                <td colspan="5"> No stocks in portfolio </td>
            </tr>
        <?php endif ?>
        <tr>
            <td colspan="4">Remainder</td>
            <td>$<?=number_format($user[0]["cash"], 2)?></td>
        </tr>
    </tbody>
</table>
</div>
<br>
<div class="form-group" >
    <a href="deposit.php">
    <button class="btn btn-default" type="submit">
            $ Deposit
    </button>
    </a>
</div>
