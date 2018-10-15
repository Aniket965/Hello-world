#include <iostream>
using namespace std;
int count = 0;

void hanoi(int n, int source, int dest, int helper){

	if(n==0){
		return;
	}
	hanoi(n-1,source,helper,dest);
	cout<<"Move "<<n<<"th disc from T"<<source<<" to T"<<dest<<endl;
	hanoi(n-1,helper,dest,source);
	count++;


}

int main(){
	int n;
	cin>>n;
	hanoi(n,1,2,3);
	cout<<count;
}