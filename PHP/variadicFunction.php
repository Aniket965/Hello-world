<?php
function variadicFunction($operands)
{
  $sum = 0;
  foreach($operands as $singleOperand) {
    $sum += $singleOperand;
  }
  return $sum;
}
echo variadicFunction(1,2); // 3
echo variadicFunction(1,2,5); // 8
?>
