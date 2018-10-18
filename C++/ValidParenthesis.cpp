#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<char> st;
		for(int i=0;i<s.length();i++){
			if(s[i]=='{' || s[i]=='(' || s[i]=='[')
				st.push(s[i]);
			else if(!st.empty()){
				if(s[i]=='}' && st.top()=='{')
					st.pop();
				else if(s[i]==')' && st.top()=='(')
					st.pop();
				else if(s[i]==']' && st.top()=='[')
					st.pop();
				else{
					st.push(s[i]);
					break;
				}	
			}else{
				st.push(s[i]);
				break;
			}
		}
		if(st.empty())
			cout<<"balanced";
		else
			cout<<"not balanced";
		cout<<"\n";
	}
	return 0;
}