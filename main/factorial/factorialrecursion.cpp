#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
        return 1;
    
    else
        return n * factorial(n - 1);
}

void main()
{
    int i;
    cout << "Enter a natural number:\n\n";
    cin >> i;
    cout << i << "!\t=\t" << factorial(i) << endl;

}
