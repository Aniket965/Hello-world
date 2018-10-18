// CODING IN TURBO C++ //

**  PRINTING OF “HELLO WORLD !!” **

( USING LOWER & UPPER TRAINGLE OF A MATRIX)

#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int i,j,a[10][10],r,c;
 cout<<"                       ### Showing Hello World !!!  ###\n";
 cout<<"                  ---XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX---";
 cout<<"\n Enter Rows: ";
 cin>>r;
 cout<<"\n Enter Columns: ";
 cin>>c;
 cout<<"--------------------------------------------------------------------------------\n";
 cout<<"                          ";
  for(i=0;i<r;i++)
 { for(j=0;j<c;j++)
  { if(i>=j)
    cout<<"*";
    else cout<<" ";
  }
  cout<<"                                                                           ";
 }
 cout<<"\n      HELLO WORLD !! \n";
 cout<<"                                         ";
  for(i=0;i<r;i++)
 { for(j=0;j<c;j++)
   {
    if(i<=j)
    cout<<"*";
    else
    cout<<" ";
  }
  cout<<"                                                                              ";
 }
 cout<<"                                    --------------------------------------------------------------------------------				";
 getch();
}









