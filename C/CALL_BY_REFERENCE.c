#include<stdio.h>
void valueswap(int a,int b);
void referenceswap(int *a,int *b);

int main()
{
int a,b;
printf("enter the value of a and b to see the diff bw call by value and reference:");
scanf("%d%d",&a,&b);

valueswap(a,b);
printf("after call by value the value of a and b is %d and %d\n",a,b);
referenceswap(&a,&b);
printf("\nafter call by reference the value of a and b is %d and %d\n",a,b);
return 0;
}

void valueswap(int a,int b)
{int c;
c=a;
a=b;
b=c;
}

void referenceswap(int *a,int *b)
{int c;
c=*a;

*a=*b;
*b=c;
}
