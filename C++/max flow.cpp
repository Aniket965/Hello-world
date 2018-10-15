#include <iostream>
#include <limits.h>
using namespace std;
#define n 6
int g[6][6]={{0, 9, 9, 0, 0, 0},
             {0, 0, 4, 8, 0, 0},
             {0, 0, 0, 1, 3, 0},
             {0, 0, 0, 0, 0, 10},
             {0, 0, 0, 8, 0, 7},
             {0, 0, 0, 0, 0, 0}};



int bfs(int v,int *parent)
{int visited[6]={0};
 visited[v]=1;
 int q[8];
 int i,f=0,r=-1;
 q[++r]=v;

 while(f<=r)
 {v=q[f++];
  for(i=0;i<n;i++)
  {if(visited[i]==0&&g[v][i]!=0)
  {//cout<<i;
   *(parent+i)=v;
   q[++r]=i;
   visited[i]=1;
  }
  }
 }
 return((visited[5]==1)?1:0);
}


int max_flow()
{int i,j;
 int parent[6]={-1};
 int max_flow=0,flow=1000;

 while(bfs(0,parent))
 {for(i=5;i!=0;i=parent[i])
  {j=parent[i];
   flow=min(flow,g[j][i]);
  }
  
  for(i=5;i!=0;i=parent[i])
  {j=parent[i];
   g[j][i]-=flow;
   g[i][j]+=flow;
  }
  max_flow+=flow;
 }

 return(max_flow);
}

int main()
{ cout << "The maximum possible flow is " << max_flow()<<endl;
  return 0;
}
