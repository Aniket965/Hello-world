#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>v; //It will create vector name v of type integer.
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);  //it will append(insert) values at the end of vector
    }
    sort(v.begin(),v.end());  //This function will sort all the elements of vector v in ascending order
    for(int i=0;i<n;i++)
      cout<<v[i]<<" ";
    return 0;
}
