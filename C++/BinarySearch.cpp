#include <iostream>
#include <conio.h>

using namespace std;

int binarySearch(int num,int ary[100],int len)
{
	int first=0,last=len-1,mid=0;
	int idNum=-1;
	while (first<=last)
	{
		mid=(last+first)/2;
		if(num==ary[mid])
		{
			idNum=mid;
			break;
		}
		if(num>ary[mid])
			first=mid+1;
		if(num<ary[mid])
			last=mid-1;
	}
	return idNum;
}
