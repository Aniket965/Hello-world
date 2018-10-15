#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
long N,num,p,q,r=0;
cin>>N;

for(int i=0;i<N;i++)
{
    cin>>num;
    p=(num-1)/3;
    q=(num-1)/5;
    r=(num-1)/15;

    cout << 3*(p*(p+1)/2)+5*(q*(q+1)/2)-15*(r*(r+1)/2)<<endl;

}
return 0;
}
