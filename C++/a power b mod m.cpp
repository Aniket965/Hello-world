#include <iostream>
using namespace std;
#define ll long long
long long power_mod_p(ll a, ll b, ll m){

		if(!b)return 1;

		return power_mod_p(a*a%m, b/2, m)*(b&1? a:1)%m;
	}

int main() {
	
	long long a,b,m;
	cin>>a>>b>>m;
	cout<<power_mod_p(a, b, m)<<endl;


	return 0;
}
