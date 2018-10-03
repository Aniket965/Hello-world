#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
struct customer
{
	int cnum;
	char cname[30];
};
const int max=20;
customer c[10];
int front=-1,rear=-1;
void insert(customer c[],customer ele)
{
	if(front==-1)
	{
		front=rear=0;
		c[0]=ele;
	}
	else if(rear==max-1)
	{
		cout<<"Over flow\n";
	}
	else
	{
		c[++rear]=ele;
	}
}
int del()
{
	if(front==-1)
	{
		cout<<"underflow\n";
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front++;
	}
}
void display(customer c[],int front,int rear)
{
	if(front==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{
	for(int i=front;i<=rear;i++)
	{
		cout<<c[i].cnum;
		puts(c[i].cname);
	}
	}
	/*cout<<c[rear].cnum;
	puts(c[i].cname);*/
}
void main()
{
	clrscr();
	int ch;
	customer c1;
	do
	{
		cout<<"1.Insertion\n";
		cout<<"2.Deletion\n";
		cout<<"3.Display\n";
		cout<<"4.EXIT\n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the data of the customer\n";
			cout<<"1.Customer Number\n";
			cout<<"2.Customer name\n";
			cin>>c1.cnum;
			gets(c1.cname);
			insert(c,c1);
			getch();
		}
		else if(ch==2)
		{
			cout<<"Deletion\n";
			del();
			getch();
		}
		else if(ch==3)
		{
			cout<<"Dispalying\n";
			display(c,front,rear);
			getch();
		}
		else if(ch==4)
		{
			exit(0);
		}
	}
	while(ch>=1&&ch<=4);
}

