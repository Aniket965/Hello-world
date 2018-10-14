#include <iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n,k,l=-1,r;
    cout<<"enter the value of rows(above 0):\n";
	while(1){
		cin>>n;
		if(n>0)
			break;
		cout<<"make sure that the rows is more than 0\n\n";
	}

    for(int i=1;i<=n;i++)
    {
        for(int space = 1;space<=n-i;space++) {
            cout<<"  ";
        }

        for(int j=1;j<=2*i-1;j++)
        {

            cout<<"* ";
        }
        cout<<"\n";

   }
    int a = pow(2, n);
	cout<<"total number of stars used = "<<a<<endl;
}
