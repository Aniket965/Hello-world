//https://www.geeksforgeeks.org/count-divisors-n-on13/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A;
	cin>>A;
int cnt = 0;
    for (int i = 1; i <= sqrt(A); i++) 
	{
        if (A % i == 0) {
            // If divisors are equal,
            // count only one
           //we are doing square root(A) so we are excluding numbers greater than its sqaure root
           //so what we will do we will divide the number with a i then new ans will be also a divisor
           //ex 100/1=100 so here 1 and 100 both are divisors ex 100/2=50 both 2 and 50 are divisors.
            if (A / i == i)
             {
             	
				   cnt++;
			 }
            else // Otherwise count both
               {
               	 //ex 100/2=50 so 2 and 50 both are divisors. 
				 cnt = cnt + 2;
			   }
        }
    }
    cout<<cnt;
	
}
