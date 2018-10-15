#include <iostream>

#include <cstring>

using namespace std;


int main() {

	
	int n; 

	cout<<"Number of integers :"<<"\n";
	
	cin>>n;
	
	//max is the maximum element in a[] 
	int a[n],max=0,c[n];
	
	for(int i=0;i<n;i++){
		
		cin>>a[i];
		
		if(max < a[i]){
			
			max =a[i];
		
		}
	
	}
	
	// b[] is used to keep count orrurances of each element of a[]
	int b[max+1];
	
	memset(b,0,(max+1)*sizeof(int));
	
	for(int i=0; i<n; i++){
		
		b[a[i]]++; 
	
	}
	
	for(int i=1;i<=max;i++){
		
		b[i]+=b[i-1];
	
	}
	
	//Store elements in sorted order in c[] using their orrurance count in b[] 
	for(int i=0; i<n; i++){
		
		c[b[a[i]]-1]= a[i];

		b[a[i]]--;

	}

	cout<<"Sorted array :"<<"\n";

	for(int i=0; i<n; i++){

		cout<<c[i]<<" ";

	}
	
	cout<<"\n";

	
return 0;

}
