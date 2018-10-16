#include<stdio.h>
#include<iostream>
using namespace std;
#define max 5
int que[max],front=-1,rear=-1;
void enqueue(int val)
{
	if(front==0 && rear==max-1)
	{
		cout<<"Overflow";
		return;
	}	
	else if(front==-1 && rear==-1)
		front=rear=0;
	else if(rear==max-1 && front!=0)
		rear=0;
	else
		rear++;
	que[rear]=val;
}
void dequeue()
{
	if(front==-1)
	{
		cout<<"Underflow";
		return;
	}
	cout<<"Deleted value is "<<que[front];
	que[front]=0;
	if(front==rear)
		front=rear=-1;
	else if(front==-1)
		front=0;
	else
		front++;
}
void display()
{
	int i;
	if(front==-1)
		cout<<"Circular Queue is empty";
	else
		for(i=0;i<=max-1;i++)
			cout<<"\t"<<que[i];
}
int main()
{

	int val,option;
	do
	{
		cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Exit";
		cout<<"\nEnter your option:";
		cin>>option;
		switch(option)
		{
		case 1: cout<<"Enter the value to be added:";
			 cin>> val ;
			enqueue(val);
			break;
		case 2:dequeue();
		break;
		case 3:display();
		break;
		case 4:break;
		default:cout<<"Invalid";
		}
	}while(option!=4);
	
	return 0;
}
