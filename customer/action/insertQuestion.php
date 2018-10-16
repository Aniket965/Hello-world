<?php
	$db=mysqli_connect("localhost","root",'');
	mysqli_select_db($db,'customer');

	$store = $_POST["store"];
	$itemName = $_POST["itemname"];
	$itemCode= $_POST["itemc"];
  $customerName= $_POST["cname"];
  $customerEmail = $_POST["cemail"];
	$question = $_POST["question"];
	if($_POST["submit"]) {
		$sql = "INSERT INTO question VALUES (0,'$store','$itemCode','$itemName','$customerName','$customerEmail','$question',0)";

		if(mysqli_query($db,$sql)) {
			echo "Done";
      header("location: ../home.php");
		}
		else {
			echo "fail";
		}
	}
?>
