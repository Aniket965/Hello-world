<?PHP

class A {
    function example($a) {
	//throw new Exception("Fatal error.");
        echo $a.", i am A::example() and provide basic functionality.\n";
    }
}

class B extends A {
    function example($a) {
	
        echo $a.", i am B::example() and provide additional functionality.\n"; 
	parent::example($a);
    }
}

$b = new B;

// This will call B::example(), which will in turn call A::example().
$b->example("Hi");
