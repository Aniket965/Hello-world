#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
// 33 11+11+11 8
    int num,i,quos,rem,sum;
    char arr[100];

    printf("Enter a number to convert\n");
    scanf("%d",&num);
    
    if(num<11)
    {
        for(i=0;i<num;i++)
        {
            if(i%2==0)
            {
                arr[i] = '1';
            }
            else
            {
            arr[i] = '+';
            }
        }
    }
    if(num==11)
    {
        sum=2;
    }

    if(num>11 && num<121)
    {
        quos= num/11;
        rem = num%11;
        for(i=0;i<quos;i++)
        {
            if(i%2!=0)
            arr[i] = '9';
            else
            arr[i] = '+';
        }
    }
    for(i=0;i<strlen(arr);i++)
    {
        printf("%c ",arr[i]);
    }






    printf("\n");
    return 0;
}