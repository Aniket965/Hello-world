#include<iostream.h>
#include<conio.h>

void  main()
{
    clrscr();
    int n,a[100]][100], temp;
    cout<<"\nenter the size of array";
    cin>>n;
    cout<<"\nenter the array";
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        cin>>a[i][j];
    }
    
    for(i=0;i<n;i++)
    {
        int flag = 0;
        for(j=0;j<n-i+1;j++)
        {
            if(a[i]>a[j])
            {
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
                flag = 1;
            }
        }
        // Break out of loop if no swaps are made in a particular outer iteration
        if(!flag)
            break;
    }
    cout<<"\nSORTED ARRAY";
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        cout>>a[i][j];
    }
    getch();
}
