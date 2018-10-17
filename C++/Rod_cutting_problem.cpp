// Rod cutting problem
#include <bits/stdc++.h>
using namespace std;
int cutRodRecursion(int price[], int n);
int cutRodDP(int price[], int n);
int main(){
	int n;
	cin >> n;
	int price[n];
	for(int i=0; i<n; i++)
		cin >> price[i];
	cout << cutRodRecursion(price, n) << endl;
	cout << cutRodDP(price, n) << endl;
	return 0;
}

// Exponential
int cutRodRecursion(int price[], int n){
	int maxRev = 0;
	for(int i=0; i<n; i++){
		maxRev = max(maxRev, price[i] + cutRodRecursion(price, n-i-1));
	}
	return maxRev;
}

// O(n^2)
int cutRodDP(int price[], int n){
	int revenue[n], p=0;
	revenue[0] = 0;
	for(int i=0; i<=n; i++){
		p=0;
		for(int j=0; j<i; j++){
			p = max(p, price[j] + revenue[i-j-1]);
		}
		revenue[i] = p;
	}
	return revenue[n];
}