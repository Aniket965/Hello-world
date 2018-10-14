#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 10000000;
int F[MAXN];
string text, pattern;
int m;

void build(){
    // the prefix under index i is string from pattern[0] to pattern[i-1]
    // inclusive, so the last character of string under index i is [i-1].
    m = pattern.size();
    F[0] = F[1] = 0;    //always true
    for(int i = 2;i <= m; i++){
        // j is the index of the largest next partial match (the largest suffix/prefix)
        // of the string under index (i-1)
        int j = F[i-1];
        while(1){
            // check to see if the last character of string i.e pattern[i-1]
            // expands the current candidate best partial match the prefix under index j
            if(pattern[j] == pattern[i-1]){
                F[i] = j + 1;
                break;
            }
            // if we cannot expand even the empty string
            if(j == 0) { F[i] = 0; break; }
            // else go to the next best candidate partial match
            j = F[j];
        }
    }
}

void kmp(){
    build();
    int flag = 0;
    int n = text.size();
    int i = 0;  // the initial state of automaton is empty
    int j = 0;  // the first character of the text
    while(j < n){
        // if the current character of the text expands the current match
        if(text[j] == pattern[i]){
            i++;
            j++;
            if(i == m) {cout << (j-m) << endl;flag=1;}   // match found
        }
        // if the current state is not 0 (we have not reached the empty string yet) 
        // we try to expand the next best match
        else if(i > 0)  i = F[i];
        // if we reached the empty string and failed to expand even it; we go to the
        // next character from the text, the state of the automaton remains zero
        else j++;
    }
    if(!flag)
        cout << endl;
}

int main(){
    // io;
    while(cin >> m){
        cin >> pattern >> text;
        kmp();
    }
    return 0;
}