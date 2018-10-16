#include<iostream>
using namespace std;
class factorial{
    int f,n;
    public:
    int fact();
};
int factorial::fact()
{
    f=1;
    std::cout<<"\nEnter a Number:";
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}
int main()
{   int fact;
    factorial ob;
    fact=ob.fact();
    std::cout << "factorial is: "<<fact<<endl;
    return fact;
}
