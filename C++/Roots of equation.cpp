#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x1,x2,a,b,c,d,e;
    cin >> a;
    cin >> b;
    cin >> c;
     d = (b * b) - 4 * a * c;
     e = sqrt(d);
     x1 = ((-b) + e) / 2 * a;
     x2 =((-b) - e ) / 2 * a;

    cout << x1 << endl;
    cout << x2;
    return 0;
}

