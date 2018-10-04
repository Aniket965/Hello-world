#include <iostream>
using namespace std;
int main(){
int n,sum = 0;
cin >> n;
int o[n] = {};
for(int i =0;i < n;i++){
    cin >> o[i];
}
for(int i =0;i < n;i++){
    sum = sum + o[i];
}
cout << sum << endl;
return 0;
}
