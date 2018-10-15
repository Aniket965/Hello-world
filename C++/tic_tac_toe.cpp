#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

char tic[3][3];
int flag=1;
int player=1;
int count1=0;

int win()
{
    if(player==2)
    {

        if((tic[0][0]=='X'&&tic[1][1]=='X'&&tic[2][2]=='X')||(tic[0][0]=='X'&&tic[0][1]=='X'&&tic[0][2]=='X')||(tic[1][0]=='X'&&tic[1][1]=='X'&&tic[1][2]=='X')||(tic[2][0]=='X'&&tic[2][1]=='X'&&tic[2][2]=='X')||(tic[0][2]=='X'&&tic[1][1]=='X'&&tic[2][0]=='X')||(tic[2][0]=='X'&&tic[2][1]=='X'&&tic[2][2]=='X')||(tic[0][0]=='X'&&tic[1][0]=='X'&&tic[2][0]=='X')||(tic[0][1]=='X'&&tic[1][1]=='X'&&tic[2][1]=='X')||(tic[0][2]=='X'&&tic[1][2]=='X'&&tic[2][2]=='X'))
           {
               return 1;
           }
    }
    else if(player==1)
    {

        if((tic[0][0]=='O'&&tic[1][1]=='O'&&tic[2][2]=='O')||(tic[0][0]=='O'&&tic[0][1]=='O'&&tic[0][2]=='O')||(tic[1][0]=='O'&&tic[1][1]=='O'&&tic[1][2]=='O')||(tic[2][0]=='O'&&tic[2][1]=='O'&&tic[2][2]=='O')||(tic[0][2]=='O'&&tic[1][1]=='O'&&tic[2][0]=='O')||(tic[2][0]=='O'&&tic[2][1]=='O'&&tic[2][2]=='O')||(tic[0][0]=='O'&&tic[1][0]=='O'&&tic[2][0]=='O')||(tic[0][1]=='O'&&tic[1][1]=='O'&&tic[2][1]=='O')||(tic[0][2]=='O'&&tic[1][2]=='O'&&tic[2][2]=='O'))
           {
               return 2;
           }

    }
    return 0;

}
int main()
{
    int i,j;
    int i1,j1;

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        tic[i][j]='_';

        while(!win())
        {
            if(count1==9)
            {
                break;
            }
               for(i=0;i<3;i++)
                {
                  for(j=0;j<3;j++)
                   {
                     cout<<tic[i][j]<<"|";
                   }
                cout<<endl;
               }

             if(player==1)
               {
                cout<<"\nIT IS CHANCE OF PLAYER 1:"<<endl<<"WRITE THE X Y WHERE YOU WANT TO PLACE 'X':";
               cin>>i1>>j1;
                  if(tic[i1-1][j1-1]=='_')
                {tic[i1-1][j1-1]='X';
                 player++;
                 count1++;
                 }
                else
                    cout<<"\nTHE PLACE IS ALREADY OCCUPIED!! PLEASE ENTER COORDINATES AGAIN\n";
               }

                   else if(player==2)
               {
                cout<<"\nIT IS CHANCE OF PLAYER 2:\n"<<endl<<"WRITE THE X Y WHERE YOU WANT TO PLACE 'O':\n";
            cin>>i1>>j1;
            if(tic[i1-1][j1-1]=='_')
            {tic[i1-1][j1-1]='O';
            player--;
            count1++;
            }
                else
            {
                cout<<"\nTHE PLACE IS ALREADY OCCUPIED!! PLEASE ENTER COORDINATES AGAIN\n";

            }
               }



        }
          for(i=0;i<3;i++)
                {
                  for(j=0;j<3;j++)
                   {
                     cout<<tic[i][j]<<"|";
                   }
                cout<<endl;
               }
    int result=win();
    if(result==1)
        cout<<"\nPLAYER 1 WON!!!";
    else if(result==2)
        cout<<"\nPLAYER 2 WON!!";
    else
        cout<<"MATCH WAS DRAWN!!!!";


        return 0;

}
