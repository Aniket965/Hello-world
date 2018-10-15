#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char ans = 'N';
    char size = ' ';
    double priceM = 9.99, priceL = 12.99;
    double total = 0.0;
    int getCoupon = 0;

    cout << "Would you like to use the $2 coupon for this order? Y/N " << endl;
    cin >> ans;

    if (ans == 'N')
    {
        total += 0;
    }
    else
    {
        total -= 2;
    }
    while (1)
    {
        cout << "Would you like to order a large pizza or a medium pizza & press -1 to stop: L/M ";
        cin >> size;

        if (toupper(size) == 'L')
    {
        total += priceL;
        getCoupon = 1;
    }
        else if (toupper(size) == 'M')
    {
       total += priceM;
    }
        else
    {
            cout << "This is your price: $" << total << setprecision(2) << endl;
                if (getCoupon)
        {
                cout << "You get a coupon!" << endl;
        }
        return 0;
    }
    }
}
