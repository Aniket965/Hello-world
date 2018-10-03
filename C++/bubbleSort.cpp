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
    int input[] = {88,55,20,63,23,99,45};
    int size = sizeof(input)/sizeof(input[0]);
    bubbleSort(input,size);
    for(int i=0;i<size;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}
