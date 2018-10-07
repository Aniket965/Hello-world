#include <stdio.h>


void main()
{
	int n; // No. for which Factorial is required
	scanf("%d", &n);
	int result = 1;
	
	while(n)
	{result*=n;
	n--;}

	printf("%d\n", result);
}
