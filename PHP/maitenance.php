<?php

header('HTTP/1.1 503 Service Unavailable');
header('Retry-After: 300'); // 5 minutes in seconds

?>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="robots" content="noindex">

    <title>Site is temporarily down for maintenance</title>

    <style>
        body { color: #333; background: white; width: 500px; margin: 100px auto }
        h1 { font: bold 47px/1.5 sans-serif; margin: .6em 0 }
        p { font: 21px/1.5 Georgia,serif; margin: 1.5em 0 }
    </style>
</head>
<body>
<h1>We are Sorry</h1>

<p>The site is temporarily down for maintenance.<br />Please try again in a few minutes.</p>
</body>
</html>
