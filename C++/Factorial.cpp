#include<iostream>
using namespace std;

int main()
{
    int n,fact;
    cout << "Enter a positive integer: ";
    cin >> n;
    fact=n;
    if(n<=0)
    {
        cout<<"invalid number";
        return 0;
    }   
    label:
    fact*=(n-1);
    n-=1;
    if(n>0)
        goto label;
    cout << "Factorial of " << n << " = " << fact<<endl;
    return 0;
}
