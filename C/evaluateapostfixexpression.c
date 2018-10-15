#include<stdio.h>
#include<conio.h>
#define MAX 50
char test[MAX];
char pf[50];
int top = -1;
int push(int value);
int pop();
void evpf();
int main()
{
clrscr();
printf("ENTER THE POSTFIX EXPRESSION: ");
scanf("%s", &pf);
evpf();  //FUNCTION TO EVALUATE THE POSTFIX EXPRESSION.
getch();
return 0;
}
int push(int value) //PUSHING IN A STACK.
{
if(top == MAX -1)
	return 0;
else{
	top = top + 1;
	test[top] = value;
	return 1;
	}
}
int pop() //POPPING IN A STACK.
{
if(top == -1)
	return 0;
else{
	return test[top--];
	}
}
void evpf() //POSTFIX EVALUATION.
{
int i, ch, op1, op2;
for(i = 0; (ch = pf[i]) != '\0'; i++)
{
	if( ((int)ch >= 48) && ((int)ch <= 57) )
		push(ch - '0');
	else
	{
		op2 = pop();
		op1 = pop();
		switch(ch)
		{
		  case '+' : push(op1 + op2);
			     break;
		  case '-' : push(op1 - op2);
			     break;
		  case '*' : push(op1 * op2);
			     break;
		  case '/' : push(op1 / op2);
			     break;
		}
	}
}
printf("EVALUATED EXPRESSION: %d", test[top]);
}