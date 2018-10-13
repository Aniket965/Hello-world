#include<iostream>
using namespace std;

int main()
{
	int T;
	int k=0;
	cin>>T;
	int A[T];
	while(T--){
		long long int N;
		cin>>N;
		int x=5;
		int sum=0;
		while(N/x){
			sum+=N/x;
			x=x*5;
		}
		A[k]=sum;
		k++;
	}
	for(int i=0;i<k;++i){
		cout<<A[i]<<endl;
	}
	return 0;
}
