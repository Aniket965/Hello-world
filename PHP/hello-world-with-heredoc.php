<?php
$text = 'Hello World!';
echo <<<HTML
  <!DOCTYPE html>
  <html lang="en">
  <head>
    <meta charset="UTF-8">
    <title>Hello World with heredoc</title>
  </head>
  <body>
    <p>{$text}</p>
  </body>
  </html>
HTML;
