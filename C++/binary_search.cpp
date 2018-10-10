#include<bits/stdc++.h>
using namespace std;
#define N 10

int binary_search(int x, int n, int v[]){
	int e = 0, m = 0, d = n-1;
	while(e <= d){
		m = (e+d)/2;
		if(v[m] == x){
			int can = 1;
			/* search for the FIRST occur of the element */
			while(can){
				if(v[m-1] == x && (m-1) >= 0){
					m -= 1;
				}else{
					break;
				}
			}
			return m;
		}
		if(v[m] < x){
			e = m + 1;
		}else{
			d = m - 1;
		}
	}
	return -1;
}

int main(){
	int A[N], proc;
	for(int x = 0; x < N; x++){
		cin >> A[x];
	}
	sort(A, A + N); // sort the array
	cin >> proc; // type here what number you are searching
	int search = binary_search(proc, N, A);
	if(search == -1){
		cout << "Not found" << endl;
	}else{
		cout << "Found at index " << search << endl;
	}
}
