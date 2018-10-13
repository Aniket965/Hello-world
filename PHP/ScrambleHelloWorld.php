<?php
/**
* Josh F. (https://github.com/joshfedo)
 */


$goal = "Hello World!";
$values = range('!','~');
$values[] = ' '; //add space to values
$goalLen = strlen($goal);
$guess = array_fill(0,$goalLen,'0');
$goal = str_split($goal);
while($guess != $goal){
	$wrong = 0;
	for($i = 0; $i < $goalLen; $i++){
		if($goal[$i] != $guess[$i]){
			$wrong++;
			$guess[$i] = $values[rand(0,count($values)-1)];
		}
	}
	$percentComplete = 100 - round(($wrong / $goalLen),2)*100;
	echo implode($guess) . " $percentComplete% Solved \r";
	usleep(20000);
}
echo implode($guess) . "                   \r";
