#include<stdio.h>
void leftRotate(int a[],int n);
void leftRotate(int a[],int n,int d)
{
int i;
for(i=0;i<d;i++)
leftRotatebyone(a,n);
}
void leftRotatebyone(int a[],int n)
{
int temp=a[0],i;
for(i=0;i<n-1;i++)
a[i]=a[i+1];
a[i]=temp;
}
void printArray(int a[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d",a[i]);
}
int main()
{
int a[]={1,2,3,4,5,6,7,8,9,10};
leftRotate(a,2,10);
printArray(a,10);
return 0;
}
