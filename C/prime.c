#include <stdio.h>
#include <string.h>
int main()
{
// Prime factorisation
int num,arr[10],i,j;
printf("Enter a Number to calculate\n");
scanf("%d",&num);

for(i=0;i<num;i++)
{
if(num%i+2==0)
{
arr[i] = num;
}
}
for(i=0;){
printf("\n");
}
return 0;
