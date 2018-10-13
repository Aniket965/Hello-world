#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >>n;
    string name,game;
    unordered_map<string, int> m;
    set<string> s;
    for(int i=0;i<n;i++) {
        cin >> name>> game;
        if(s.find(name)==s.end()) {
            m[game]++;
        }
    }
    unordered_map<string, int>::iterator it;
    string st;
    int len=0;
    for(it=m.begin(); it!=m.end();it++){
        if(it->second> len) {
            st = it->first;
            len = it->second;
        }
        cout << it->first << endl;
    }   
    cout << st << endl;
    cout << m["football"];
	return 0;
}
