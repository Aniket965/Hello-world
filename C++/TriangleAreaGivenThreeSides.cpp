#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;

    cout << "Insert triangles side: ";
    cin >> a >> b >> c;

    double s = 0.5 * (a + b + c);

    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    cout << area << endl; 

    return 0;
}