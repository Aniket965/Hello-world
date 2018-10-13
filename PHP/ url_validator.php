 
<?php
error_reporting(0);
$displayS = "";
?>
<!DOCTYPE html>
<html>
<head>
	<title>Test if a URL is valid</title>
</head>
<body>
<p><?php echo $displayS;?></p>
<form method="POST">
Insert link here: <textarea name="link" rows="1" cols="15"></textarea>
<input type="submit" name="submit" value="Check link">
</form>
<?php
if(isset($_POST['link'])) {
$url = $_POST['link'];
if (!preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i",$url)) {
      echo "<br>Invalid URL";
}
else {
	if(!get_headers($url)) {die("<br>Link does not exist<br>");}
	$returnCode = substr(get_headers($url)[0], 9, 3);
	$returnCode = (int)$returnCode;
	if($returnCode < 600 && $returnCode > 308) {
		die("<br>Link returns error code: ".$returnCode);
	}
	echo "<br>Link is working";
}

}
?>
</body>

</html>
