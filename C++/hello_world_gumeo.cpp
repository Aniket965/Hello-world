// This is a single line comment in C++

/*
  This is a multi-line comment!
  In order to print something in C++ we will use the iostream header
*/
#include <iostream>

// We will use the namespace std, i.e. the standard library namespace
// to avoid needing to declare from which namespace these objects or functions come from.

using namespace std;

// Now we declare the main function, which is the entry-point for the operating system to the program
// Note that the return type of main is int, meaning that it returns an integer to the caller, where
// a return value of 0 means that everything went ok

int main(){
  // We use cout from iostream to print to the standard output
  // endl prints a newline for us
  cout << "Hello World!" << endl;
  return 0;
}
