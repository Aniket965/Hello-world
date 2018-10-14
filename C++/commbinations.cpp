//This program is used to find the numbers  of possible Combinations
/*
This program repeatedly reads in a non-negative integer N followed by a second non-negative integer K, and prints out the number of ways you can choose K items from among N total items. We call this "N-choose-K", and the formula for "N-choose-K" is:

N! / (K! * (N-K)!)


Input Format:
The input consists of two integers N and K respectively.


Output Format:
The output contains a single integer indicating the result given the integers N and K.
*/
#include <iostream>

using namespace std;

double fact(double x)       //function to find factorial 
{   double r=1;
    while(x!=1)
    {
        r*=x;
        x--;
        fact(x);
    }
    return r;
}
int main() {
    double a[2],s;
    cin>>a[0]>>a[1];                //a[0] is N & a[1] is K
    if(a[1]<=a[0] && a[1]>=0)
    {
        cout<<fact(a[0])/(fact(a[1])*fact(a[0]-a[1]));
    }
    else cout<<0;
}

