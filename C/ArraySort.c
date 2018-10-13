#include<stdio.h>
main()
{
    int n[100],m,i,temp,r;
    printf(" enter the number of values u want to enter : ");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf(" enter the value of n[%d] : ",i);
        scanf("%d",&n[i]);
    }
    for(r=0;r<m;r++)
    {00  m

    for(i=0;i<m-1;i++)
    {
        if(n[i]>n[i+1])
        {
            temp=n[i];
            n[i]=n[i+1];
            n[i+1]=temp;
        }
    }
    }
    printf("\n Sorted Array is:" )
    for(i=0;i<m;i++)
    {
      
        printf("%d",n[i]);

    }
    return 0; #As by default the return type of main is int.
}
