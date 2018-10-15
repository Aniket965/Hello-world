#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cctype>
#include<cmath>
using namespace std;
int main ()
{
  	char letter;
  	char letter1;
  	char letter2;
  	char letter3;
  	char letter4;
  	int a,b;
  	double a1,b1;
  	int result;
  	double result1;
  	cout<<"\n\n\n ***************** SCIENTIFIC CALCULATOR ****************** \n\n\n";
  	do
  	{
    	cout<<"\t 1 : Arithmetic Operations \n";
    	cout<<"\t 2 : Trigonometric Functions \n";
    	cout<<"\t 3 : Logarithmic Functions \n";
    	cout<<"\t 4 : Power Functions \n";
    	cout<<"\t 5 : Exit... \n";
    	letter = getche();
    	switch(letter)
    	{
    	  	case '1':
    	    { 
    	      	cout<<"\n\n";
        	 	cout<<"\t1 : Addition \n";
         		cout<<"\t2 : Subtraction \n";
         		cout<<"\t3 : Multipilication \n";
        		cout<<"\t4 : Division \n\n";
        		letter1 = getche();
          		switch(letter1)
          		{
            		case '1':
            		{
            	    	cout<<"\n\nEnter first number...";
            	    	cin>>a;
            	    	cout<<"Enter an other number...";
            	    	cin>>b;
            	    	result=a+b;
            	    	cout<<"\n\nResult = "<<result<<endl;
            	    	system("pause");
            	    	break;
            		}                 
            		case '2':
            		{
						cout<<"\n\nEnter first number...";
	            		cin>>a;
						cout<<"Enter an other number...";
						cin>>b;
						result=a-b;
						cout<<"\n\nResult = "<<result<<endl;
						system("pause");
						break;
					}
					case '3':
            		{
						cout<<"\n\nEnter first number...";
						cin>>a;
	            		cout<<"Enter an other number...";
						cin>>b;
						result=a*b;
                		cout<<"\n\nResult = "<<result<<endl;
                		system("pause");
                		break;
					}
            		case '4':         
            		{
                		cout<<"\n\nEnter first number...";
						cin>>a;
						cout<<"Enter an other number...";
						cin>>b;
						if(a!=0)
                		{
							result=a/b;
                	    	cout<<"\n\nResult = "<<result<<endl;
                	    	system("pause");
                		}	
                		break;
            		}
        		}
        		break;
    		}// end of arithmatic operation
			case '2':
        	{
        	  	cout<<"\n\n";
    			cout<<"\t1 : Sin function \n";
        		cout<<"\t2 : Cos function \n";
        	  	cout<<"\t3 : Tan function \n";
    			letter2=getche();
  				switch(letter2)
   				{
   					case '1':
    				{	
     					cout<<"\n\n Enter a number...";
     					cin>>a1;
						result1=(sin(a1));
     					cout<<"\n\nResult = "<<result1<<endl;
     					system("pause");
                	 	break;
     				}
    				case '2':
     				{
    					cout<<"\n\n Enter a number...";
     					cin>>a1;
                	    result1=(cos(a1));
      					cout<<"\n\nResult = "<<result1<<endl;
      					system("pause");
      					break;
     				}
   					case '3':
   					{
    					cout<<"\n\n Enter a number...";
    					cin>>a1;
						result1=(tan(a1));
     					cout<<"\n\nResult = "<<result1<<endl;
    					system("pause");
      					break;
      				}
				}	
				break;
        	}//end of trignomatic operation
    		case '3':
        	{
        	    cout<<"\n\n";
    			cout<<"\t1 : Natural log\n";
    			cout<<"\t2 : log with base 10 \n";
    			letter3=getche();
    			switch(letter3)
    			{
    				case '1':
    				{
    					cout<<"\n\n Enter a number...";
    					cin>>a1;
       		            result1=log(a1);
    					cout<<"\n\n Result = "<<result1<<endl;
    					system("pause");
    					break;
   					}
    				case '2':
     				{
    					cout<<"\n\n Enter a number...";
     					cin>>a1;
        	    		result1= log10(a1);
    					cout<<"\n\n Result = "<<result1<<endl;
    					system("pause");
    					break;
     				}
           		}
           		break;
        	}// end of logrithmic operation
    		case '4':
        	{
        	    system("cls");
    			cout<<"1) Press 1 for Power \n";
    			cout<<"2) Press 2 for Square root \n";
    			cout<<"Enter your choice....";
    			letter4=getche();
    			switch(letter4)
    			{
    				case '1':
     				{
      					cout<<"\n\nEnter a number...";
      					cin>>a1;
      					cout<<"Enter power...";
      					cin>>b1;
      					result1=pow(a1,b1);
      					cout<<"\n\nResult = "<<result1<<endl;
      					system("pause");
      					break;
     				}
    				case '2':
     				{
      					cout<<"\n\nEnter a number...";
      					cin>>a;
      					result1=sqrt(a);
      					cout<<"\n\nResult = "<<result1<<endl;
      					system("pause");
      					break;
      				}
      			}
           		break;
        	}// end of power function
		}//end of outer switch
	}while(letter != '5');
	return 0;
}