#include <stdio.h>

main()
{
    int a[3][3],b[3][3],c[3][3]={0};
    int i,j,k;
    printf("---Matrix Multiplication--- \n\n");
    printf("Enter 1st matrix: \n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter 2nd Matrix: \n");
    
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&b[i][j]);
        }
    }

    
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                c[i][j] += a[i][k] * b[k][j];
            
            }
        }
    }

    printf("Multiplied matrix is :\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d\t",c[i][j]);
            if(j == 2)
                printf("\n");
        }
    }

}
