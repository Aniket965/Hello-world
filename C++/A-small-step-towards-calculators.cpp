

#include <bits/stdc++.h>

using namespace std;

int solve(char* opr) {
 int x=((int)*opr-48);
 int y=((int)*(opr+2)-48);
 int z=(int)*(opr+1);
 return z=='+'? x+y:x-y;
}
int main() {
  char* opr = (char *)malloc(512000 * sizeof(char));
    cin >> opr;
    int result = solve(opr);
    cout << result << endl;
    return 0;
}
