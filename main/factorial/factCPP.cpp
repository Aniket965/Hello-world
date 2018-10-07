#include <iostream>
using namespace std;

int f(int a){
  return a < 2 ? 1 : a * f(a-1);
}

int main(){
  int a;
  cin>>a;
  cout<<f(a)<<endl;
  exit(EXIT_SUCCESS);
}
