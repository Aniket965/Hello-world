<?php
require_once 'Bahanbakar.php';

/**
 * class premium implements interface Bahanbakar
 */
class Premium implements Bahanbakar
{
    private $price;
    private $octane;
    private $name;

    function __construct()
    {
        $this->price    = 8000;
        $this->octane   = 82;
        $this->name     = "Premium";
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
