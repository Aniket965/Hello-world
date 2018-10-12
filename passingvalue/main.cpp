#include <iostream>

using namespace std;


int ajeet(int arr[],int length);

int main()
{
     int l2;
     cout<<"enter length of the array:";
    cin>>l2;
    int arr2[l2];

    int counter;

    for(counter=0 ; counter<l2; counter ++)
    {
        cin>>arr2[counter];
    }

    ajeet(arr2 , l2);
    return 0;
}




int ajeet(int arr[],int length)
{
    int counter;
    for(counter=0 ; counter<length ; counter++)
    {
        cout<<arr[counter]<<endl;
    }
}
