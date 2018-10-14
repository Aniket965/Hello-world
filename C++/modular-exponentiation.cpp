#include <iostream>

///(a*b)%m = [(a%m)*(b*m)]%m

using namespace std;

long long modularExp(int a,long b,int m){

    if(b==0)return 1;

    if(b%2==0)  //even power
    {
        long long y = modularExp(a,b/2,m);
        return (y*y)%m;
    }
    //else odd
    return ((a%m)*modularExp(a,b-1,m))%m;

}

int main()
{

    int t;
    cin>>t;
    while(t-- > 0){

        int a;
        long long b;
        cin>>a>>b;

        long long ans = modularExp(a,b,10);
        cout<<ans<<endl;

    }

}
