#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    int max, random_number, i;

    cout << "Welcome to the Random Number Generator." << endl;
    cout << "Please input the max number: ";
    cin >> max;

    srand(time(0));
    random_number = (rand() % max) + 1;

    cout << random_number << endl;

    return 0;
}