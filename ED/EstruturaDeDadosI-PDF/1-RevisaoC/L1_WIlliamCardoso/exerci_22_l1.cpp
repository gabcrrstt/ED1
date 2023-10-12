#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
Leia uma matriz de 3 x 3 elementos. Calcule a soma dos elementos que estão na diagonal
principal.
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

void somarElementosDiagonalPrincipal(int vetor[][3])
{
  int soma = 0;
  for (int i = 0; i < 3; i++)
    soma += vetor[i][i];
  printf("a soma da diagonal principal e : %d", soma);
}

main()
{
  int matriz1[3][3];
  int i, j;
  srand(time(NULL));
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
    {
      matriz1[i][j] = rand() % 5;
    }
  exibeMatriz(matriz1);
  somarElementosDiagonalPrincipal(matriz1);
  return 0;
}
