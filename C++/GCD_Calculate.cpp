#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3, n4, c, max;
    cout<<"1. HCF\n";
    cout<<"2. LCM\n";
    cout<<"choice: ";
    cin>>c;
    if(c==1)
    {
        cout << "Enter two numbers: ";
        cin >> n1 >> n2;
    
        while(n1 != n2)
        {
            if(n1 > n2)
                n1 -= n2;
           else
                n2 -= n1;
        }

        cout << "HCF = " << n1;
    }
    else
    {
    
        cout << "Enter two numbers: ";
        cin >> n3 >> n4;
    
    // maximum value between n1 and n2 is stored in max
        max = (n1 > n2) ? n1 : n2;

        do
        {
            if (max % n1 == 0 && max % n2 == 0)
            {
                cout << "LCM = " << max;
                break;
            }
            else
                ++max;
        }while (true);
    }
        return 0;
    
}
