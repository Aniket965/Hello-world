#include <bits/stdc++.h>
  using namespace std;

// Function returns (n^p) % MOD
long long power(long long n , long long p , long long MOD){
  long long ans = 1;
  n %= MOD;
  for(;p;p>>=1){
    if(p&1){
      ans = (ans*n)%MOD;
    }
    n = (n*n)%MOD;
  }
  return ans;
}

bool millerTest(long long d, long long n) { 
  long long a = 2 + rand() % (n - 4); 
  long long x = power(a, d, n); 
  if (x == 1  || x == n-1) 
     return true;  
  while (d != n-1) { 
    x = (x * x) % n; 
    d *= 2; 
    if (x == 1)      return false; 
    if (x == n-1)    return true; 
  } 
  return false; 
} 

// K is the no. of times primarility is checked , higher value of k means more accurate results
bool isPrime(long long n, long long k) {  
  if (n <= 1 || n == 4)  return false; 
  if (n <= 3) return true; 
  long long d = n - 1; 
  while (d % 2 == 0) 
      d /= 2; 
  for (long long i = 0; i < k; i++) 
   if (millerTest(d, n) == false) 
    return false; 
  return true; 
} 


int main(){
  cout << isPrime(7 , 10) << ' ' << isPrime(1000000007 , 10) << ' ' << isPrime(17 , 10) << '\n';
  return 0;
}
