#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int m, s, sum = 0;
	cin>>m>>s;
	
	int dig[m];
	fill_n(dig, m, 0);
	
	if(s == 0){
		if(m > 1){
			cout<<-1<<" "<<-1;
		}
		else{
			cout<<0<<" "<<0;
		}
		return 0;
	}
	else{
		if(m == 1){
			cout<<1<<" "<<s;
			return 0;
		}
		else{
			int nine_count = s/9;
			int last_digit = s%9;
			for(int i = 0; i < nine_count; ++i){
				dig[i] = 9;
			}
			if(last_digit)
				dig[m-1] = last_digit;
		}
	}
	
	for(int i = m - 1; i >=0; --i){
		cout<<dig[i];
	}
	
	cout<<' ';
	
	for(auto i: dig){
		cout<<i;
	}
	return 0;
}