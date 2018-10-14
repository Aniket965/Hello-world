#include <iostream>
#include <algorithm>
#include <string>

int main()
{
 std::string str;
 std::cout << "Enter any string :";
 std::cin >> str;

 std::reverse(str.begin(), str.end());

 std::cout<< "Reverse string is: " << str << '\n';

 return 0;
}
