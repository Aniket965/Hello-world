#include<bits/stdc++.h>
using namespace std;
int binsearch(int arr[],int s,int e,int k){
    if(s>e)
        return -1;
        
    int mid = (s+e)/2;
    if(arr[mid]==k)
        return mid;
    
    if(arr[s]<=arr[mid]){
        if(k>=arr[s]&&k<=arr[mid])
            return binsearch(arr,s,mid-1,k);
        
        return binsearch(arr,mid+1,e,k);
    }
    
    if(k<=arr[e]&&k>=arr[mid])
        return binsearch(arr,mid+1,e,k);
    
    return binsearch(arr,s,mid-1,k);
        
}
int main()
{
	int t;
	cin>>t;
	while(t-->0){
	   int n,arr[100005],k;
	   cin>>n;
	   for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	   cin>>k;
	   cout<<binsearch(arr,0,n-1,k)<<"\n";
    }
}