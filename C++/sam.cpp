#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int num,a[100],sum=0,c;
    cout << "Enter the no. of numbers you want to add";
    cin >> num;
    cout << "Enter the numbers"; 
    
    for( c=1;c<=num;c++ )
    {
        cin >> a[c];
        sum=sum+a[c];

    }
    cout << "Sum is"<<sum;
        return 0;
}