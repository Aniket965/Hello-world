#include <stdio.h>
#include <stdlib.h>

//Declarando Função
void hanoi(int, char, char, char);
int movimentos(int);

//========================================================================
int main(int argc, char *argv[])
{
  int discos;

  printf("Forneca o numero de discos: \n");
  scanf("%d", &discos);
  if (discos < 1)
  {
    while (discos < 1)
    {
      printf("Valor invalido. Insira novamente: \n");
      scanf("%d", &discos);
    }
  }
  printf("numero de movimentos: %d\n", movimentos(discos));
  hanoi(discos, 'A', 'C', 'B');
  return 0;
}
//=========================================================================
void hanoi(int d, char ori, char dest, char aux)
{
  if (d == 1)
  {
    printf("Mover disco %d de %c para %c\n", d, ori, dest);
  }
  else
  {
    hanoi(d - 1, ori, aux, dest);
    printf("Mover disco %d de %c para %c\n", d, ori, dest);
    hanoi(d - 1, aux, dest, ori);
  }
}

int movimentos(int discos)
{
  if (discos == 1)
  {
    return 1;
  }
  else
  {
    return 2 * movimentos(discos - 1) + 1;
  }
}
