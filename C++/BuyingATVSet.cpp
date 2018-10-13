#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int ulli; 


int main() {
	ulli a, b, x, y, gcdiv;
	cin>>a>>b>>x>>y;
	
	gcdiv = __gcd(x, y);
	
	x /= gcdiv;
	y /= gcdiv;
	
	cout<<min(a / x, b / y);

	return 0;
}
