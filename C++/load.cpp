#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<string.h>

void main()
{
    clrscr();
    char a[10];
    cin>>a;
    int n=strlen(a);
   
    for(i=0;i<4;i++)
    {
         clrscr();
        gotoxy(35,12);
        for(j=0;j<n;j++)
        {
            cout<<a[j];
            delay(200);
        }
       

    }
    getch();
    
}
