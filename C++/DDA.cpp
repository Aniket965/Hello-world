#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
#include<graphics.h>
#include<math.h>

int sign(float a);
void main()
{
	int gd=DETECT,gm;
	int x1,x2,y1,y2,length,i;
	float dx,dy,x[100],y[100];



	cout<<"\n Enter x1 and y1:";
	cin>>x1>>y1;
	cout<<"\n Enter x2 and y2:";
	cin>>x2>>y2;

	dx=fabs(x2-x1);
	dy=fabs(y2-y1);

	if(dx>=dy)
	{
		length=dx;
	}
	else
	{
		length=dy;
	}

	dx=(float)(x2-x1)/length;
	dy=(float)(y2-y1)/length;

       x[0]=x1+0.5*sign(dx);
       y[0]=y1+0.5*sign(dy);
       i=1;

       while(i<=length)
       {
	    //	cout<<i<<(x[i-1])<<(y[i-1]);
		x[i]=x[i-1]+dx;
		y[i]=y[i-1]+dy;
		i++;
       }
       getch();
       initgraph(&gd,&gm,"C:\\TC\\BGI");

       for(i=0;i<=length;i++)
       {
		putpixel(x[i],y[i],11);
       }
       getch();
       closegraph();
}
int sign(float a)
{
	if(a>0)
		return 1;
	else if(a==0)
		return 0;
	else
		return -1;
}
