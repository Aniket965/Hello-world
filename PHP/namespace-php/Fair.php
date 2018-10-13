<?php
/**
 * Created by PhpStorm.
 * User: abdullahaaf
 * Date: 30/09/18
 * Time: 10:47
 */

namespace NiceWeather;

use BadWeather\Storm;

include 'Storm.php';
include 'Sunny.php';

class Fair
{
    public function __construct()
    {
        $storm  = new Storm();
        $sunny  = new Sunny();
    }
}