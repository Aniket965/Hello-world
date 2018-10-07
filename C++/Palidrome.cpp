#include <iostream>
using namespace std;
int palindrome(int n)
{
     while( n > 0){
    a = n % 10;
    n = n / 10;
    s = s * 10 + a;
    }
    return s;
}
int main()
{
    int a,n,b,s=0;
    cout << "Please enter a number" << endl;
    cin >> n;
    b = n;
   s=palindrome(n);
    if( b == s){
    cout << "Yes" << endl;
    }
    else{
    cout << "No" << endl;
    }
    return 0;
}
