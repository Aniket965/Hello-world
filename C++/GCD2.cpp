#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long t,a,b=0;
	int len;
	string str;
	cin>>t;
	while(t--){
		b=0;
		cin>>a;
		cin>>str;
		if(a==0){
			cout<<str<<endl;
		}
		else {
			for(int i=0;str[i]!='\0';i++){
				b = (b*10 + (str[i]-0x30))%a;
			}
			cout<<__gcd(a,b)<<endl;
		}
	}
	return 0;
}
