//Maps are a part of the C++ STL.Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
#include<bits/stdc++.h>
using namespace std;
int main(){
  map<string,int>m; //This will create a map m with key_value as string data type and mapped_value as Integer datatype
  map<string,int>::iterator it; //Iterator can be usefull for finding a index of particular key_value
  string str="Hactoberfest";
  int year=2018;
  m.insert(make_pair(str,year));  //make_pair function used for make pair of any two datatypes here string and integer. And it will insert it into map m
  it=m.find(str);   //find function will find index of str if it is in the map, otherwise it will give m.end()
  if(it==m.end()){
    cout<<"It is not present";
  }
  else{
    cout<<"It was present and removed it";
    m.erase(str); //It will erase all mapped_values associated with key_values str.
  }
  return 0;
}
