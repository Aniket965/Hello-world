//find the sum of the even-valued fibonacci terms upto 4 million.
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int sum=0, x=1, y=2;
	
	while(x<=4000000)// 4,000,000 . does not exceed---> <=
		{
			sum+= (x%2==0)?x:0;
			int z= x+y;
			x=y;
			y=z;
		}
	
	 cout<<sum<<"\n";
	
	return 0;
}


/***

Note.

F(n)= F(n-1)+ F(n-2);
E(n)= 4E(n-1)+ E(n-2);// Even number Fibonacci Series
