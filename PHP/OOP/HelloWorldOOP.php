<?php

class HelloWorldOOP {

    /**
     * @var string
     */
    private $msg;

    private function __construct($msg) {
        $this->msg = $msg;
    }
    
    public static function createFromMsg($msg) {
        return new self($msg);
    }

    public function __toString() {
        return $this->msg;
    }

}