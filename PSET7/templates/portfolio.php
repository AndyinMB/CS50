<div>
    <ul class="nav nav-pills">
        <li><a href="quote.php">Quote</a></li>
        <li><a href="buy.php">Buy</a></li>
        <li><a href="sell.php">Sell</a></li>
        <li><a href="history.php">History</a></li>
        <li><a href="deposit.php">Add Funds</a></li>
    </ul>
</div>

    <table class="table table-striped">
        <thead>
            <tr>
                <th>Symbol</th>
                <th>Name</th>
                <th>Shares</th>
                <th>Price</th>
                <th>Total</th>
            </tr>
        </thead>
        <tbody   style="text-align: left;">
            <?php 
            
                foreach ($positions as $position)
                {
                    print("<tr>");
                    print("<td>{$position["symbol"]}</td>");
                    print("<td>{$position["name"]}</td>");
                    print("<td>{$position["shares"]}</td>");
                    print("<td>{$position["price"]}</td>");
                    print("<td>{$position["total"]}</td>");
                    print("</tr>");
                }    
            ?>
            <tr><td>CASH</td><td></td><td></td><td></td><td><?=$cash?></td></tr>
        </tbody>
    </table>    
<div>
    <a href="logout.php">Log Out</a>
</div>
