#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter n :" ;
    cin >> n;
    vector <pair<int,int> > a(n);
    cout << "Enter start and finish times : \n";
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int,int> p1, pair<int,int> p2) {
        return p1.second < p2.second;
    });
    cout << "Selected activities : \n";
    //first is always selected
    cout << a[0].first << "  " << a[0].second << "\n";
    int i = 0;
    for(int j = 1; j < n; j++) {
        if(a[j].first >= a[i].second) {
            cout << a[j].first << "  " << a[j].second << "\n";
            i = j;
        }
    }
}
