#include<iostream>

using namespace std ;

int main()
{
	int T, n1,n2,n3,smallest,largest;
	//cout<<"Enter the number of testcases";
	cin>>T;
	while (T--)
	{
	  //cout<<"Enter three numbers";
	  cin>>n1>>n2>>n3;
	
	  if(n1 < n2 && n1 < n3)
		smallest=n1;
	  else if(n2 < n3)
		smallest = n2;
	  else
		smallest = n3;
		
      if( n1>=n2 && n1>=n3 )
        largest= n1 ;
 
      if( n2>=n1 && n2>=n3 )
         largest= n2;

      if( n3>=n1 && n3>=n2 )
          largest = n3;
         //cout<<largest <<endl<< smallest<<endl;  
        
      if( n1 < largest && n1 > smallest )
         cout<<n1<<endl;
      if(n2<largest && n2>smallest)
         cout<<n2<<endl;
      if(n3<largest && n3>smallest)
          cout<<n3<<endl;
	}
	return 0;
}
