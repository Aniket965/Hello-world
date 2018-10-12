
/* Swaping int adress */
void	swap(int *n1, int *n2)
{
  int tmp = 0;

  tmp = *n1;
  *n1 = *n2;
  *n2 = tmp;
}

/* #include <stdio.h> */

/* int main() */
/* { */
/*   int a = 1; */
/*   int b = -1; */

/*   printf("Befor swap: %d, %d\n", a, b); */
/*   swap(&a, &b); */
/*   printf("after swap: %d, %d\n", a, b);   */
/* } */
