#include <stdio.h>
#include <string.h>

int main(){

    char a[10],b[10],c[20],temp,temp1;
    int sa,sb,sc,i;

    scanf("%s",a);
    scanf("%s",b);

    sa = strlen(a);
    sb = strlen(b);

    strcpy(c,a);
    strcat(c,b);

    printf("%d,%d\n",sa,sb);
    printf("%s",c);


    temp=b[0];
    b[0] =a[0];
    a[0] =temp;

    printf("\n%s %s",a,b);

    temp = b[0];
    b[0] = a[0];
    a[0] = temp;

    temp1 = b[sb-1];
    b[sb-1] = a[sa-1];
    a[sa-1] = temp1;

    printf("\n%s %s\n",a,b);

    printf("\n");
    return 0;
}