#include<stdio.h>
int main()
{
int n;

printf("enter the value of n to calculate the n*n magic square:");
scanf("%d",&n);
int a[n][n];
int i,j;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
a[i][j]=0;

i=0;
j=n/2;
int k=n*n;
int p=1;
while(p<=k)
{
if(i<0&&j==n)
{
i+=2;
j--;
a[i][j]=p;
p++;
i--;j++;
}

else if(i<0&&j<n)
{
i=i+n;
a[i][j]=p;
p++;
i--;
j++;
}

else if(j==n&&i>=0)
{
j=0;
a[i][j]=p;
p++;
i--;
j++;
}

else if(a[i][j]!=0)
{
i+=2;
j--;
a[i][j]=p;
p++;
i--;j++;
}

else
{
a[i][j]=p;
p++;
i--;
j++;
}

}

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{printf("%d",a[i][j]);
}
printf("\n");

}

}
