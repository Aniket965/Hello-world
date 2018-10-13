#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main(int argc,char *argv[])
{  
	string str;
        int k=0;
	str=argv[1];
	int n=(str.length());
	int arr[n];
	int newarr[n];
	for(int i=0;i<n;i++)
	{
		if(str[i]==' ')
		arr[i]=-1;
		else
		arr[i]=str[i]-'0';
	}


	int i=0, j=0;	
	for(int i=0;i<n;i++){
	newarr[i]=0;	
	}


	while(i<n)
	{	
	if(arr[i]!=-1)
	{
		if(newarr[j]==0){
			newarr[j]=arr[i];   k++;}
		else if(newarr[j]/10==0)
			newarr[j]=(newarr[j]*10)+arr[i];
		else if((newarr[j]/10)<10 || (newarr[j]/10)>=0 )
			newarr[j]=(newarr[j]*10)+arr[i];	
	}
	else
	{
		j++;
	}
	i++;
	}
	
	int max=0;
	int min=0;

	 max=newarr[0];
	 min=newarr[0];
	//for(int i=0;n<'\0';i++);
 	//int len=i;
	for (int i=0;i<k;i++)
	{
		if(newarr[i]>max)
			max=newarr[i];
		if(newarr[i]<min)
			min=newarr[i];
	}
	int a=atoi(argv[2]);
	if(a==1)
		cout<<max;
	else if(a==2)
		cout<<min;
	else
	
	return 0;
}
