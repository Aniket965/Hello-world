#include<stdio.h>
#include<conio.h>
#define MAX 50
int stack[MAX], value, top=-1;
//PUSHING IN A STACK.
void push()
{
 if(top==MAX-1)
   printf("STACK OVERFLOW!!\n");
 else
  {
   top++;
   stack[top]=value;
  }
}
//POPPING IN A STACK.
void pop()
{
 if(top==-1)
 {
  printf("STACK UNDERFLOW!!\n");
 }
 else
 {
  printf("VALUE BEING POPPED: %d", stack[top]);
  top--;
 }
}
//DISPLAY.
void display()
{
int i;
if(top==-1)
{
printf("EMPTY STACK.\n");
}
else
{
printf("STACK:\n");
for(i=0;i<=top;i++)
printf("%d\t",stack[i]);
}
}
int main()
{
int ch;
clrscr();
while(1)
{
printf("\n\nSTACK MENU");
printf("\n1. PUSH.");
printf("\n2. POP.");
printf("\n3. DISPLAY.");
printf("\nPRESS ANY OTHER KEY TO EXIT\n");
scanf("%d",&ch);
switch(ch)
 {
  case 1 :  printf("ENTER THE VALUE: ", stack[top]);
	    scanf("%d",&value);
	    push();
	    break;
  case 2 :  pop();
	    break;
  case 3 :  display();
	    break;
  default : exit(0);
 }
}
getch();
return 0;
}