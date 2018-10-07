#include <iostream>
#include<stdio.h>
using namespace std;

int getPivot(int input[],int start,int end){
  int pivot = input[start];
  int i = start;
  int j = end;
  while(i<j){
    while(i<j && input[--j]>=pivot);
    if(i<j){
        input[i] = input[j];
    }

    while(i<j && input[++i]<=pivot);
    if(i<j){
        input[j] = input[i];
    }
  }
  input[j] = pivot;
  return j;
}
void quickSort(int input[],int start,int end){
    if(start>end){
        return;
    }
    int partitionIndex = getPivot(input,start,end);
    quickSort(input,start,partitionIndex-1);
    quickSort(input,partitionIndex+1,end);

}

int main()
{
    cout<<"Om Kumar"<<endl;
    cout<<"05220802716"<<endl;
    int input[] = {5,10,2,7,22,15,-99};
    int end = sizeof(input)/sizeof(input[0]);
    quickSort(input,0,end);
    for(int i=0;i<end;i++){
        cout<<input[i]<<" ";
    }

    return 0;
}
