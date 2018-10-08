#include <iostream>
using namespace std;

int main()
{
    int a,num,b,s=0;
    cout << "\nPlease enter a number";
    cin >> num;
    b = num;
    while( n > 0)
    {
    a = n % 10;
    n = n / 10;
    s = s * 10 + a;
    }
   
    if( b == s){
    cout << "\nit is a palindrome" << endl;
    }
    else{
    cout << "\n it is not a palindrome" << endl;
    }
    return 0;
}
