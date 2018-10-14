#include<iostream>
using namespace std;
typedef long long int lli;
int main(){
    lli input;
    lli x;
    lli count=0;
    lli temp=0;
    cin>>input;
    lli m=input;
    while(m--){
        cin>>x;
        temp=count=0;
        for(int i=1;i*i<=x;i++){
            if(x%i==0)
                if(i*i==x)
                    count++;
                else
                    count+=2;
            if(count>=4){
                temp=1;
                break;
            }
        }
        if(temp==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
