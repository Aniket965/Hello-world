#include <iostream>
#define num 3
#define a 'A'
#define b 'B'
#define c 'C'

int cnt = 0;
using namespace std;

void hannoi(int n, char src, char temp, char dest)
{
	if ( n==1 ) cout << "step" << ++cnt << ":" << src << "-->" << dest << endl;
	else {
		hannoi(n-1,src,dest,temp);
		cout << "step" << ++cnt << ":" << src << "-->" << dest << endl;
		hannoi(n-1,temp,src,dest);
	}
}

int main(int argc, char const *argv[])
{
	hannoi(num,a,b,c);
	return 0;
}