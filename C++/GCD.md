```C++
/*
 C++ program to find GCD of given numbers using recursion
 */
#include <iostream>

using namespace std;
 
int gcd(int, int);
 
int main()
{
    int a, b;
 
    cout << "Enter the two numbers to find their GCD: ";
    cin >> a >> b;
    cout << "The GCD of " << a << " and " << b << " is equal to " << gcd(a,b) << "\n";

    return 0;
}
 
int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            return gcd(a - b, b);
        else
            return gcd(a, b - a);
    }

    return a;
}
```
