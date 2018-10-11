#include <iostream>
#include <string>

int fibonacci(int n){
     if (n <= 1)
         return n;
     return fibonacci(n-1) + fibonacci(n-2);
}

//time O(n)
int fibonacci2018(int n) {
        int a = 0, b = 1, c;
        if (n == 0)
            return a;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
}

int main()
{
  int n;
  std::cout << "Enter n: ";
  std::cin >> n;
  
  std::cout << "Fibonacci value: " << fibonacci2018(n);
}
