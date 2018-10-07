#include <iostream>

using namespace std;

void shellSort(int input[],int size){
  for(int gap = size/2;gap>0;gap = gap/2){
    for(int i = gap;i<size;i++){
        int element = input[i];
        int j = i;
        while(j>   =gap && input[j-gap]>element){
            input[j] = input[j-gap];
            j = j-gap;
        }

        input[j] = element;
    }
  }
}

int main()
{
    cout<<"Om Kumar"<<endl;
    cout<<"05220802716"<<endl;
    int input[] = {10,2,8,15,63,4};
  int s=2;
    int size = sizeof(input)/sizeof(input[0]);
    shellSort(input,size);
  if(s==2){  
    for(int i:input){
          cout<<i<<" ";
      }
  }
    return 0;
}
