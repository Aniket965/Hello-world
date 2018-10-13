<?php
require_once 'Bahanbakar.php';
/**
 * class pertamax implements interface Bahanbakar
 */
class Pertamax implements Bahanbakar
{
    private $price;
    private $octane;
    private $name;

    function __construct()
    {
        $this->price    = 9000;
        $this->octane   = 92;
        $this->name     = "Pertamax";
    }

    public function getPrice()
    {
        return $this->price;
    }

    public function getOctane()
    {
        return $this->octane;
    }

    public function getName()
    {
        return $this->name;
    }
}

?>
