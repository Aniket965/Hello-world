<?php
  $regex = '/(he(l)+o+)\s*(world)/i';
  $arrayOfHW = [
    'hello world',
    'Hello World',
    'hellllloooooo world',
    'H3LL0 W0RLD'
  ];
  
  foreach ($arrayOfHW as $helloWorld) {
    if (preg_match($regex, $helloWorld)) {
      echo $helloWorld . PHP_EOL;
    }
  }
