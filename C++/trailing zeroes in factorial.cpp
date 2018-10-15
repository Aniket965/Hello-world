//find no of trailing zeroes in a factorial of a number
#include<bits/stdc++.h>
using namespace std;

int main()
{
	    int A;
	    cin>>A;
        int count = 0;
        //count no of 10 in factorial
        //for this we have to find number of 10 or multiple of 10 in factorial(2*5) so we can find just 5 theres because its big
        //so check whether a given number is a multiple of 10 or not or multiple of 5 also
        for (int n = 1; n <= A; n++) {//finding factorial
            int m = n;
            while (m % 10 == 0) {
                count++;
                m /= 10;
            }
            while (m % 5 == 0) {
                count++;
                m /= 5;
            }
        }
        cout<<count;
}
