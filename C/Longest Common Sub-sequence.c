#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m,n,C[20][20];
char X[20],Y[20],B[20][20];
int max(int a,int b)
{
    return (a>b)?a:b;
}
void lcs_length(char X[],char Y[])
{
    m=strlen(X);
    n=strlen(Y);
    int i,j;
    for(i=0;i<=m;i++)
    {
        C[i][0]=0;
    }
    for(j=0;j<=n;j++)
    {
        C[0][j]=0;
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]='d';
            }
            else if(C[i-1][j]>=C[i][j-1])
            {
                C[i][j]=C[i-1][j];
                B[i][j]='u';
            }
            else
            {
                C[i][j]=C[i][j-1];
                B[i][j]='l';
            }
        }
    }
}
void print_lcs(int i,int j)
{
    if(i==0 || j==0)
        return ;
    if(B[i][j]=='d')
    {
        print_lcs(i-1,j-1);
        printf("%c",X[i-1]);
    }
    else if(B[i][j]=='u')
        print_lcs(i-1,j);
    else
        print_lcs(i,j-1);
}
int main()
{
    int i,res,j;
    printf("Enter the sequence X\n");
    scanf("%s",X);

    printf("Enter the sequence Y\n");
    scanf("%s",Y);

    lcs_length(X,Y);
    printf("Matrix C:\n");
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    res=C[m][n];
    printf("Longest Common Sub-Sequence Length=%d\n",res);
    print_lcs(m,n);
    return 0;
}
/*
#include<stdio.h>
#include<string.h>

int i,j,m,n,c[20][20];
char x[20],y[20],b[20][20];

void print(int i,int j)
{
                if(i==0 || j==0)
                                return;
                if(b[i][j]=='c')
                {
                                print(i-1,j-1);
                                printf("%c",x[i-1]);
                }
                else if(b[i][j]=='u')
                                print(i-1,j);
                else
                                print(i,j-1);
}

void lcs()
{
                m=strlen(x);
                n=strlen(y);
                for(i=0;i<=m;i++)
                                c[i][0]=0;
                for(i=0;i<=n;i++)
                                c[0][i]=0;

                //c, u and l denotes cross, upward and downward directions respectively
                for(i=1;i<=m;i++)
                                for(j=1;j<=n;j++)
                                {
                                                if(x[i-1]==y[j-1])
                                                {
                                                                c[i][j]=c[i-1][j-1]+1;
                                                                b[i][j]='c';
                                                }
                                                else if(c[i-1][j]>=c[i][j-1])
                                                {
                                                                c[i][j]=c[i-1][j];
                                                                b[i][j]='u';
                                                }
                                                else
                                                {
                                                                c[i][j]=c[i][j-1];
                                                                b[i][j]='l';
                                                }
                                }
}

int main()
{
                printf("Enter 1st sequence:");
                scanf("%s",x);
                printf("Enter 2nd sequence:");
                scanf("%s",y);
                printf("C:\n");
                printf("\nThe Longest Common Subsequence is ");
                lcs();
                for(i=0;i<=m;i++)
                {
                    for(j=0;j<=n;j++)
                    {
                        printf("%d ",c[i][j]);

                    }
                    printf("\n");
                }
                print(m,n);
        return 0;
}
*/
