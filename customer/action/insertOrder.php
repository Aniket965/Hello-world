<?php
	$db=mysqli_connect("localhost","root",'');
	mysqli_select_db($db,'customer');

	$store = $_POST["store"];
	$itemName = $_POST["itemname"];
	$itemCode= $_POST["itemc"];
  $customerName= $_POST["cname"];
  $customerEmail = $_POST["cemail"];
  $q=$_POST["quantity"];
	$quantity = (int)$_POST["quantity"];
  $price=(int)$_POST["price"];
  $payment=(string)($price*$quantity);
  $cno=$_POST['cno'];
  $address=$_POST['address'];
	if($_POST["submit"]) {
		$sql = "INSERT INTO customerorders VALUES (0,'$store','$itemCode','$itemName','$customerName','$customerEmail','$cno','$address','$q','$payment',0)";

		if(mysqli_query($db,$sql)) {
			echo "Done";
      header("location: ../home.php");
		}else{
		echo $store;
    echo $payment;
    echo $quantity;
	}
}
?>
