#include <iostream>

using namespace std;

void swap(int input[],int i,int j){
 int temp = input[i];
 input[i] = input[j];
 input[j] = temp;
}

int getMin(int input[],int start,int end){
   int minValue = INT_MAX;
   int minIndex = start;
   for(int i=start;i<end;i++){
    if(minValue>input[i]){
        minValue = input[i];
        minIndex = i;
    }
   }
   return minIndex;
}
void SelectionSort(int input[],int size){
  for(int i=0;i<size;i++){
    int minIndex = getMin(input,i,size);
     swap(input,i,minIndex);
  }
}
int main()
{
    int n;
    cout<<"Enter the number of elements to be inserted: ";
    cin>>n;
    int input[n];
    cout<<"Enter the elements to be sorted: ";
    for(int i=0;i<n;i++)
     cin>>input[i];
    int size = sizeof(input)/sizeof(input[0]);
    SelectionSort(input,size);
    for(int i:input){
        cout<<i<<" ";
    }
    return 0;
}
