<?php
	$db=mysqli_connect("localhost","root",'');
	mysqli_select_db($db,'customer');

	$name = $_POST["name"];
	$email = $_POST["email"];
	$password= $_POST["password"];
  $repassword= $_POST["repassword"];
	$type = "Customer";

	if($_POST["submit"]) {
		$sql = "INSERT INTO users VALUES (0,'$name','$email','$password','$type')";

		if(mysqli_query($db,$sql)) {
			echo "Done";
			header("location: ../home.php");
		}
		else {
			header("location: ../login.php");
		}
	}
?>
