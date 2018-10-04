#include <iostream>

using namespace std;

int main()
{
    int a,b,c,n;
    cin >> n;
    for(int i = 0; i < n; i++){
    cin >> a;
    b = a % 10;
    while( 10 <= a){
        a = a / 10;
    }
    c = b + a;
    cout << c << endl;
    }


    return 0;
}
