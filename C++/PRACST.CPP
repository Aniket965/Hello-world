#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
struct stud
{
	int rollno;
	char name[40];
};
const int max=20;
stud s[max],s1;
int top=-1;
void push(stud s[],stud ele)
{
	if(top==-1)
	{
		top=0;
		s[top]=ele;
	}
	else if(top==max-1)
	{
		cout<<"Overflow\n";
	}
	else
	{
		s[++top]=ele;
	}
}
void pop()
{
	if(top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{
		cout<<"popping\n";
		--top;
	}
}
void traverse(stud s[],int top)
{
	if(top==-1)
	{
		cout<<"Underflow \n";
	}
	else
	{
		for(int i=top;i>=0;i--)
		{
			cout<<s[i].rollno;
			puts(s[i].name);
		}
	}
}
void main()
{
	clrscr();
	int ch;
	do
	{
		cout<<"1.For pushing data\n";
		cout<<"2.For popping data\n";
		cout<<"3.For traversing the list\n";
		cout<<"4.EXIT\n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the data\n";
			cin>>s1.rollno;
			gets(s1.name);
			push(s,s1);
		}
		else if(ch==2)
		{
			pop();
		}
		else if(ch==3)
		{
			traverse(s,top);
		}
		else if(ch==4)
		{
			exit(0);
		}
	}
	while(ch>=1&&ch<=4);
}


