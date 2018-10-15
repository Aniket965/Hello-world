#include<iostream>
#include<windows.h>

void slow_print(const std::string str, int delay_time) {
    for (size_t i = 0; i != str.size(); ++i) {
        std::cout << str[i];
        Sleep(delay_time);
    }
}

int main(){

    std::string message = "Hello World!";
    // the bigger the number the slower it prints
    int DELAY_TIME = 300;


    //pass in the message to print it slowly
    slow_print(message, DELAY_TIME);
}
