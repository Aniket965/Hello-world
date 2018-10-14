#include<iostream>
#include<string>
using namespace std;

int main(void){
    string name;
    // Get username
    cout << "Enter Username:";
    getline(cin,name);
    // Print hello message
    cout << "Hello, " << name << "!" << endl;
    return 0;
}
