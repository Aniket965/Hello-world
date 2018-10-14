#include <bits/stdc++.h>
using namespace std;
int buscar(int v[], int com, int fim){
	int esq = com;
	int dir = fim;
	int aux;
	int pivo = v[com];
	while(esq < dir){
		while(v[esq] <= pivo && esq <= fim){
			esq++;
		}
		while(v[dir] > pivo && dir > com){
			dir--;
		}
		if(esq < dir){
			swap(v[esq],v[dir]);
			/*aux = v[esq];
			v[esq] = v[dir];
			v[dir] = aux;*/
		}
	}
	v[com] = v[dir];
	v[dir] = pivo;
	return dir;
}
void quickSort(int v[], int com, int fim){
	int pivo;
	if(com < fim){
		pivo = buscar(v,com,fim);
		quickSort(v,com, pivo-1);
		quickSort(v, pivo + 1, fim);
	}
}
int main(){
	int v[1000000];
	int qnt;
	cin >> qnt;
	for(int i=0; i< qnt; i++)
	scanf("%d", &v[i]);
	quickSort(v,0,qnt-1);
	for(int i=0; i< qnt; i++)
	printf("%d ", v[i]);
	cout << endl;
	return 0;
}
