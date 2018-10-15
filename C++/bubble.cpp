#include<bits/stdc++.h>
using namespace std;

int main(){
	int qt = 0, aux;
	vector<int> p;
	while(cin >> aux){
		p.push_back(aux);
		qt++;
	}
	for(int x = 0; x < qt; x++){
		for(int y = 0; y < qt - 1; y++){
			if(p[y] > p[y+1]){
				swap(p[y], p[y+1]);
			}
		}
	}
	for(int x = 0; x < qt; x++){
		cout << p[x] << " ";
	}
}
