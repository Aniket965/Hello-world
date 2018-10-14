<?php
/**
 * Created by PhpStorm.
 * User: abdullahaaf
 * Date: 30/09/18
 * Time: 8:32
 */
require __DIR__."/vendor/autoload.php";

use App\Controllers\UserController;

$user   = new UserController();
$user->index();
//$file = __DIR__."\n";
//echo $file;
?>