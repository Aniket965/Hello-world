#include "bits/stdc++.h"

using namespace std;

int k=0;

/*Method to sort the array*/
void Counting_Sort(int A[],int B[],int n)    
{
	int C[k];
	for(int i=0;i<k+1;i++)
	{
		C[i]=0;
	}
	for(int j=1;j<=n;j++)
	{
		C[A[j]]++;			    
	}
	for(int i=1;i<=k;i++)
	{
		C[i]+=C[i-1];            
	}
	for(int j=n;j>=1;j--)
	{
		B[C[A[j]]]=A[j];          
		C[A[j]]=C[A[j]]-1;		  
	}
}
int main()
{
	cout<<"Array Size:";
	int n;cin>>n;
	
	int A[n],B[n]; 
	
	for(int i=1;i<=n;i++)        
	{
		cin>>A[i];
		if(A[i]>k)
		{
			k=A[i];              
		}
	}
	Counting_Sort(A,B,n);        
	for(int i=1;i<=n;i++)
	{
		cout<<B[i]<<" ";
	}
	cout<<endl;
	return 0;
}