#include <iostream>
using namespace std;

int strange_sumB(int arr[],int left, int right);

int main(){
  int a[] ={0,1,2,3,4,5,6};
  int sum = strange_sumB(a,3,1);
  cout << "sum= " << sum << endl;
}

int strange_sumB(int arr[], int left, int right){
  cout << "Left= " << left << "\tRight= " << right << endl;
  if (right - left == 1)
  {
    return arr[left];
  }
  return strange_sumB(arr,left, right/2) + strange_sumB(arr,right/2,right);
}

