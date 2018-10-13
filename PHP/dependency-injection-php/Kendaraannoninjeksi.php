<?php
class Kendaraannoninjeksi
{
    private $bbm;

    public function terisiPenuh(Bahanbakar $bbm)
    {
        $string = "Kendaraan non-injeksi terisi penuh dengan bahan bakar {$bbm->getName()}";
        $string .= " dengan oktan {$bbm->getOctane()}";
        $string .= " dan dengan harga {$bbm->getPrice()} per liter \n";

        echo $string;
    }
}
?>
