#include<conio.h>
#include<stdio.h>
#define max 5
int deque[max] ,left = -1, right = -1;
void insert_deque();
void delete_deque();
void insert_left();
void insert_right();
void delete_left();
void delete_right();
void display();

void main()
{
  int option;
  printf("\n MAIN MENU \n 1.Insertion restricted DEQUE \n 2. Deletion restricted DEQUE \n 3.EXIT \n");
  printf("Enter your choice\n");
  scanf("%d", &option);
  
   switch(option)
    {
         case 1: insert_deque();
     		break;
         case 2: delete_deque();
    		break;
 
    }    
 
 getch();   
}

void insert_deque()
{
  int option;   
  do
  {
      printf("\n INPUT RESTRICTED DEQUE \n 1.Insertion from right \n 2.Deletion from right \n 3.Deletion from left \n 4.Display \n 5.EXIT \n");
      printf("Enter your choice\n");
      scanf("%d", &option);
      
      
        switch(option)
        {    
        	case 1: insert_right();
        		break;
        	case 2: delete_right();
        		break;
        	case 3: delete_left();
        		break;
        	case 4: display();
        		break;
        }
  }while(option!=5);
}

void delete_deque()
{
  int option;
  do
   {
      printf("\n OUTPUT RESTRICTED DEQUE \n 1.Insertion from left \n 2.Insertion from right \n 3.Deletion from left \n 4.Display \n 5.EXIT \n");
      printf("Enter your choice\n");
      scanf("%d", &option);
      
      
        switch(option)
        {
        	case 1: insert_left();
        		break;
        	case 2: insert_right();
        		break;
        	case 3: delete_left();
        		break;
        	case 4: display();
        		break;
        }
        
  }while(option!=5);
}


void insert_right()
{
    
      int val;
      printf("Enter the value to be inserted= ");
      scanf("%d",&val);
      if((left == 0 && right == max-1) || (left = right+1))
       {
         printf(" The Queue IS OVERFLOW ");
         return ;
       }
      if(left == -1)
         {
          right=left=0;
         } 
      else
        {
          if(right == max-1)
           {     
                right = 0;
           }
          else
           {
                right+=1;
           }
        }
      deque[right] = val;
}

void insert_left()
{
  int val;
      printf("Enter the value to be inserted = ");
      scanf("%d",&val);
      if((left == 0 && right == max-1) || (left = right))
       {
             printf(" The Queue IS OVERFLOW ");
             return ;
       }
      if(left == -1)
        {
             right= left= 0;
        }
      else
        {
             if(left == max-1)
              {
                   left=0; 
              }
             else
              {
                   left-=1;
              }
        }
  deque[left] = val;
}


void delete_right()
{
     if(left == -1 && right == -1)
      {
           printf("The Queue Is UNDERFLOW");
           return ;
      }
    printf("\n The Deleted Number is %d ", deque[right]);
     if(right == left)
        {
             right = left = -1;
        }
      else
        {
             if(right == 0)
              {
               right = max-1;
              }
             else
              {
               right-=1;
              }
        }
}

void delete_left()
{
     if(left == -1 && right == -1)
      {
           printf("\n The Queue Is UNDERFLOW");
           return ;
      }
    printf("\n The Deleted Number is %d ", deque[left]);
     if(left == right)
        {
             right = left = -1;
        }
      else
        {
             if(left == max-1)
              {
                   left = 0;
              }
             else
              {
                   left+=1;
              }
        }
}

void display()
{
     int front=left, rear=right, i;
     if(front == -1 && rear == -1)
      {
           printf("\n The Queue Is EMPTY");
           return ;
      } 
      else
      {
            printf("\n The Elements Of The QUEUE are : ");
            for(i=0;i<=max-1;i++)
        			printf("%d\t",deque[i]);
      }   
    
}
