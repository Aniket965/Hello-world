#include <bits/stdc++.h>

// Finds primes up to MAX_SIZE using the sieve of eratosthenes

using namespace std;

const int MAX_SIZE = 10000;
bool primes[MAX_SIZE];

void sieve(){
    for(int i = 2;i < MAX_SIZE;i++){
        if(!primes[i]){
            for (int j = 0; i*i + j*i < MAX_SIZE; j++) {
                primes[i*i + j*i] = 1;
            }
        }
    }

    for (int i = 2; i < MAX_SIZE; ++i) {
        if(!primes[i]) printf("%d\n", i);
    }
}


int main() {
    sieve();
}
