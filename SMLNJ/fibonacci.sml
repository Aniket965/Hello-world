fun fibonacci 0 = 0
| fibonacci 1 = 1
| fibonacci n = fibonacci(n-1) + fibonacci(n-2);

fibonacci 0;
fibonacci 1;
fibonacci 2;
fibonacci 3;