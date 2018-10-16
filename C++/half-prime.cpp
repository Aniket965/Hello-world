#include <iostream>

void makePrimes(int *, int, int &);

using namespace std;

int main(){
    int primes[10000];
    int boundary, cnt, num = 0;
    cin >> boundary;
    makePrimes(primes, boundary, cnt);
    for(int i = 0, j = cnt - 1 ; i <= j;){
        if(boundary / primes[i] >= primes[j]){
            num += j - i + 1;
            i++;
        }else
            j--;
    }
    cout << num;
}

void makePrimes(int * primes, int num, int& cnt){
    int i, j;

    primes[0] = 2;
    primes[1] = 3;

    for(i = 5, cnt = 2; i < num; i += 2)
    {
        int flag = true;
        for(j = 1; primes[j]*primes[j] <= i; ++j)
        {
            if(i%primes[j] == 0)
            {
                flag = false; break;
            }
        }
        if(flag) primes[cnt++] = i;
    }
}
