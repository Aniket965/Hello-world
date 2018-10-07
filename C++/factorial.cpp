#include<bits/stdc++.h>

using namespace std;

map<int,int> f;

int fact(int n){

	if(n==1 || n==0)
		return 1;
	else if(f[n])
		return f[n];
	else
		return f[n]=n*fact(n-1);
}

int main(){
	cout<<fact(5);
}
