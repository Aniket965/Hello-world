#include <iostream> // Imports Standard Library "iostream" which is used for input and output

using namespace std; // Removes the need for using std::

int factorial (int n) // Defining a function factiorial which takes an integer as an argument and returns an integer
{
    if(n==1)
    {
        return 1;
    }
    return n*factorial(n-1); // Recursive Function which calls itself with an argument with integer one less in value until it reaches one

}
int main()
{
    int n,result; 
    cout<<"Enter the number whose factorial you want to find: ";
    cin>>n;//Takes input for the value n 
    result=factorial(n); //Calls factorial with argument n and assigns its return value to result
    cout<<"The result is \n";
    cout<<result;
    return 0;

}
