<?php
/*
Filename : HelloWorldArray.php
Author : JanuriDP
Desc : Print Hello World in Array
*/

// Indexed Arrays and start from 1
$text = array('1' => 'Hello', 'World');

// Get The Length of an Array 
$count = count($text);

echo "<pre>";
print_r($text);
echo "</pre>";

// Print with array index
echo $text[1].$text[2];
echo "<br>";

// Print array with foreach
foreach ($text as $word) {
	echo $word;
}
echo "<br>";

// Loop Through an Indexed Array
for ($i=1; $i < $count; $i++) { 
	echo $text[$i];
}

?>
