<?php

class HelloThere
{
    public function getHelloMessage()
    {
        return 'Hello HacktoberFest 2k18!';
    }
}

$hello = new HelloThere();

echo $hello->getHelloMessage();
