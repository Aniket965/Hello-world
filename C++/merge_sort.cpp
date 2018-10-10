#include<bits/stdc++.h>
using namespace std;
#define N 10

void merge(int A[], int init, int middle, int end){
	int n1 = middle - init + 1;
	int n2 = end - middle;

	int L[n1], R[n2];

	for(int x = 0; x < n1; x++){
		L[x] = A[init + x];
	}
	for(int y = 0; y < n2; y++){
		R[y] = A[middle + y + 1];
	}

	int x = 0, y = 0, k = init;
	while(x < n1 && y < n2){
		if(L[x] <= R[y]){
			A[k] = L[x];
			x++;
		}else{
			A[k] = R[y];
			y++;
		}
		k++;
	}
	while(x < n1){
		A[k] = L[x];
		x++;
		k++;
	}
	while(y < n2){
		A[k] = R[y];
		y++;
		k++;
	}
}

void mergesort(int A[], int init, int end){
	if(init < end){
		int middle = (end + init) / 2;
		mergesort(A, init, middle);
		mergesort(A, middle + 1, end);
		merge(A, init, middle, end);
	}
}

int main(){
	int A[N];
	for(int x = 0; x < N; x++){
		cin >> A[x];
	}
	mergesort(A, 0, N - 1);
	for(int x = 0; x < N; x++){
		cout << A[x] << " ";
	}
}
