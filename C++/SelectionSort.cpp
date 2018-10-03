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
    cout<<"Om Kumar"<<endl;
    cout<<"05220802716"<<endl;
    int input[] = {10,2,8,15,63,4};
    int size = sizeof(input)/sizeof(input[0]);
    SelectionSort(input,size);
    for(int i:input){
        cout<<i<<" ";
    }
    return 0;
}
