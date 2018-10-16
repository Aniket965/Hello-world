#include<stdio.h>
#include<conio.h>
struct stu
{ int marks;
  int age;
}st[5][5],ONED[50];

int i,j,m,n,k;

void input()
{
printf("Enter the size of array (m x n)");
scanf("%d %d",&m,&n);
printf("\n Enter the details of students");
for(i=0;i<m;i++)

{
  for(j=0;j<n;j++)
  {

 printf("\n Enter Marks \t");
 scanf("%d",&st[i][j].marks);
 printf("\n Enter age \t");
 scanf("%d",&st[i][j].age);
 }
}
}
void display()
{ k=0;
  printf("\n Display in 2D array \n");

for(i=0;i<m;i++)

{
  for(j=0;j<n;j++)
  {
    printf("%d",st[i][j].marks);
    printf(",");
    printf("%d",st[i][j].age);
    printf(" \t ");
  }
  printf("\n");
}
printf("\n Display the 1D array \n");
for(i=0;i<m;i++)

{
  for(j=0;j<n;j++)
  {
    if(st[j][i].marks !=0 && st[j][i].age!=0)
    { ONED[k].marks=st[j][i].marks;
      ONED[k].age=st[j][i].age;
      k++;
     }
   }
}

for(i=0;i<k;i++)
{
    printf("%d",ONED[i].marks);
    printf(",");
    printf("%d \t",ONED[i].age);
}

}
void main()
{ clrscr();
  input();
  display();
  getch();
}