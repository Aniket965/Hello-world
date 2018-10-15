#include <iostream>
using namespace std;

int linear_search(int A, int n, int s)
{
    int i=0;
    while(i<n)
    {
        if(A[i]==s)
        return i;
        i++;
    }
    return -1;
}
int main() {
	int N,A[N],i,s;
	cin>>N;
	i=0;
	while(i<N)
	{
	    cin>>A[i];
	    i++;
	}
	cin>>s;
    pos=linear_search(A,n,s);
    if(pos==-1)
    cout<<"Element not present in the array";
    else
    cout<<"Element present at position "<<pos+1;
	return 0;
	
}

