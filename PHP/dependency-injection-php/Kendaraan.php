<?php

function __autoload($class)
{
    $file   = $class . ".php";
    if (is_readable($file)) {
        require $file;
    }
}

$pertamax   = new Pertamax();
$premium    = new Premium();

$vario_150  = new Kendaraaninjeksi();
$vario_150->terisiPenuh($pertamax);

$astrea     = new Kendaraannoninjeksi();
$astrea->terisiPenuh($premium);
?>
