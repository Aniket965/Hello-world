#include <iostream>
using namespace std;

int main() {
    string line;
    cout << "Enter a string: ";
    getline(cin, line);

    for(int i = 0; i < line.size(); ++i)
    {
        if (!((line[i] >= 'a' && line[i]<='z') || (line[i] >= 'A' && line[i]<='Z')))
        {
            line[i] = '\0';
        }
    }
    cout << "Output String: " << line;    
    return 0;
}
