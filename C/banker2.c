#include<stdio.h>
int pn,rn,allocation[10][10],max[10][10],need[10][10],available[10],safe[10],flag[10];

void input();
void process();

void input()
{
    printf("Enter the number of processes:");
    scanf("%d",&pn);
    printf("Enter the number of resources:");
    scanf("%d",&rn);
    int i,j;
    printf("Enter the allocation matrix:");
    for(i=0;i<pn;i++)
    {
        for(j=0;j<rn;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("Enter the max matrix:");
    for(i=0;i<pn;i++)
    {
        for(j=0;j<rn;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the first available:");
    for(i=0;i<rn;i++)
    {
        scanf("%d",&available[i]);
    }
    for(i=0;i<pn;i++)
    {
        flag[i]=0;
        for(j=0;j<rn;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
}
void main()
{
    input();
    process();
}


void process()
{
    int c=0,k=0,z=0;
    do{
        c=0;
        for(int i=0;i<pn;i++)
        {
            if(flag[i]==1)
            {
                goto label;
            }
            for(int j=0;j<rn;j++)
            {
                if(need[i][j]<=available[j])
                {
                    continue;
                }
                else
                {
                    goto label;
                }
                if(j==rn-1)
                {
                    safe[k++]=i;
                    flag[i]=1;
                    for(int l=0;l<rn;l++)
                    {
                        available[j]=available[j]+allocation[i][j];
                    }
                    c++;
                }
            }
            label:
            if(c==0)
            {
                z++;
            }
        }while(c<=n && z<=n)
    }
    if(k==n)
    {
        printf("It is in safe state!\n");
        for(i=0;i<k;i++)
        {
            printf("%d",safe[k]);
        }
    }
    else{
        printf("Dead lock occurs!\n")
    }
}