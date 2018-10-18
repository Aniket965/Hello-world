#include<bits/stdc++.h>
using namespace std;
int primeFactors(int num) 
{ int max=0;
    for(int i=2;i*i<=num;i++)
    while(num%i==0){
    	if(i>max)
    	max=i;
     num=num/i;
    }
    if(num>1&&num>max)
    max=num;
return max;
} 
int main() 
{ 
    int cnt=0;
    for(int i=1;cnt<15;i++)
    if(primeFactors(i*i+1)>=2*i){
    	cout<<i<<" ";
    	cnt++;
    }
} 
