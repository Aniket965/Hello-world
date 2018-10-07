#include <stdio.h>

// Just have to do with the range now

int main()
{
    int n,square,arr[10],temp,size,digit[10],i,sum,num,c=0;
    printf("Enter a number\n");
    scanf("%d",&num);


for(n=1;n<=num;n++)
{
square = n*n;
size = 0;
sum = 0;


    for(i=0;square>0;i++)
    {
        digit[i]= square%10;
        square = square/10;
        size++;
    }

for(i=0;i<size;i++)
{
sum = sum + digit[i];
}


if (sum == n)
{
   arr[c]= n;
   c++;
}

}
    for(i=0;i<c;i++)
    {
        printf("%d ",arr[i]);
    }


    printf("\n");
    return 0;
}