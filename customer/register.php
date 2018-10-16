<!DOCTYPE html>
<?php include 'header.php'; ?>
<html lang="en" dir="ltr">
  <head>
    <link rel="stylesheet" href="css/register.css">
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>

    <form action="action/signupAction.php" method="post">
      <div class="container">
        <div class="container signin">
          <center>
            <h1>Register</h1>
            <p>Please fill in this form to and Be a Part of Oriflame</p>
          </center>
        </div>
        <hr>
        <center>
            <label for="email"><b>Name</b></label>
            <br>
            <input type="text" placeholder="Enter Name" name="name" required>
            <br>
            <label for="email"><b>Email</b></label>
            <br>
            <input type="text" placeholder="Enter Email" name="email" required>
            <br>
            <label for="psw"><b>Password</b></label>
            <br>
            <input type="password" placeholder="Enter Password" name="password" required>
            <br>
            <label for="psw-repeat"><b>Repeat Password</b></label>
            <br>
            <input type="password" placeholder="Repeat Password" name="repassword" required>
            <hr>
            <input type="submit" class="registerbtn" name="submit"></input>
        </center>
      </div>

      <div class="container signin">
        <p>Already have an account? <a href="login.php">Sign in</a>.</p>
      </div>
    </form>

  </body>
</html>
