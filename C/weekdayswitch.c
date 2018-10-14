#include <stdio.h>

int main(){

    int num;

    printf("Enter a number between 1 to 7 to check its weekday.\n");
    scanf("%d",&num);

    switch(num)
    {
        case 1: printf("It's Monday");
            break;
        case 2: printf("It's Tuesday");
            break;
        case 3: printf("It's Wednesday");
            break;
        case 4: printf("It's Thursday");
                       break;
        case 5: printf("It's Friday");
                       break;
        case 6: printf("It's Saturday");
                       break;
        case 7: printf("It's Sunday");
                       break;
        default: printf("You have not entered a valid number please enter a valid number.\n");
    }


    
    return 0;
}
