#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct data
{
    int dist;//my own shortest distance so far
    int adj_list[140001];
    int count;
    int T;
    int weights[140001];
    int visited;
};

int Pri_Q[140001];
int QC;
int front=0;
//int isEmpty();
int delete(struct data *);//
//void insert(struct data *,int,int);

void short_pth(struct data *,int,int,int);//
void relax(struct data *,int,int,int);//
int ans[140001];
int ans_c=0;
int dest_dist = INT_MAX;

int main()
{
    int a,b,i,s,d,m,n,w;//sum,z;
    printf("\nEnter the source and destination vertices:\t");
    scanf("%d%d",&s,&d);
    printf("\nEnter the Number of vertices:\t");
    scanf("%d",&n);
    struct data *arr = (struct data *)malloc((n+1)*sizeof(struct data));
    QC=n;
    printf("\nEnter the number of Edges:\t");
    scanf("%d",&m);
    printf("\nEnter the Time Periods of each Juncton:\n\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&((arr+i)->T));
        (arr+i)->count=0;
        (arr+i)->dist=INT_MAX;
        (arr+i)->visited=0;
        Pri_Q[i-1]=i;
    }
    (arr+s)->dist=0;
    for(i=0;i<m;i++)
    {
        printf("\nEnter a:\t");
        scanf("%d",&a);
        printf("\nEnter b:\t");
        scanf("%d",&b);
        printf("\nEnter weight:\t");
        scanf("%d",&w);
        (arr+a)->weights[b]=w;
        (arr+b)->weights[a]=w;
        (arr+a)->adj_list[((arr+a)->count)++]=b;
        (arr+b)->adj_list[((arr+b)->count)++]=a;
    }
    short_pth(arr,s,d,n);

    //sum=0;
    //for(i=0;i<ans_c;i++)
    //{
      //  z=ans[i];
        //printf("%d\t",z);
        //sum+=((arr+z)->dist);
    //}

    //printf("\n%d",(arr+d)->dist);
    printf("\n%d",dest_dist);
    return 0;
}

int delete(struct data *p)
{
    int i,j,min,indx;
    min=Pri_Q[0];
    indx=front;
    for(i=1;i<QC;i++)
    {
        j=Pri_Q[i];
        if((p+j)->dist<(p+min)->dist)
        {
            min=j;
            indx=i;
        }
    }
    for(i=indx;i<(QC-1);i++)
    {
        Pri_Q[i]=Pri_Q[i+1];
    }
    QC--;

    return(min);
}

void relax(struct data *p,int a,int b,int d)//chk1
{
    int x,t,r;
    if(((p+b)->dist)>(((p+a)->dist)+(p+a)->weights[b]))
    {
        ((p+b)->dist)=(((p+a)->dist)+(p+a)->weights[b]);
        if(b==d)
        {
            if((p+b)->dist<dest_dist)
                dest_dist=(p+b)->dist;
        }
        x=(p+b)->dist;
        t=(p+b)->T;

        if((x%t)!=0)
        {
            r=(x%t);
            (p+b)->dist=((p+b)->dist)+(t-r);//important
        }
    }

    return;
}

void short_pth(struct data *p,int s,int d,int n)
{
    int i,u,v;
    while(QC!=0)
    {
        u = delete(p);
        printf("\n%d -> %d",u,(p+u)->dist);
        ans[ans_c++]=u;
        if((p+u)->visited==0)
        {
            (p+u)->visited=1;
            //if(u==d)
              //  break;
            for(i=0;i<(p+u)->count;i++)
            {
                v=(p+u)->adj_list[i];
                relax(p,u,v,d);
            }
        }
    }
    return;
}
