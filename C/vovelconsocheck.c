#include <stdio.h>

int main(){

    char letters;
    printf("Enter a Character Please ");
    scanf("%c",&letters);

    if(letters == 'a' || letters == 'A' || letters == 'e' || letters =='E' || letters == 'i' || letters =='I'|| letters == 'o' || letters =='O'|| letters == 'u' || letters == 'U' )
    {
        printf("The character is a vovel");
    }
    else{
        printf("This Character is a consonent");
    }

printf("\n");
return 0;
}