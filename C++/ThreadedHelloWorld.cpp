#include <iostream>
#include <thread>

void helloWorld()
{
    std::cout << "Threaded \"Hello world!\"\n";
}

int main()
{
    std::thread t(helloWorld);
    std::cout << "Hello world from main()!\n";
    t.join();
}
