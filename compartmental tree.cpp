#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int tree[1000000];
void insert(int x,int war)
{
	while (x>0)
	{
		tree[x] = max(tree[x], war);
		x /= 2;
	}
}

int query(int x,int pp,int pk,int zp,int zk)
{
	int middle = (zp + zk) / 2;
	if ((pp>=zp)&&(pk<=zk))
	{
		return tree[x];
	}
	else if ((pp > zk) || (pk < zp))
	{
		return 0;
	}
	else 
	{
		return max(query((2 * x), pp, middle, zp, zk), query((2 * x + 1), middle + 1, pk, zp, zk));
	}
	

}

int main()
{
	int n,pom;
	cin >> n;
	int r = 1;
	while (r<n)
	{
		r *= 2;
	}
	for (int i=0;i<n;++i)
	{
		cin >> pom;
		insert(i + r, pom);
	}
	cin >> n;
	for (int i=0;i<n;++i)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		cout << query(1, 1, r, temp1, temp2);
	
	}
	system("pause");
}