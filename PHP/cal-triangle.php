<?php 
$height = isset($_GET['h']) ? $_GET['h'] : 0;
$base = isset($_GET['b']) ? $_GET['b'] : 0;

$sum=(1*$high*$base)/2;

echo 'Triangle area = '.$sum;