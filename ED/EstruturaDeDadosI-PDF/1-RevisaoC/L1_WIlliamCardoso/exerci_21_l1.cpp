#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
Leia uma matriz de 3 x 3 elementos. Calcule a soma dos elementos que estão acima da 
diagonal principal.
*/
void exibeMatriz(int vetor[][3])
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf(" %d\t", vetor[i][j]);
    }
    printf("\n");
  }
}

void calcularElementosAcimaDaDiagonalPrincipal(int vetor[][3])
{
  int i, j, soma = 0;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      if (j > i)
      {
        soma += vetor[i][j];
      }
    }
  }
  printf("\nSoma dos elementos acima da diagonal principal: %d\n", soma);
}
main() {
  int matriz1[3][3];
  int i, j;
  srand(time(NULL));
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
    {
      matriz1[i][j] = rand() % 5;
    }
    exibeMatriz(matriz1);
    printf("\n");
    calcularElementosAcimaDaDiagonalPrincipal(matriz1);
}