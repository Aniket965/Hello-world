<!DOCTYPE html>
<?php
 require_once('auth.php');
 ?>
<?php
$db=mysqli_connect("localhost","root","") or die ("Error Occures");
mysqli_select_db($db,"customer") or die("Error Occures");
$type=$_POST['store'];
$itemn=$_POST['itemname'];
$itemc=$_POST['itemcode'];
$price=$_POST['price'];

?>

<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="css/register.css">
    <title>Quick Buy</title>
  </head>
  <body>
    <form action="action/insertOrder.php" method="post">
      <div class="container">
        <div class="container signin">
          <center>
            <h1>Quick Buy</h1>
            <p>Place your Order with Correct details</p>
          </center>
        </div>
        <hr>
        <center>
            <label for="email"><b>Store Type</b></label>
            <br>
            <input type="text" placeholder="Enter Store" value ="<?php echo $type;?>" name="store" readonly>
            <br>
            <label for="email"><b>Item Name</b></label>
            <br>
            <input type="text" placeholder="Enter ItemName" name="itemname" value="<?php echo $itemn; ?>" readonly>
            <br>
             <input type='hidden' name='price' value=<?php echo $price; ?>>
            <input type="hidden" name="itemc" value="<?php echo $itemc; ?>">
            <input type="hidden" name="cname" value="<?php echo $_SESSION['name']; ?>">
            <input type="hidden" name="cemail" value="<?php echo $_SESSION['email']; ?>">
            <br>
            <label for="Quantity"><b>Quantity</b></label>
            <br>
            <input type="number" placeholder="Enter Quantity" name="quantity"  required>
            <br>
            <label for="contactNumber"><b>Contact Number</b></label>
            <br>
            <input type="text" placeholder="Enter Phone NUmber" name="cno"  required>
            <br>
            <label for="psw"><b>Delivery Address</b></label>
            <br>
            <textarea type="text" placeholder="Enter your Question" name="address" required></textarea>
            <hr>
            <input type="submit" class="registerbtn" name="submit" value="Order Now"></input>
        </center>
      </div>
    </form>
  </body>
</html>
