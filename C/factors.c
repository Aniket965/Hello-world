#include <stdio.h>

int main(){

    // Factors of a value
    int num,i;

    printf("Enter a value to calculate ");
    scanf("%d",&num);
        for(i=1;i<=num;i++)
        {
        	if(num%i==0)
        	printf("%d  ",i);
        }
    
    printf("\n");
    return 0;
}
