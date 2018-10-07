#include <iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter a numbers: ";
	cin>>n;
	if(n==0 || n==1)
		cout<<n<<"!="<<1<<endl;
	else
	{
		int ans;
		ans=1;
		for(int i=2;i <= n;i++){
			ans=ans*i;
		}
		cout<<n<<"!="<<ans<<endl;
	}
	return 0;
}