#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5
void push(int *CQUEUE,int x);
void pop(int *CQUEUE);
void display(int *CQUEUE);
int FRONT=-1;
int REAR=-1;
int CQUEUE[SIZE];
void main()
{
      int x,ch;
      clrscr();
      while(1)
      {
          printf("Select Your Choice:\n");
          printf("(1) PUSH\n");
          printf("(2) POP\n");
          printf("(3) Display\n");
          printf("Enter Your Choice\n");
          scanf("%d",&ch);
          switch(ch)
          {
              case 1:
                   printf("Enter Element:");
                   scanf("%d",&x);
                    push(CQUEUE,x);
                   break;
              case 2:
                   pop(CQUEUE);
                   break;
              case 3:
                   display(CQUEUE);
                   break;
              case 4:
                   exit(0);
          }
}
}
void push(int *CQUEUE,int x)
{
      if(REAR>=SIZE-1 && FRONT==0)
          printf("Circular Queue is Overflow");
      else
      {
          if (REAR==-1 && FRONT==-1)
          {
              FRONT=0;
              REAR=0;
          }
          else if (REAR==SIZE-1 && FRONT!=0)
              REAR=0;
          else
              REAR=REAR+1;
          CQUEUE[REAR]=x;
      }
}
void pop(int *CQUEUE)
{
      if(FRONT==-1)
      printf("Circular Queue is Underflow");
      else
      {
          printf("Deleted Element is %d\n",CQUEUE[FRONT]);
          if(FRONT==REAR)
          {
              FRONT=-1;
              REAR=-1;
          }
          else
          {
              if(FRONT==SIZE-1)
              FRONT=0;
              else
              FRONT=FRONT+1;
          }
      }
}
void display(int *CQUEUE)
{
      int i;
      if(FRONT==-1)
      printf("Circular Queue is Empty\n");
      else if(REAR>=FRONT)
      {
          for(i=FRONT;i<=REAR;i++)
          printf("%d\n",CQUEUE[i]);
      }
      else
      {
          for(i=FRONT;i<=SIZE-1;i++)
          printf("%d\n",CQUEUE[i]);
          for(i=0;i<=REAR;i++)
          printf("%d\n",CQUEUE[i]);
      }
}
