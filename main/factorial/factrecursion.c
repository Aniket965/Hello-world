#include<stdio.h>

int factorial(int n)
{
  if(n==1)
    return 1;

  return n*factorial(n-1);
}

int main()
{
  int x;
  long long int fact;
 
  scanf("%d", &x);
 
  fact=factorial(x);
 
  printf("%lld\n", fact);

  return 0;
}
