#include <stdio.h>

int primecheck(int);

int main(){

    int i,c,temp,j,flag,range,arr[10],finalans,sum;
    printf("Enter range of prime numbers\n");
    scanf("%d",&range);

i=2;
c=0;
temp =0;
finalans=0;
sum = 0;
    for(i=3;i<=range;i++)
    {
        // i= number to check
        temp = i;
        if(primecheck(temp)){
            // The number is a prime number
            while(sum<=i || j>=range)
            {
                if(primecheck(j))
                {
                    sum = sum + j;
                }
                j++;
            }
            printf("%d",sum);
            if(sum == temp)
            {
                finalans++;
            }
            sum = 0;
            

        }


    }
    // printf("Prime Numbers are\n");
    // for(i=0;i<c;i++)
    // {
    //     printf("%d\n",arr[i]);
    // }
    printf("Consecutive Prime Numbers are \n%d",finalans);



    printf("\n");
    return 0;

}

int primecheck(int number)
{
    int flag= 0;
    int j=2;
    while (j<number){
        if(number%j==0)
        {
            flag =1;
        }
        j++;
    }
    if(flag == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}


/*

2+3=5
2+3+5= 10
2+3+5+7 =17

*/