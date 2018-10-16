<?php

  class helloWord {
    public $a = "hello";
    public $b = "word";

    public function helloword(){
      return "{$this->a} {$this->b}";
    }

  }

    $hello = new helloword();

    echo $hello->helloWord();




?>
