// This is a program to print a pyramid like pattern in C
#include<stdio.h>
int main()
{
int i,j,k;
for(i=1;i<=5;i++)
{
for(j=5;j>i;j--)
{
printf(" ");
}
for(k=1;k<=i;k++)
{
printf("*");
}
printf("\n");
}
}

