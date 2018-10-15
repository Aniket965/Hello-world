<?php

class Hacktoberfest {
	public function Hello() {
		$HelloHack = "Hello Hacktoberfest 2k18";
		return $HelloHack;
	}
}

$say = new Hacktoberfest();

?>

<html>
  <head><title>Say hello to the Hacktoberfest 2k18</title></head>
  <body>
    <p><?php echo $say->Hello(); ?></p>
  </body>
</html>
