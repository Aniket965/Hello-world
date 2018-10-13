#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string st;
    cin >> st;
    vector<int> vec(5,0);
    for(int i=0;i<st.length();i++){
        if(st[i]=='a')
            vec[0] = 1;
        else if(st[i]=='e')
            vec[1] = 1;
        else if(st[i]=='i')
            vec[2] = 1;
        else if(st[i]=='o')
            vec[3] = 1;
        else if(st[i]=='u')
            vec[4] = 1;
    }
    for(int i=0;i<5;i++){
        if(vec[i] == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
	return 0;
}
