<?hh

namespace Hack\UserDocumentation\Callables\SpecialFunctions\Examples\LambdaPP;

class Hello {
  public function dump(): void {
    $vec = Vector { 'Hello', 'Blue_World!' };
    \var_dump($vec->map($in ==> $this->wrap($in)));

    // This is not allowed because inst_meth() can not access private methods
    // var_dump($vec->map(inst_meth($this, 'wrap')));
  }

  private function wrap(string $in): string {
    return '|[x]| '.$in.' |[x]|';
  }
}

function main() {
  (new Hello())->dump();
}

main();

// Output 
// ----------
// object(HH\Vector)#4 (2) {
//  [0]=>
//  string(17) "|[x]| Hello |[x]|"
//  [1]=>
//  string(23) "|[x]| Blue_World! |[x]|"
// }
