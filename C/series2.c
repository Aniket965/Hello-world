#include <stdio.h>

int main(){

    int num,i=1,sum=0;
    // +1-2+3-4+5-6+7-8+9-n
    printf("Enter the Last value ");
    scanf("%d",&num);

    while(i<=num)
    {
        if(i%2==1)
        {
            printf("+%d",i);
            sum= sum+i;
        }
        else{
            printf("-%d",i);
            sum= sum - i;
        }
    i++;
    }
    printf("\nSum is %d",sum);

    printf("\n");
    return 0;
}