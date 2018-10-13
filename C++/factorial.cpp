#include<iostream>
using namespace std;
int main()
{
    int n, fact = 1;
    cout << "Enter a positive integer: ";
    cin >> n;
    for(int i = n; i > 1; i--)
        fact = (fact * i) % 1000000007;
    cout << "Factorial of " << n << " = " << fact << endl;
    return 0;
}
