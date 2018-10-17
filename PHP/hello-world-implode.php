<?php
	$helloWorld = "Hello, World";
	echo implode(array_map(function ($a) { return $a; }, (array)$helloWorld)).PHP_EOL;
