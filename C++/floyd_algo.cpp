#include <bits/stdc++.h>

int n;
int g[101][101];

int main() {
	puts("Enter graph size");
	scanf("%d", &n);
	puts("Enter graph as adjacency matrix");
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
				scanf("%d", &g[i][j]);
}
