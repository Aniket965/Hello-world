#include<stdio.h>
void swap1(int a,int b);
void swap2(int a,int b);
void swap3(int a,int b);

int main()
{
int a,b;
printf("enter two number to be swapped in order to implement please avoid 0 as input:");
scanf("%d%d",&a,&b);

swap1(a,b);
swap2(a,b);
swap3(a,b);

return 0;
}

void swap1(int a,int b)
{
b=a+b;
a=b-a;
b=b-a;

printf("the swapped value of a and b is %d and %d",a,b);
}

void swap2(int a,int b)
{
b=a*b;
a=b/a;
b=b/a;

printf("the swapped value of a and b is %d and %d",a,b);
}

void swap3(int a,int b)
{
a^=b^=a^=b;
printf("the swapped value using xor of a and b id %d and %d",a,b);

}
