<?php 
date_default_timezone_set("Asia/Jakarta");
// mengatur tanggalsekarang
echo date("Y/m/d-h:i a") . "<br>";


$format = mktime(11, 12, 0, 11, 8, 2018);
echo date("Y/m/d-h:i a", $format)
 ?>