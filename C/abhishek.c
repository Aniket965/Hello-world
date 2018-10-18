#include<stdio.h>
int main()
{
  int c, n;
  unsigned long fact = 1;
  printf("Enter a number to calculate its factorial\n");
  scanf("%d", &n); 
  for (c = n; c >= 1; c--)
    fact *= c;
  printf("Factorial of %d = %lu\n", n, fact);
  return 0;
}
