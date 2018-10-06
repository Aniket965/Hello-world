#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int ulli; 

ulli gcd(ulli x, ulli y){
	if( x<0 ) x = -x;
    if( y<0 ) y = -y;
    while( y!=0 ){
        x %= y;
        if( x==0 ) return y;
        y %= x;
    }
    return x;
}

int main() {
	ulli a, b, x, y, gcdiv;
	cin>>a>>b>>x>>y;
	
	gcdiv = gcd(x, y);
	
	x /= gcdiv;
	y /= gcdiv;
	
	cout<<min(a / x, b / y);

	return 0;
}