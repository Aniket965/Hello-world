#include <stdio.h>

void twhenoi(int n, char a, char b, char c);

int main()
{
    int n;
    scanf("%d",&n);
    twhenoi(n,'A','C','B');

    printf("\n");
    return 0;
}

void twhenoi(int n, char from, char to, char aux)
{
    if(n==1)
    {
        printf("\nMove disk 1 from rod %c to rod %c",from,to);
        return;
    }
    twhenoi(n-1,from,aux,to);
    printf("\nMove disk %d from rod %c to rod %c",n,from,to);
    twhenoi(n-1,aux,to,from);
}