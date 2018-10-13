<?php 
for ($i=9; $i>=1; $i--) {  
    for($j=1; $j<=$i; $j++) {  
       echo '&nbsp;';  
    }
    $j--;
    for ($k=1; $k<=(10-$j); $k++) {  
        echo " # ";   
    }  
    echo "<br>\n";
}