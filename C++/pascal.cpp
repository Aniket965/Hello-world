#include <iostream>

using namespace std;

int main()
{
    int n,k;
    int a[10][10];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int space=1;space<=n-i;space++)
        {
           cout<<" ";

        }
        for(int j=1;j<=2*i-1;j++){
            if(j%2==0) {
               cout<<" ";
            }
            else if(j==1 || j== 2*i-1) {
                    a[i][j]=1;
                    cout<<a[i][j];
            }
            else{
                a[i][j] = a[i-1][j-2] + a[i-1][j];
                cout<<a[i][j];
            }

        }
        cout<<"\n";

    }
}

