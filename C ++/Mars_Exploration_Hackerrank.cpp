/**
*   This is the solution to the hackerrank problem : https://www.hackerrank.com/challenges/mars-exploration
**/
#include <iostream>
using namespace std;
int main(){
    string S;
    cin >> S;
    string sos = "SOS";
    int count=0;
    int length = S.length();
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<sos.length();j++)
        {
            if(S[i] == sos[j])
            {
                i++;
            }
            else
            {
                count++;
                i++;
            }
        }
        i-=1;
    }
    cout << count;
    return 0;
}
