//A recursive solution of tower of hanoi
#include<stdio.h>
void hanoi(int,int,int,int);
int main()
{
	int n;
	printf("Enter number of disk : ");
	scanf("%d",&n);
	hanoi(n,1,2,3);
	return 0;
}
void hanoi(int n,int src,int med,int dest)
{
	if(n==0) return;

	hanoi(n-1,src,dest,med);
	printf("%d to %d\n",src,dest);
	hanoi(n-1,med,src,dest);	
}
