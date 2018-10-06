#include <stdio.h>

int main(){

    // Sum of two matrixes are
    int sum[10][10],mat1[10][10],mat2[10][10];
    int i=0,j=0;
    int sizex=0,sizey=0;

    printf("Enter the size of the matrix\n");
    scanf("%d%d",&sizex,&sizey);

    // 1st Matrix
    printf("\nEnter %d elements in the 1st matrix\n",sizex*sizey);
    for(i=0;i<sizex;i++)
    {
        for(j=0;j<sizey;j++)
        {
            scanf("%d",&mat1[i][j]);
        }
        printf("\n");
    }

    // 2nd Matrix
    printf("Enter %d elements in the 2nd matrix\n",sizex*sizey);
    for(i=0;i<sizex;i++)
    {
        for(j=0;j<sizey;j++)
        {
            scanf("%d",&mat2[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<sizex;i++)
    {
        for(j=0;j<sizey;j++)
        {
            sum[i][j]= mat1[i][j] + mat2[i][j];
        }
    }
    printf("The sum matrix of both the array matrix are\n");
    for(i=0;i<sizex;i++)
    {
        for(j=0;j<sizey;j++)
        {
            printf("%d\n",sum[i][j]);
        }
        printf("\n");
    }


    printf("\n");
    return 0;
}