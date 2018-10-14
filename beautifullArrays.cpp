//beautifullArrays.cpp

#include <iostream>

using namespace std;

bool search(long long a[],int n,int key)
{
    for(long i=0; i<n; i++)
    {
        if(a[i]==key)
        {
            return true;
        }
    }
    return false;
}


int main()
{

    long t;
    cin>>t;
//naive algorithm
    // while(t--)
    // {
    //     long n;
    //     cin>>n;
    //     long long a[n];

    //     for(long i=0; i<n; i++)
    //         cin>>a[i];



    //     bool buti=true;

    //     for(long i=0; i<n; i++)
    //     {   for(long k=i+1; k<n; k++)
    //         {
    //             int key=a[i]*a[k];
    //             buti=search(a,n,key);
    //             if(buti==false)
    //             {
    //                 cout<<"no\n";
    //                 break;
    //             }
    //         }

    //         if(buti==false)
    //         {
    //             break;
    //         }
    //     }

    //     if(buti==true)cout<<"yes\n";
    // }

    while(t--)
    {
        int n;
        cin>>n;

        int count0=0,count1=0,countneg1=0,countOther=0;

        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
            if(a==0)count0++;
            else if(a==1)count1++;
            else if(a==-1)countneg1++;
            else countOther++;

        }

        if(countOther>1)cout<<"no\n";
        else if(countneg1 && countOther)cout<<"no\n";
        else if(countneg1>1&& count1==0)cout<<"no\n";
        else cout<<"yes\n";
    }
}