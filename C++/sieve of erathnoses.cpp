#include<bits/stdc++.h>
using namespace std;
//Initialize all entries of boolean array 
    // as true. A value in isPrime[i] will finally 
    // be false if i is Not a prime, else true 
void sieve(int n,bool isPrime[])
{
 isPrime[0]=isPrime[1]=false;
 for(int i=2;i<=n;i++)
 isPrime[i]=true;
 for (int p=2; p*p<=n; p++) 
    { 
        // If isPrime[p] is not changed, then it is 
        // a prime 
        if (isPrime[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) //it will make 2p,3p,4p,5p,6p etc
                isPrime[i] = false; 
        } 
    } 
		//O(N log (log N))
}    
bool isPrime(int n)

{

    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
//time complexity is o(sqrt(n))
}

int main()
{
	int n;
	cin>>n;
	bool isPrime[n+1];
	sieve(n,isPrime);
	//find first two prime numbers whose sum will equal to the given number.
	for (int i=0; i<n; i++) 
    { 
        if (isPrime[i] && isPrime[n-i]) 
        { 
            cout << i << " " << (n-i); 
            break; 
        } 
    } 
}
