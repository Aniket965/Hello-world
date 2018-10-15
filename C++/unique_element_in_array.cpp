#include <iostream>
using namespace std;

int main() {
	int N,A[N],i,c;
	cin>>N;
	i=0;
	while(i<N)
	{
	    cin>>A[i];
	    i++;
	}
	c=0;
	i=0;
	while(i<N)
	{
	    c=c^A[i];
	    i++;
	}
	cout<<"THE UNIQUE ELEMENT IN ARRAY IS : "<<c;
	return 0;
}

