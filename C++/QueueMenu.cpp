#include <iostream>
#define max 10

using namespace std;

struct queue
{
	int data[max];
	int head;
	int tail;
};

queue antrian;

void create()
{
	antrian.head=antrian.tail=-1;
}

int isempty()
{
	if(antrian.tail==-1) return 1;
	else return 0;
}

int isfull()
{
	if(antrian.tail==max-1) return 1;
	else return 0;
}

void enqueue(int data)
{
	if(isempty()==1)
	{
		antrian.head=antrian.tail=0;
		antrian.data[antrian.tail]=data;
		cout<<antrian.data[antrian.tail]<<" added !"<<endl;
	}
	
	else
	{
		if(isfull()==0)
		{
			antrian.tail++;
			antrian.data[antrian.tail]=data;
			cout<<antrian.data[antrian.tail]<<" added !"<<endl;
		}
	}
}

int dequeue()
{	
	int e = antrian.data[antrian.head];
	for(int i = antrian.head; i<=antrian.tail-1;i++)
	{
		antrian.data[i] = antrian.data[i+1];
	}
	antrian.tail--;
	return e;
}

void tampil()
{
	if(isempty()==0)
	{
		for(int i=antrian.head;i<=antrian.tail;i++)
		{
			cout<<"Number : "<<antrian.data[i]<<endl;		
		}
	}
	
	else
	{
		cout<<"no data"<<endl;
	}
}

void clear()
{
	antrian.head=antrian.tail=-1;
	cout<<"data clear\n";
}

int main() 
{
	int opt, angka;	
	create();
	
	do
	{
		system("cls");
		cout<<"          Queue Program          \n";
		cout<<"  ===============================\n";
		cout<<"  =   1. Enqueue                =\n";
		cout<<"  =   2. Dequeue                =\n";
		cout<<"  =   3. Show                   =\n";		
		cout<<"  =   4. Clear All              =\n";
		cout<<"  =   5. Exit                   =\n";
		cout<<"  ===============================\n\n";
		cout<<"  Enter your choice : "; cin>>opt;
		
		
		switch(opt)
		{
			
			case 1: system("cls");
			{
				cout<<"Number : "; 
				cin>>angka;
				enqueue(angka);				
				break;
			}
			
			case 2: system("cls");
			{
				cout<<dequeue()<<" removed";
				break;
			}
			
			case 3: system("cls");
			{
				tampil();				
				break;
			}
			
			case 4: system("cls");
			{
				clear();
				break;
			}
			
			case 5: system("cls");
			
			
			{
				cout<<"Created by Alvin Tandiardi";
				return 0;								
			}
			
			default : system ("cls");
			{
            	cout<<"\n Sorry, Your choice not available\n\n";
            	break;
            }
		}
		cout<<endl;
		system("pause");
		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	}
	
	while(opt!=5);
	
	return 0;
}
