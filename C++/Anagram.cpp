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
		string s1,s2;
		cin>>s1>>s2;
		int h1[26],h2[26];
		memset(h1,0,sizeof h1);
		memset(h2,0,sizeof h2);
		int len1=s1.length(),len2=s2.length();
		if(len1==len2){
			for(int i=0;i<len1;i++){
				h1[s1[i]-'a']++;
				h2[s2[i]-'a']++;
			}
			for(int i=0;i<26;i++){
				if(h1[i]!=h2[i]){
					cout<<"NO";
					break;
				}
			}
			cout<<"YES";
		}else
			cout<<"NO";
		cout<<"\n";
	}
	return 0;
}
