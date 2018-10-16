/*Rahul Ghosh

Implementation of floyd warshall all pair shortest path algorithm
The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.
 The problem is to find shortest distances between every pair of vertices in a 
 given edge weighted directed Graph.
*/

#include<stdio.h>
int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    if(b<a)
     return b;
}
void floyd(int p[100][100],int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                p[i][j] = min(p[i][j],p[i][k]+p[k][j]);
            }
        }
    }
}
int main()
  {
    int n,e,p[100][100],i,j,u,v,w,v1,v2;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the number of edges\n");
    scanf("%d",&e);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            p[i][j] = 99;
        }
    }
    printf("enter the end vertices of a particular edge and give the weight of it\n");
    for(i=0;i<e;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        if(u<=n && v<=n)
        {
        p[u][v] = w;
           
        }
        else
        printf("you have given wrong input this vertice doesn't exist\n");
        
    }
    printf("The final input is\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",p[i][j]);
        }
        printf("\n");
    }
    floyd(p,n);
    printf("Enter the vertice numbers to get the shortest weighted path\n");
    scanf("%d%d",&v1,&v2);
    printf("shortest path between %d and %d is %d\n",v1,v2,p[v1][v2]);

    return 0;

    
    
}