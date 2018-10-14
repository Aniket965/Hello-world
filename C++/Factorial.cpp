#include<iostream>
using namespace std;
int factorial(int n)        //Factorial function
{
    if(n==1 || n==0)
        return 1;
    else
        return n*factorial(n-1);
}
int main()                  //main function
{
    int n;
    cout << "\nEnter a positive integer : ";
    cin >> n;
    cout << "\nThe Factorial of Number " << n << " is = " << factorial(n)<<endl;    //function call
    return 0;
}
