#include<iostream>
using namespace std;

class Node 
{
	public:
	int data;
	Node *link;
};

class List : public Node
{
	Node *head = NULL, *tail = NULL;
	
	int count = -1;

	public:

	void create();
	void insert();
	void delet();
	void display();
	void search();
};

void List::create()
{
	Node *temp = new Node();
	
	cout<<"Enter the value:";
	int value;
	cin>>value;

	temp->data = value;	
	temp->link = NULL;
	
	if(head == NULL)
		{
			head = tail = temp;
		}
	else
		{
			tail->link = temp;
			tail = temp;
		}
		
		count++;
}

void List::insert()
	{

		cout<<"INSERT \n1.First\n2.Between\n3.Last"<<endl;
			
		int option;
		cin>>option;

	Node *temp = new Node();
	
		switch(option)
		{
			case 1:
					cout<<"Enter the value:";
					int value;
					cin>>value;

					temp->data = value;	
					temp->link = head->link;
					head = temp;
				
			break;

			case 2:{
					cout<<"Enter the position:";
					int pos;
					cin>>pos;

					Node *pre = head;
					if(pos < count)
						{
							for(int i = 0; i < pos; i++)
								{
									pre = pre->link;			
								}
							cout<<"Enter the value:";
							cin>>value;

							temp->data = value;	
							temp->link = pre->link;
							pre->link = temp;
				
	
					}
				else 
					{
						cout<<"The position is out of range\n";
					}	}	
				break;

			case 3:{
					cout<<"Enter the value:";
					cin>>value;

					temp->data = value;	
					tail->link = temp;
					temp->link = NULL;
					tail = temp;
				}
			break;
		}
		
	}

void List::display()
{
	Node *temp = head;
	int counter = 0;
	
	if(count == 0)
	{
		cout<<"The list is empty"<<endl;
	}
	else
	{
		while(temp !=NULL)
			{
				cout<<"Pos ("<<counter<<")-->"<<temp->data<<endl;
				counter++;
				temp = temp->link;
			}
	 }
	
}

void List::delet()
{
	cout<<"DELETE \n1.First\n2.Between\n3.Last"<<endl;
			
		Node *temp = NULL;

		int option;
		cin>>option;
	    
        Node *pre = head;
		switch(option)
		{
			case 1:
					temp = head;
					head = head->link;
					temp->link = NULL;
					temp = NULL;
				
			break;

			case 2:{
					
                    int pos = 0;
					if(pos < count)
						{
							for(int i = 0; i < pos-1; i++)
								{
									pre = pre->link;			
								}
							temp = pre->link;
							pre->link = pre->link->link;
							temp->link = NULL;
							temp = NULL;
				
	
					}
				else 
					{
						cout<<"The position is out of range\n";
					}	}	
				break;

			case 3:{
						
						for(int i = 0; i < count-1; i++)
								{
									pre = pre->link;			
								}
							temp = pre->link;
							pre->link = pre->link->link;
							temp->link = NULL;
							temp = NULL;

					temp = tail;
					head = head->link;
					temp->link = NULL;
					temp = NULL;
				}
			break;
		}
		
}

void options()
{
	cout<<"Select an option. By pressing the number."<<endl;
	cout<<"1.CREATE\n2.INSERT\n3.Delete\n4.Display\n5.EXIT"<<endl;
}
main()
{
	
	
	
	bool exit = true;
	char input;
	List list;

	while(exit)
		{
		options();
		cin>>input;
		cout<<"You have selected ";
		switch(input)
			{
				case '1': cout<<"(Create)"<<endl;
						list.create();
				break;		
				case '2': cout<<"(Insert)"<<endl;
						list.insert();
				break;		
				case '3': cout<<"(Delete)"<<endl;	
						list.delet();
				break;		
				case '4': cout<<"(Display)"<<endl;
						list.display();
				break;		
				case '5': cout<<"(Exit)"<<endl;
				exit = false;
				break;		
			}
		
		}
}
