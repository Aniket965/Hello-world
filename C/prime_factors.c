#include <stdio.h>

main()
{
    int i,x;
    printf("--Prime Factors Printing--\n");
    printf("Enter a number:\n");
    scanf("%d",&x);
    
    for(i=2;x>1;i++){
        while(x%i == 0){
            printf("%d ",i);
            x = x / i;
        }
    }
}