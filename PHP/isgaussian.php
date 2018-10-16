<?php
$startX = $startY = 0;
fscanf(STDIN, "%d %d\n", $startX, $startY);

if (checkIfGauss($startX,$startY)) {
    echo "Yes\n";
} else {
    echo "No\n";
}

function checkIfGauss($x, $y) {
    if (($x == 0) && ($y != 0)) {
        if ((checkIfPrime(abs($y))) && (abs($y) % 4 == 3)) {
            return true;
        } else {
            return false;
        }
    } else if (($x != 0) && ($y == 0)) {
        if ((checkIfPrime(abs($x))) && (abs($x) % 4 == 3)) {
            return true;
        } else {
            return false;
        }
    } else if (($x != 0) && ($y != 0)) {
        if (checkIfPrime(($x ** 2) + ($y ** 2))) {
            return true;
        } else {
            return false;
        }
    }
}

function checkIfPrime($a) {
    if ($a == 1) return false;
    if ($a == 2) return true;
    if ($a % 2 == 0) return false;

    for ($i = 3; $i <= ceil(sqrt($a)); $i += 2) {
        if ($a % $i == 0) return false;
    }

    return true;
}
?>
