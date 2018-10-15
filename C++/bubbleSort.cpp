#include <iostream>

using namespace std;
void swap(int input[],int i,int j){
      int temp = input[i];
      input[i] = input[j];
      input[j] = temp;
}
void bubbleSort(int input[],int size){
   for(int firstUnsortedIndex = size-1;firstUnsortedIndex>0;firstUnsortedIndex--){
    for(int i = 1;i<=firstUnsortedIndex;i++){
        if(input[i-1]>input[i]){
            swap(input,i-1,i);
        }
    }
   }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++)
      cin>>input[i];
    int size = sizeof(input)/sizeof(input[0]);
    bubbleSort(input,size);
    for(int i=0;i<size;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}
