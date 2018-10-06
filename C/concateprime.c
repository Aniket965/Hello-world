#include <stdio.h>
#include <string.h>
int main(){
    // Prime numbers who are divisible by themselfs only or 1
    // how many prime numbers are in between 1 and n store them in the array 
    // after storing use the array values concateing to make a new prime number
    // example 2 and 3 makes 23

    int num,i=2,flag=0,c,arr[100],j,z;
    printf("Enter the nth value ");
    scanf("%d",&num);
    c=0;
    for(i=2;i<num;i++)
    {
        while(j<i)
        {
           if(i%j!=0)
             {
                arr[c]=i;
                c++;
             }
            j++;
        }
    }

    for(i=0;i<z;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    return 0;
}

