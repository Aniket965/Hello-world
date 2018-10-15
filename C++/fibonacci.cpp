#include <iostream>

using bigint_t = unsigned long long int;

void swapThem(bigint_t* a, bigint_t* b)
{
    bigint_t c = *b;
    *b = *a;
    *a = c;
}

int main(void)
{
    bigint_t a = 1, b = 0;
    unsigned int term = 0, current = 0;
    std::cout << "Fibonacci term wanted (>= 1) :"; std::cin >> term;
    
    while (true)
    {
        a += b;
        swapThem(&a, &b);
        ++current;
        
        if (current == term)
        {
            std::cout << b;
            break;
        }
    }
    std::cout << std::endl;
    
    return 0;
}
