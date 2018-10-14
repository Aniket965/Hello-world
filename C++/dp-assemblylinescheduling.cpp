#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Give number of stations ";
cin>>n;

int a[2][n];
cout<<"Give ass1"<<endl;
for(int i=0;i<n;i++){
cin>>a[0][i];
}
cout<<"Give ass2"<<endl;
for(int i=0;i<n;i++){
cin>>a[1][i];
}

int t[2][n];
t[0][0]=0;t[1][0]=0;
cout<<"Give t1"<<endl;
for(int i=1;i<n;i++){
cin>>t[0][i];
}
cout<<"Give t2"<<endl;
for(int i=1;i<n;i++){
cin>>t[1][i];
}

int e1,e2,x1,x2;
cout<<"Five e1,e2,x1,x2 :";
cin>>e1>>e2>>x1>>x2;
int A[n],B[n];

A[0]=e1+a[0][0];
B[0]=e2+a[1][0];
int path1[n];
int path2[n];

for(int i=1;i<n;i++){
//A[i]=min(A[i-1]+a[0][i],B[i-1]+a[0][i]+t[1][i]);
//B[i]=min(B[i-1]+a[1][i],A[i-1]+a[1][i]+t[0][i]);
if(A[i-1]+a[0][i]<=B[i-1]+a[0][i]+t[1][i]){A[i]=A[i-1]+a[0][i]; path1[i]=1;}
else {A[i]=B[i-1]+a[0][i]+t[1][i]; path1[i]=2;}

if(B[i-1]+a[1][i]<=A[i-1]+a[1][i]+t[0][i]){B[i]=B[i-1]+a[1][i]; path2[i]=2;}
else {B[i]=A[i-1]+a[1][i]+t[0][i]; path2[i]=1;}
}

int pf;
if(A[n-1]+x1<=B[n-1]+x2) pf=1;
else pf=2;

int ans=min(A[n-1]+x1,B[n-1]+x2);
cout<<"Minimum cost is "<<ans<<endl;


cout<<"Path is :"<<endl;
cout<<"Part "<<n<<" on line "<<pf<<endl;

for(int j=n-1;j>0;j--){
if(pf==1)	pf=path1[j];
else pf=path2[j];
cout<<"Part "<<j<<" on line "<<pf<<endl;
}
return 0;
}
