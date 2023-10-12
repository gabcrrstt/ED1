#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Leia uma matriz de 3 x 3 elementos. Calcule a multiplicação dos elementos que estão na
diagonal secundária.
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

void multiplicarElementosDiagonalSecundaria(int vetor[][3])
{
  int multi = 1;
  for (int i = 0, j = 3; i < 3; i++, j--)
    multi *= vetor[i][j-1];
  printf("a multiplicacao da diagonal secundaria e : %d", multi);
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
  multiplicarElementosDiagonalSecundaria(matriz1);
  return 0;
}
