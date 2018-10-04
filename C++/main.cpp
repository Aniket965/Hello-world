#include<iostream>
using namespace std;

void swap(int *a ,int *b)
   { int temp=*a;
      *a=*b;
      *b=temp;
      }

void sort(int a[],int n)
{
	for (int round = 0; round < n-1; round++)
	{  for (int i = 0; i < n-1- round; i++)
		{
      if (a[i] > a[i + 1])
      swap(&a[i],&a[i+1]);
		}
	}
}
int main()
{
	int arr[100];
	cout << "enter the array" << endl;
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	sort(arr,5);
cout<<"sorted array:"<<endl;
	for (int i = 0; i < 5; i++)
		cout << arr[i] <<" ";
}
