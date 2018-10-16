<!DOCTYPE html>
<?php include 'header.php'; ?>
<html lang="en" dir="ltr">
  <head>
    <link rel="stylesheet" href="css/register.css">
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>

    <form action="action/loginCheck.php" method="post">
      <div class="container">
        <div class="container signin">
          <center>
            <h1>Login</h1>

          </center>
        </div>
        <hr>
        <center>
            <label for="email"><b>Email</b></label>
            <br>
            <input type="text" placeholder="Enter Email" name="email" required>
            <br>
            <label for="psw"><b>Password</b></label>
            <br>
            <input type="password" placeholder="Enter Password" name="password" required>
            <br>
            <hr>
            <input type="submit" class="registerbtn" name="submit"></input>
        </center>
      </div>

      <div class="container signin">

      </div>
    </form>

  </body>
</html>
