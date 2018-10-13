#include <stdio.h>

int main(){

    int num;

    printf("Enter a number between 1 to 7 to check its weekday ");
    scanf("%d",&num);

    switch(num)
    {
        case 1: printf("Its Monday");
            break;
        case 2: printf("Its Tuesday");
            break;
        case 3: printf("Its Wednesday");
            break;
        case 4: printf("Its Thursday");
                       break;
        case 5: printf("Its Friday");
                       break;
        case 6: printf("Its Saturday");
                       break;
        case 7: printf("Its Sunday");
                       break;
        default: printf("You have not entered a valid number please enter a valid number");
    }


    printf("\n");
    
}
