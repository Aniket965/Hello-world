#include<iostream.h>
#include<conio.h>
class cashreg
{
	int cash;
	public:
	cashreg()
	{
		cash=500;
	}
	cashreg(int amo)
	{
		cash=amo;
	}
	int getbalance()
	{
		return cash;
	}
	void acceptamo(int x)
	{
		cash+=x;
	}
};
class dispenser
{
	int no,cost;
	public:
	dispenser()
	{
		cost=50;
		no=50;
	}
	dispenser(int x,int y)
	{
		cost=x;
		no=y;
	}
	int getno()
	{
		return no;
	}
	int getcost()
	{
		return cost;
	}
	void makesale()
	{
		--no;
	}
};
void showselec(dispenser a)
{
	int x;
	x=a.getno();
	cout<<"Number of items:"<<x<<endl;
}
void sellpro(dispenser &d,cashreg &c,int x=10)
{
	d.makesale();
	int p;
	c.acceptamo(x);
	p=d.getno();
	cout<<"No of candies left:"<<p<<endl;
}
void main()
{
	clrscr();
	dispenser d;
	cashreg c;
	int ch,x,n,m;
	char ask,ch1;
	do
	{
		cout<<"Candy machine\n";
		cout<<"1.Strawberry candy\n";
		cout<<"2.Green apple candy\n";
		cout<<"3.Blue lagoon candy\n";
		cin>>ch;
		if(ch==1)
		{
			showselec(d);
			cout<<"Cost=Rs.10\n";
			cout<<"Do you wish to buy this candy(y/n)\n";
			cin>>ask;
			if(ask=='y'|ask=='Y')
			{
				sellpro(d,c);
			}
		}
		else if(ch==2)
		{
			showselec(d);
			cout<<"Cost=Rs.15\n";
			cout<<"Do you wish to buy this item\n";
			cin>>ask;
			if(ask=='y'|ask=='Y')
			{
				sellpro(d,c,15);
			}
		}
		else if(ch==3)
		{
			showselec(d);
			cout<<"Cost=Rs.20\n";
			cout<<"Do you wish to buy this item\n";
			cin>>ask;
			if(ask=='y'|ask=='Y')
			{
				sellpro(d,c,20);
			}
		}
		m=d.getno();
		if(m<=0)
		{
			cout<<"Candies out of stock\n";
			ch1='y';
		}
		cout<<"Do you wish to buy more(y/n)\n";
		cin>>ch1;
	}
	while(ch1=='y');
	x=c.getbalance();
	cout<<"Cash in register:"<<x<<endl;
	n=d.getno();
	cout<<"Candies left:"<<n<<endl;
	getch();
}


