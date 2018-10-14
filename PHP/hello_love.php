<!DOCTYPE html>
<html>
	<head>
		<title>Hello Love</title>
		<link href="https://fonts.googleapis.com/css?family=Loved+by+the+King" rel="stylesheet">
		<style type="text/css">
			html {
				background: url(http://static.colourlovers.com/images/patterns/1432/1432125.png?1316453497) repeat #BD3038;
				color: #fff; font-family: 'Loved by the King', cursive;	display: grid; align-items: center;
				justify-content: center; height: 100%;	margin: 0;	padding: 30px;	box-sizing: border-box;
				font-size: 50px; text-align: center;
			}
			body {margin: 0;}
			h1 {background: #fff; color: #BD3038; padding: 0px 40px; margin-top: 0;}
			p {background: #FF7E57; color: #220114; padding: 0px 20px;    margin-bottom: 10px;}
			code {background: #220114; display: block; font-size: .4em; padding: 30px;}
		</style>
	</head>
	<body>
		<?php
			if (isset($_GET['world'])) {
				echo "<h1>Hello ".$_GET['world']."!</h1><p>You are my world <3</p>";	
			} else {
				echo "<h1>Hello World</h1><p>Add your love to the url:</p><code>hello_love.php?world=Caio</code>";
			}
		?>
	</body>
</html>

