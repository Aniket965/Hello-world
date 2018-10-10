 #include <bits/stdc++.h>
#include<string.h>
#define INF 1000000000
using namespace std;
long long int max[1000000],min[1000000];

void convertMINH(long long int a[],long long int i, long long int n)
    {
        long long int l= 2*i+1;
        long long int r= 2*i+2;

        long long int small = i;
        if (l<n && a[l]<a[small])
         {
            small= l;
        }

        if (r<n && a[r]< a[small]) 
        {
            small= r;
        }
        if (small!= i) {
            swap(a[i],a[small]);
            convertMINH(a, small, n);
        }
    }

 void MinH(long long int a[] , long long int n)
  {
      long long int ht1 = (n - 1) / 2;
        for (long long int i = ht1; i >= 0; i--) 
        {
            convertMINH(a, i, n);
        }
    }

void convertMAXH(long long int a[], long long int i,long long int n) 
{
        long long int l= 2*i+1;
        long long int r= 2*i+2;
        long long int largest = i;

        if (l<n && a[l]> a[largest]) 
        {
            largest = l;
        }

        if (r<n && a[r]>a[largest])
         {
            largest = r;
        }

        if (largest!=i) {
            swap(a[i],a[largest]);                                      
            convertMAXH(a, largest, n);
        }
    }
 
void MaxH(long long int a[],long long int n) 
{
        long long int ht1 = (n - 1) / 2;
        for (long long int i = ht1; i >= 0; i--) 
        {
            convertMAXH(a, i, n);
        }
    }


int main()
{

long long int n;
cin>>n;
long long int a[n],max[n],min[n];
long long int x1=0,x2=0;
double mid=0;
    cout<<setprecision(1)<<fixed;
for(long long int i=0;i<n;i++)
{
    cin>>a[i];
    if(a[i]<mid)
    {
        //int q=x1-1;
       // cout<<q<<" ";
        max[x1++]=a[i];
       // x1++;
        if(max[x1-1]>max[0])
            swap(max[x1-1],max[0]);
    }
    else
    {
          //int p=x2-1;
       // cout<<p<<" ";
        min[x2++]=a[i];
       // x2++;
        if(min[x2-1]<min[0])
            swap(min[x2-1],min[0]);
    }
//for(long long int i=0;i<n;i++)
    //cout<<a[i]<<" ";
if((x1-x2)>1||(x2-x1)>1)
{
    long long int p,q,r,s;
    
    if(x1>x2)
    {   
        swap(max[x1-1],max[0]);
         q=--x1;
        p=x2++;
        min[p]=max[q];
        swap(min[0],min[x2-1]);
        MaxH(max,x1);
    }
    else
    {
        swap(min[x2-1],min[0]);
        s=--x2;
         r=x1++;
        max[r]=min[s];
        swap(max[0],max[x1-1]);
        MinH(min,x2);
    }
    //for(long long int i=0;i<n;i++)
    //cout<<a[i]<<" ";
}
    //cout<<mid<<" ";
if(x1==x2)
{
    mid=double((max[0]+min[0]))/2;
}
    //cout<<mid<<" ";
    
else if(x1>x2)
{
    mid=double(max[0]);
    //cout<<mid<<" ";
    
}
    else
    {
        mid=double(min[0]);
    }
        //cout<<mid<<endl;
cout<<mid<<endl;
    
}
    return 0;

}
   

