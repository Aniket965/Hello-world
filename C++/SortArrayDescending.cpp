#include <stdio.h>
#include <iostream>
    int main()
    {
    	using namespace std;
        int number[30];
        int i,j,a,n;
        cin>>n;
        for (i = 0; i < n; i++)
	        cin>>number[i];
        for (i=0;i<n;i++) 
        {
            for (j=i+1;j<n;j++) 
            {
                if (number[i]<number[j]) 
                {
                    a = number[i];
                    number[i] = number[j];
                    number[j] = a;
                }
            }
        }
        cout<<"Array in Descending Order :-"<<endl;
        for (i=0;i<n;i++) 
            cout<<number[i]<<" ";
        return 0;
    }