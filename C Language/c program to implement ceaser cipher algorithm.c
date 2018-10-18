#include <stdio.h>

int main() 
{
    char array[100], cipher[100];
    int c=0, x=0, y=0;
    int z;
    printf("This Program will encrypt according to your needs\n");
    printf("Enter the cipher key\n");
    scanf("%d",&z);
    printf("Enter the sentence");
    while((c=getchar()) != '\n')
    {
        array[x++]=(char)c;
        cipher[y++]=(char)(c+z);
    }

    array[x]=0;
    cipher[y]=0;

    printf("%s\n",cipher);

    return 0;
}
