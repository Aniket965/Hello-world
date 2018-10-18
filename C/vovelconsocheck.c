#include <stdio.h>

int main(){

    char letter;
    printf("Enter a Character Please ");
    scanf("%c",&letter);

    if(letter == 'a' || letter == 'A' || letter == 'e' || letter =='E' || letter == 'i' || letter =='I'|| letter == 'o' || letter =='O'|| letters == 'u' || letter == 'U' )
    {
        printf("%c is a vowel\n",letter);
    }
    else{
        printf("%c is a consonent\n",letter);
    }
return 0;
}
