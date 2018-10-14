#include <stdio.h>

int main(){

    // Sum of two matrixes are
    int sum[20][10],mat1[20][10],mat2[20][10];
    int i,j;
    int m=0,n=0;

    printf("Enter the size of the matrix\n");
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d ",&mat1[i][j]);
        }
        printf("\n");
    }
    printf("Enter %d elements in the 2nd matrix\n",sizex*sizey);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d ",&mat2[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum[i][j]= mat1[i][j] + mat2[i][j];
        }
    }
    printf("The sum matrix of both the array matrix are\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }

}
