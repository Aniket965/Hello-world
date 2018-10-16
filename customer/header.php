<!DOCTYPE html>
<?php
error_reporting(0);
 ?>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="css/navigation.css">
    <title>Oriflame Sweden</title>
    <center>
      <h1>Oriflame Sweden</h1>
    </center>
  </head>

  <body>
    <ul>
      <li><a class="active" href="home.php">Home</a></li>
      <li><a href="skincare.php">Skin-Care</a></li>
      <li><a href="makeup.php">Make-Up</a></li>
      <li><a href="fragrance.php">Fragrance</a></li>
      <li><a href="body.php">Bath & Body</a></li>
      <li><a href="hair.php">Hair</a></li>
      <li><a href="wellness.php">Wellness</a></li>
      <li><a href="men.php">Men</a></li>
      <li><a href="Men">About</a></li>
      <li><a href="Men">Contact Us</a></li>
      <?php
        session_start();
        if($_SESSION['auth']=='a'){
          error_reporting(0);
          //echo "<li class='logSign'>".$_SESSION['name']."</li>";
          echo "<li class='logSign'><a href='action/logout.php'>LogOut</a></li>";
          echo "<li class='logSign'><a>".$_SESSION['name']."</a></li>";

       }else{
         echo "<li class='logSign'><a href='register.php'>SignUp</a></li>";

         echo "<li class='logSign'><a href='login.php'>Login</a></li>";
       }
       ?>

    </ul>


  </body>
</html>
