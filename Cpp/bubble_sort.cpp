#include<iostream>
using namespace std;


int main(){

    int a[10]; ///Creates an array of 10 integers
    int n,key;

    cin>>n;
    ///Read n numbers;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ///Bubble Sort - Optimised
    for(int times=0;times<n-1;times++){

        bool swaps=0;
        ///Pair Wise Swapping starting from 0th positon

        for(int j=0;j<=n-times-2;j++){
            if(a[j]>a[j+1]){
                ///Inbuild Swap Fn
                swap(a[j],a[j+1]);
                swaps++;
            }
        }
        if(swaps==0){
            break;
        }
    }

    ///Print
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }

return 0;
}