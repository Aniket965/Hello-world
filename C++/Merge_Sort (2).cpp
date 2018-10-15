#include <iostream>
using namespace std;

void inputArr(int a[], int n){
	for(int i = 0; i<n; ++i){
		cin>>a[i];
	}
}

void outputArr(int a[], int n){
	for(int i = 0; i<n; ++i){
		cout<<a[i]<<" ";
	}
}

void mergeSortedArr(int a[], int beg, int mid, int end){
	int i = beg;
	int j = mid + 1;
	int c[end+1];
	int k=0;
	while(i<=mid && j<=end){
		if(a[i]<a[j]){
			c[k] = a[i];
			++i;
			++k;
		}
		else{
			c[k] = a[j];
			++j;
			++k;
		}
	}
	
		
	while(i<=mid){
		c[k] = a[i];
		++k;
		++i;
	}
	while(j<=end){
		c[k] = a[j];
		++k;
		++j;
	}

	for (int x = beg,y=0; x <= end; ++x,y++)
	{
		a[x]=c[y];
	}

}

void mergeSort(int a[], int beg, int end){
	if(beg>=end){
		return;
	}

	int mid = (beg + end)/2;
	mergeSort(a,beg,mid);
	mergeSort(a,mid+1,end);
	mergeSortedArr(a,beg,mid,end);
}



	


int main(){
	int n;
	 cin>>n;
	 int a[100];
	 inputArr(a,n);
	 mergeSort(a,0,n-1);
	 outputArr(a,n);
}