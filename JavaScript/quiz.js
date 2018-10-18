<!DOCTYPE html>
<html>
<head>
	<!-- BOOTSTRAP -->
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
	
	<meta name="viewport" content="width=device-width,height=device-height,initial-scale=1.0"/>
	<title>Quiz</title>
	<style type="text/css">
		.container {
			width:device-width;
			height:device-height;
			background-image: url("https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ8p-NxWmvV37-sh1rwzijCz6GCPyCs5MQojyii6nl9YXlyhRsg");
		}
		.main {
			height:400px;
			margin-top:50px;
			width:55%;
			align-items: center;
			margin-left:250px;
			border-style: solid;
			border-width: 3px;
			
			background-color: #3a8;
			display: inline-block;
			overflow-y: scroll;
		}
		.results {
			height:50px;
			margin-top:20px;
			width:55%; 
			margin-left:250px;
			text-align: center;
		}
		.questions{
			height:100px;
			width: 500px;
			margin-left:30px;
			margin-top: 30px;
			display: inline-block;
		}
	</style>
</head>
<body style="background-color: black;">
	<h1 style = "text-align: center; margin-top:20px; color:blue"><b><i><u>QUIZ</u></i></b></h1>
<div class = "container">
<div class = "main">
	<div class = "questions" name = "ques1">
		<p><b>Q1. </b>C++ was designed by ?</p>
		A. <input type="radio" id="q1a" value = "A" name = "Q1">James Gosling<br>
		B. <input type="radio" id="q1b" value ="B" name="Q1">Dennis Ritchie<br>
		C. <input type="radio" id="q1c" value ="C" name ="Q1">Bjarne Stroustrup<br>
		<hr>
	</div>

	<div class = "questions" name="ques2" >

		<p><b>Q2. </b>Java was designed by?</p>

		A. <input type="radio" name="q2" value = "A" id = "q2a">James Gosling<br>
		B. <input type="radio" name="q2" value = "B" id = "q2b">Dennis Ritchie<br>
		C. <input type="radio" name="q2" value = "C" id = "q2c">Guido van Rossum<br>
		<hr>

	</div>

	<div class = "questions" name="ques3">

		<p><b>Q3. </b>C was designed by?</p>

		A. <input type="radio" name="q3" value = "A" id = "q3a">Brendan Eich<br>
		B. <input type="radio" name="q3" value = "B" id = "q3b">Dennis Ritchie<br>
		C. <input type="radio" name="q3" value = "C" id = "q3c">James Gosling<br>
		<hr>

	</div>

	<div class = "questions" name="ques4">

		<p><b>Q4. </b>Python was designed by?</p>
		
		A. <input type="radio" name="q4" value = "A" id = "q4a">Guido van Rossum<br>
		B. <input type="radio" name="q4" value = "B" id = "q4b">Bjarne Stroustrup<br>
		C. <input type="radio" name="q4" value = "C" id = "q4c">Brendan Eich<br>
		<hr>

	</div>

	<div class = "questions" name="ques5">

		<p><b>Q5. </b>Javascript was designed?</p>

		A. <input type="radio" name="q5" value = "A" id = "q5a">Guido van Rossum<br>
		B. <input type="radio" name="q5" value = "B" id = "q5b">Brendan Eich<br>
		C. <input type="radio" name="q5" value = "C" id = "q5c">James Gosling<br>

	</div>
	
</div>
<div class = "results">
	<button type = "submit" onclick="showResults()" style = "margin-top: 0px;">FINISH QUIZ</button>
</div>
</div>

<script type="text/javascript">
		//	Javascript Code. //
		function showResults() {
			var score = 0; 
	
			if (document.getElementById('q1c').checked) score ++; // Option C is correct
			if (document.getElementById('q2a').checked) score ++; // Option A is correct
			if (document.getElementById('q3b').checked) score ++; // Option B is correct 
			if (document.getElementById('q4a').checked) score ++; // Option A is correct
			if (document.getElementById('q5b').checked) score ++; // Option B is correct

			var perc = score*100;
			perc /= 5;

			window.alert("YOUR SCORE: "+score+"/5" + " "+perc+" %");
		}
		
</script>
</body>
</html>
