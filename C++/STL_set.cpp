#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  set<int>s;
  set<int>::iterator it; //Iterator helps you travel to elements of set
  for(int i=1;i<=100;i++){
    s.insert(i);  //This insert function will insert into the set.
  }
  it=s.find(n); //Find function in set will find wether n is in the set or not? If n is there in the set than it will give index of n ohterwise it will return s.end()
  if(it==s.end()){
    cout<<"Number is not in the set";
  }
  else{
    cout<<"Number is in the set";
    s.erase(n); //This erase function will erase n from the set if n is found in the set.
  }
  return 0;
}
