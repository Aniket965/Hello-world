#include <stdio.h>
#include <string.h>
int main(){

    // Palindrome 101 12321

    char a[20],b[20];
    int arrsize=0,i=0,temp=0;

    printf("Enter a string ");
    scanf("%s",a);
    arrsize = strlen(a);

    for(i=0;i<arrsize;i++)
    {
      b[i] = a[i];
    }

    if(!strcmp(a,b))
    {
        printf("Yes it is palindrome");
    }
    else
    {
        printf("No you are not a palindrome baby");
    }

    printf("\n%d",arrsize);
    printf("\n%s",a);
    printf("\n%s",b);
    


    printf("\n");
    return 0;
}