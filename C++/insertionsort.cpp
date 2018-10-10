#include <iostream>
using namespace std;

int main(){
	int a[10];
	cout<<"Enter 10 Numbers to Sort:";
	for(int i=0; i<10; i++) cin>>a[i];
	
	for(int i=1; i<10; i++){
		for(int j=i; j>0; j--){
			if(a[j]<a[j-1]) swap(a[j],a[j-1]);
			else break;
		}
	}

	cout<<endl<<"Sorted Result: "<<endl;
	for(int i=0; i<10; i++) cout<<a[i]<<" ";
}


void swap(int *a, int *b){
	int *swap;
	swap=a;
	a=b;
	b=swap;
}