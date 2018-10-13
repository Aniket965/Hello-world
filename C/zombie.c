#include <stdio.h>

int main(){
    int b=0,n,a,i;
    scanf("%d%d",&b,&n);
    for(i=0;i<n;i++)
    {
        if(scanf("%d",&a)<1)
        {
            printf("Invalid Input");
            return 0;
        }
        b=b-((a%2)+(a/2));
    }
    if(b>0)
    {
        printf("Yes It will survive");
    }
    else{
        printf("No zombie killed him");
    }

    printf("\n");
    return 0;
}