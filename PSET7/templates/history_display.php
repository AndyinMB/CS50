
    <table class="table table-striped">
        <thead>
            <tr>
                <th>Date</th>
                <th>Action</th>
                <th>Symbol</th>
                <th>Shares</th>
                <th>Price</th>
            </tr>
        </thead>
        <tbody   style="text-align: left;">
            <?php 
            
                foreach ($positions as $position)
                {
                    print("<tr>");
                    print("<td>{$position["date"]}</td>");
                    print("<td>{$position["action"]}</td>");
                    print("<td>{$position["symbol"]}</td>");
                    print("<td>{$position["shares"]}</td>");
                    print("<td>{$position["price"]}</td>");
                    print("</tr>");
                }    
            ?>
        </tbody>
    </table>    
<div>
    <a href="logout.php">Log Out</a>
</div>
