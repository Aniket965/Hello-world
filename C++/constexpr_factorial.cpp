#include <iostream>

constexpr unsigned long long fact(int n)
{
    if (n == 0 || n == 1) return 1;
    else return n * fact(n-1);
}

constexpr unsigned long long factorial[21] = {
    fact(0), fact(1), fact(2), fact(3), fact(4),
    fact(5), fact(6), fact(7), fact(8), fact(9),
    fact(10), fact(11), fact(12), fact(13), fact(14),
    fact(15), fact(16), fact(17), fact(18), fact(19),
    fact(20) };

int main(int argc, char** argv)
{
    int n = std::stoi(argv[1]);
    if (n < 21) std::cout << factorial[n] << "\n";
    else std::cout << "factorial " << n << " is too big\n";
}
