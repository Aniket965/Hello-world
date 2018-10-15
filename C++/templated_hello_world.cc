#include <iostream>


template<typename ReturnT, typename...  ArgT>
using Function = ReturnT(*)(ArgT...);



void greetWorld() {

std::cout<< "Hello, World!" << std::endl;

};


int main()
try {

Function sayHello = greetWorld;

sayHello();

return EXIT_SUCCESS;
}
catch(...) {

std::clog << "Bye, cruel world!" ;

};
