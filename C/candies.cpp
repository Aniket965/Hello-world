#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int courn=0;
    while(n>0)
    {
        n-=n/10;
        courn++;
    }
    cout<<courn<<endl;
    return 0;
}
