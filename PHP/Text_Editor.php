<!--- Made with love by Saksham Saxena--->
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
	<title>Txt Maker</title>
	<!--- Fonts from Google Fonts --->
	<link href="https://fonts.googleapis.com/css?family=Raleway" rel="stylesheet">
	<link href="https://fonts.googleapis.com/css?family=Jua" rel="stylesheet">
</head>
<!--- CSS Styling --->
<style>
	body{
		background-color:#c7d8cf;
		box-shadow: 5px 5px 5px grey;
	   }
	#title{
		font-family: 'Jua', sans-serif;
		text-align: center;
		padding: 20px;
		border: dashed;
		border-radius: 20px;
		background-color: #01f774;
		box-shadow: 5px 5px 5px grey;
	   }
	#Workarea{
		width:100%;
		height:100%;
		font-family: 'Raleway', sans-serif;
        font-size: 20px;
		box-shadow: 5px 5px 5px grey; 
	      }
	p{
	font-family: 'Jua', sans-serif;
	font-size: 25px;
	     }
	button{
		border-radius: 10px;
		background-color: #f2f2f2;
		height: 50px;
		width: 100px;
		font-size: 35px;
		font-family: 'Jua', sans-serif;
		box-shadow: 5px 5px 5px grey;
	     }
	textarea{
		border-width:5px;
		border-radius: 5px;
	    }
	input{
		height: 50px;
		width: 200px;
		font-size: 30px;
		font-family: 'Raleway', sans-serif;
		border-radius: 7px;
		border-bottom-width: 1px;
		border-color: black;
	      }
</style>
<body>
	<h1 id="title">Txt Maker</h1>
	<div id="Form">
		<!--- User input area --->
<form action="Text_Editor.php" method="post">
	<p>Enter File Name: <input type="text" name="Filename">   <button type="submit" onclick = "<?php SaveFile(); ?>">Save</button></p>

	</div>
	<textarea rows="4" cols="50" type="text" placeholder="Enter Text Here......" name="User" id="Workarea" multiline="true"></textarea>
	<br/>
	</form>
<!--- Backend (PHP) Begins --->
<?php
/* Function to save a file */
function SaveFile(){
	if (isset( $_POST['User'])){
$Text = $_POST['User'];
$filename = $_POST['Filename'];
/* Check if any of the field id empty while saving */
if(empty($Text)){
	echo ("Text is Empty");
}
elseif(empty($filename)){
	echo ("File Name is Empty");
}

/* If Everything is fine , it will create a connection and save the file */
else{
	$Filelink = fopen ($filename.".txt",'w+') or die("Cannot Open File");
	fwrite($Filelink, $Text);
	
	fclose ($Filelink);
	echo ("File Saved");
	}
	}
}

?>
</body>

</html>
