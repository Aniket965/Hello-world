<?php
    session_start();
    $username = "";
    $email = "";
    $department = "";
    $semester = "";
    $subject = "";
    $date = "";
    $admin="";
    $password="";
    $data="";
    $errors = array();
    // connect to the databse
    $db = mysqli_connect('localhost','root','','appointment');

    // if the register button is clicked
    if (isset($_POST['appoint'])){
        $username = mysqli_real_escape_string($db, $_POST['username']);
        $department = mysqli_real_escape_string($db, $_POST['department']);
        $email = mysqli_real_escape_string($db, $_POST['email']);
        $semester = mysqli_real_escape_string($db, $_POST['semester']);
        $subject = mysqli_real_escape_string($db, $_POST['subject']);
        $date = mysqli_real_escape_string($db, $_POST['date']);

    //ensure that form fields are filled properly
    if(empty($username)){
        array_push($errors, "username is required"); // add error to errors array
    }
    
    if(empty($department)){
        array_push($errors, "Department is required"); // add error to errors array
    }
    if(empty($email)){
        array_push($errors, "E-mail is required"); // add error to errors array
    }   
    
    if(empty($semester)){
        array_push($errors, "Semester is required"); // add error to errors array
    }    
    
    if(empty($subject)){
        array_push($errors, "Subject is required"); // add error to errors array
    }

    $today=date("Y-m-d");
    if(empty($date)){
        array_push($errors, "Date is required");
        $date=$today; // add error to errors array
    }


    
    if($date<$today)
    {
        array_push($errors, "Booking for this date is'nt available");
    }

    $diff = abs(strtotime($date) - strtotime($today)); 

    $years   = floor($diff / (365*60*60*24)); 
    $months  = floor(($diff - $years * 365*60*60*24) / (30*60*60*24)); 
    $days    = floor(($diff - $years * 365*60*60*24 - $months*30*60*60*24)/ (60*60*24));
    if($days>6)
    {
        array_push($errors, "Booking for this date is'nt available");
    }

    $rr="SELECT * FROM appointments WHERE date='$date'";
    $result=mysqli_query($db,$rr);
    // Return the number of rows in result set
    $rowcount=mysqli_num_rows($result);

    if($rowcount>5)
    {
        array_push($errors, "Booking for this date is already full");
    }


    if(date('D', strtotime($date)) == 'Sat' || date('D', strtotime($date)) == 'Sun') { 
        array_push($errors, "Booking isnt available for this date");
    } 



    //if there are no errors, save user to database
    if(count($errors)==0){
        $sql = "INSERT INTO appointments (username, email, department, semester, subject, date)
                VALUES ('$username', '$email', '$department', '$semester', '$subject', '$date')";
        mysqli_query($db, $sql);
        $_SESSION['username']=$username;
        $_SESSION['success']="You are now logged in";
        header('location: index.php'); //redirect to home page
    }

}

    //log user in from login page
    if(isset($_POST['login'])){
        $admin = mysqli_real_escape_string($db, $_POST['admin']);
        $password = mysqli_real_escape_string($db, $_POST['password']);


    //ensure that form fields are filled properly
    if(empty($admin)){
        array_push($errors, "username is required"); // add error to errors array
    }
    
    if(empty($password)){
        array_push($errors, "Password is required"); // add error to errors array
    } 
    if(count($errors)==0){
        $password=md5($password);
        $query = "SELECT * FROM adminuser WHERE admin='$admin' AND password='$password'";
        $result=mysqli_query($db, $query);
        if(mysqli_num_rows($result)==1){
            //log user in
            $_SESSION['admin']=$admin;
            $_SESSION['success']="You are now logged in";
            header('location: admin.php'); //redirect to home page            
        }else{
            array_push($errors, "Wrong username/password combination");
        }
    }        
    }



    //logout
    if(isset($_GET['logout'])){
        session_destroy();
        unset($_SESSION['username']);
        header('location: index.php');
    }


?>