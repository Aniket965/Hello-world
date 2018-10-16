#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
main()
{
int i,j,k,l,m,b[14000],n,s,f,d,aa,ab,ac,ad,ae,af,g,x,c[80][23];
char ch;
textcolor(0);
textbackground(7);
clrscr();
i=5;j=5;m=1;
for(i=4;i<76;i++)
{for(j=3;j<23;j++)
{c[i][j]=0;}}
clrscr();
gotoxy(35,15);
printf("welcome to snake mania");
getch();
clrscr();
gotoxy(35,14);
printf("instruction");
gotoxy(35,15);
printf("press w - up");
gotoxy(42,16);
printf("s-down");
gotoxy(42,17);
printf("a-left");
gotoxy(42,18);
printf("d-right");
gotoxy(42,19);printf("q-qiut");
start:
clrscr();
gotoxy(35,14);
printf("choose number to select level");
gotoxy(38,16);
printf("1)easy");
gotoxy(38,17);
printf("2)medium");
gotoxy(38,18);
printf("3)hard");
gotoxy(39,19);
printf("4)professional");
ch=getch();
if(ch=='1')
{s=400;}
else if(ch=='2')
{s=300;}
else if(ch=='3')
{s=100;}
else if(ch=='4')
{s=75;}
else{goto start;}
clrscr();
for(i=4;i<76;i++)
{gotoxy(i,3);printf("-");gotoxy(i,23);printf("-");}
for(j=3;j<=23;j++)
{gotoxy(3,j);printf("|");gotoxy(76,j);printf("|");}
gotoxy(5,1);printf("score=0   ");
gotoxy(50,24);printf("devolped by earnest");
x=0;
i=10;j=10;m=1;
for(n=0;n<5;n++)
{i=i+1;gotoxy(i,j);c[i][j]=1;b[m]=(i*100)+j;printf("*");m=m+1;}
n=5;
f=0;
goto food1;
game:
left:
f=1;
while(!kbhit())
{i=i+1;if(i>75||j>22||j<4||i<4){goto gameover;}
if(c[i][j]==1){goto gameover;}
if(i==aa&&j==ab){goto increase;}
gotoxy(i,j);c[i][j]=1;b[m]=(i*100)+j;printf("*");d=b[m-n];k=d/100;l=d%100;
gotoxy(k,l);printf(" ");c[k][l]=0;delay(s);m=m+1;}
ch=getch();
if(ch=='a')
{goto left;}
goto choice;
right:
f=2;
while(!kbhit())
{i=i-1;if(i>75||j<4||i<4||j>22){goto gameover;}
if (c[i][j]==1){goto gameover;}
if(i==aa&&j==ab){goto increase;}
gotoxy(i,j);c[i][j]=1;b[m]=(i*100)+j;printf("*");d=b[m-n];k=d/100;l=d%100;
gotoxy(k,l);printf(" ");c[k][l]=0;delay(s);m=m+1;}
ch=getch();
if(ch=='d')
{goto right;}
goto choice;
up:
f=3;
while(!kbhit())
{j=j-1;if(i<4||i>75||j>22||j<4){goto gameover;}
if(c[i][j]==1){goto gameover;}
if(i==aa&&j==ab){goto increase;}
gotoxy(i,j);c[i][j]=1;b[m]=(i*100)+j;printf("*");d=b[m-n];k=d/100;l=d%100;
gotoxy(k,l);printf(" ");c[k][l]=0;delay(s);m=m+1;}
ch=getch();
if(ch=='s'){goto up;}
goto choice;
down:
f=4;
while(!kbhit())
{j=j+1;if(i<4||i>75||j>22||j<4){goto gameover;}
if(c[i][j]==1){goto gameover;}
if(i==aa&&j==ab){goto increase;}
gotoxy(i,j);c[i][j]=1;b[m]=(i*100)+j;printf("*");d=b[m-n];k=d/100;l=d%100;
gotoxy(k,l);printf(" ");c[k][l]=0;delay(s);m=m+1;}
ch=getch();
if(ch=='w'){goto down;}
choice:
if(ch=='w'){goto up;}
else if(ch=='s'){goto down;}
else if(ch=='a'){goto right;}
else if(ch=='d'){goto left;}
else if(ch=='q'){goto exit;}
else {if(f==1){goto left;}
else if(f==2){goto right;}
else if(f==3){goto up;}
else{goto down;}}
food1:
randomize();
aa=(rand()%100);
if(aa<=3){goto food1;}
if(aa>=76){goto food1;}
randomize();
ab=(rand()%30);
if(ab<=3){goto food1;}
else if(ab>=23){goto food1;}
gotoxy(aa,ab);printf("*");
if(f==0){goto game;}
if(f==1){goto left;}
if(f==2){goto right;}
if(f==3){goto up;}
else{goto down;}
increase:
if(f==1){b[m]=(i*100)+j;gotoxy(i,j);printf("*");m=m+1;n=n+1;gotoxy(5,1);x=x+1;printf("score=%d",x);goto food1;}
if(f==2){b[m]=(i*100)+j;gotoxy(i,j);printf("*");m=m+1;n=n+1;x=x+1;gotoxy(5,1);printf("score=%d",x);goto food1;}
if(f==3){b[m]=(i*100)+j;gotoxy(i,j);printf("*");m=m+1;n=n+1;x=x+1;gotoxy(5,1);printf("score=%d",x);goto food1;}
else{b[m]=(i*100)+j;gotoxy(i,j);printf("*");m=m+1;n=n+1;x=x+1;gotoxy(5,1);printf("score=%d",x);goto food1;}
gameover:
clrscr();
gotoxy(35,10);
printf("game over");
gotoxy(30,11);
printf("your score=%d",x);
gotoxy(30,12);
printf("press key to continue");
getch();
goto exit;
exit:
clrscr();
gotoxy(32,11);
printf("do you want to quit(y/n)");
ch=getch();
if(ch=='n')
{goto start;}
else if(ch=='y')
{clrscr();gotoxy(35,11);printf("thanks for playing");getch();goto qiut;}
else{goto exit;}
qiut:
getch();
return 0;
}
