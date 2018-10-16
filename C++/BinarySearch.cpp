#include<iostream>
using namespace std;
bool BinarySearch(int arr[], int n, int k){
    int s=0;int e=n-1;
    while (s<=e){
        int mid=(s+e)/2;
        if (arr[mid]==k) return true;
        if (arr[mid]<k){
            s=mid+1;
        } else {
            e=mid-1;
        }
    }
    return false;
}

int main(){
    int n,target;
	cout<<"Enter the size of the array"<<endl;
	int arr[n];
	cout<<<"Enter elements of the array"<<endl;
	for (int i=0;i<n;i++) cin>>arr[i];
	cout<<"enter the number you want to search";
	cin>>target;
	if(BinarySearch(arr,n,target) cout<<"The number exists"<<endl;
	else cout<<"The number doesn't exists"<<endl;
