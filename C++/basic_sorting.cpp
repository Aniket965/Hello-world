//The STL or the Standard Template library allows to use the power of inbuilt functions in C++ 

/* There are four part or say pillars of STL

ALgorithms 
Containers
Itterators 
and functions */

// For example to SORT AN ARRAY 

#include <bits/stdc++.h>
using namespace std;

int main(){

	long long int n,i; //size of array
	cin>>n;
	long long int a[n];

	// ARRAY input
	for(i=0;i<n;i++){
		cin>>a[i];
	}

	// To sort an array 
	sort(a,a+n);

	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	


	return 0;
}