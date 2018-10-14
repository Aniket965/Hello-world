#include <iostream>
using namespace std;

int main()
{
    int a,num,b,s=0;
    cout << "\nPlease enter a number";
    cin >> num;
    b = num;
    rev=0
    while( num > 0)
    {
    rem = num % 10;
     rev = (rev * 10) + rem;
    num= num / 10;
   
    }
   
    if( b == rev){
    cout << "\nit is a palindrome" << endl;
    }
    else{
    cout << "\nit is not a palindrome" << endl;
    }
    return 0;
}
