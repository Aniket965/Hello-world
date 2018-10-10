#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i)
	{
		int x = a[i];
		int hole = i;
		/*for (int j = i; j >0 ; j--)
		{
			if (a[j-1] > x)
			{
				a[hole] = a[j-1];
				a[j-1] = x;
				hole--;
			}
		}   */
		while(hole > 0 && a[hole-1] > x)
		{
			a[hole] = a[hole-1];
			
			hole--;
		}
		a[hole] = x;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
