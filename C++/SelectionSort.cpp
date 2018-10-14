#include<iostream>
using namespace std;

void SelectionSort(int arr[],int n){
    if (n<=1) return;
    int smallestindex=0, i;
    for (i=1; i<n;i++){
        if (arr[i]<arr[smallestindex]) smallestindex=i;
    }
    swap(arr[0],arr[smallestindex]);
    SelectionSort(arr+1,n-1);
}
int main(){
 int n;
 cout<<"Enter size of the array"<<endl;
 cin>>n;
 int arr[n];
 cout<<"Enter Elements of the array"<<endl;
 for (int i=0;i<n;i++) cin>>arr[i];
 SelectionSort(arr,n);
 cout<<"Sorted array using SelectionSort algorithm is"<<endl;
 for (int i=0;i<n;i++) cout<<arr[i]<<" ";
 cout<<endl;
}
