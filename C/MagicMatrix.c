#include<stdio.h>
main()
{int a[100][100]={0};
int i=0,n,p=1,j;
scanf("%d",&n);

j=n/2;
int g=n*n;
while(p<=g)
{
 if(i==-1&&j==-1)
{i=i+2;
j=j+1;
a[i][j]=p;
p++;
i--;
j--;
}
else if(i==-1)
{i=i+n;
a[i][j]=p;
i--;j--;p++;
}
else if(j==-1)
{j=j+n;
a[i--][j--]=p++;
}
else if(a[i][j]!=0)
{i=i+2;
j++;
a[i][j]=p++;
i--;j--;
}
else
{a[i--][j--]=p++;
}
}
for(i=0;i<n;i++)
{for(j=0;j<n;j++)
{printf("%d\t",a[i][j]);
}
printf("\n");
}
}


