#include <iostream>
#include<limits.h>
using namespace std;

int mcm(int input[],int start,int last){
  if(start==last){
    return 0;
  }
  int min = INT_MAX;
  for(int i=start;i<last;i++){
    int value = mcm(input,start,i)+mcm(input,i+1,last)+input[start-1]*input[i]*input[last];
    if(value<min){
        min = value;
    }

  }
  return min;
}

int main()
{
    int input[] = {10,20,30,40};
    int m = mcm(input,1,3);
    cout<<m<<endl;

}
