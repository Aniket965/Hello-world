#include<iostream>
char exp[401],stack[401];
int top;
using namespace std;
void push(char c)
{
	top++;
	stack[top]=c;
}
void pop()
{
	while(stack[top]!='(')
	{
		cout<<stack[top];
		top--;
	}
	top--;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		top=-1;
		cin.ignore();
		cin>>exp;
		for(int i=0;exp[i]!='\0';i++)
		{
			if(exp[i]=='(')
				push(exp[i]);
			else if(exp[i]>=97 && exp[i]<=123)
				cout<<exp[i];
			else if(exp[i]=='+' || exp[i]=='/' || exp[i]=='*' || exp[i]=='-' || exp[i]=='^')
				push(exp[i]);
			else if(exp[i]==')')
				pop();		
		}
		cout<<endl;	
	}
	return 0;
}
