// 2 4 6 7 8
#include <stdio.h>
int primecheck (int n);
int evenoddcheck(int n1);
int main(){

    int num,arr[20],digitcount,temp,i,check=0;
    printf("Enter a number string ");
    scanf("%d",&num);
    temp = num;

    digitcount=0;
    while(temp>0)  
    {
        arr[digitcount]= temp%10;
        temp = temp/10;
        digitcount++;
    }

    for(i=0;i<digitcount;i++)
    {
        if(evenoddcheck(arr[i]))
        {
            // even
            if(!primecheck(arr[i]))
            {
                // yes it is composite
                check++;
            }
        }
        else
        {
            // odd
            if(primecheck(arr[i]))
            {
                // Yes it is prime number
                check++;
            }

        }
    }
    printf("Digit count is %d\n Check is %d",digitcount,check);
    if(digitcount == check)
    {
        printf("True");
    }
    else{
        printf("False");
    }

    printf("\n");
    return 0;
}

int primecheck(int n)
{
    int i,flag=1;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            flag = 0;
        }
    }
    if(flag == 1)
    {
        //yes
        return 1;
    }
    else
    {
        //no
        return 0;
    }

}
int evenoddcheck(int n)
{
    if(n%2==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}