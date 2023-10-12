#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Leia duas matrizes 4 x 4 e escreva uma terceira com os maiores valores de cada posição
das matrizes lidas.
*/

void exibeMatriz(int vetor[][4])
{
  int i, j;
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      printf(" %d\t", vetor[i][j]);
    }
    printf("\n");
  }
}

void preencherMatrizMaior(int matriz1[][4], int matriz2[][4], int matriz[][4])
{
  int i, j;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
    {
      if (matriz1[i][j] > matriz2[i][j])
      {
        matriz[i][j] = matriz1[i][j];
      }
      else
      {
        matriz[i][j] = matriz2[i][j];
      }
    }
}
main()
{
  int matriz1[4][4];
  int matriz2[4][4];
  int matriz[4][4];
  int i, j;
  srand(time(NULL));
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
    {
      matriz1[i][j] = rand() % 10;
      matriz2[i][j] = rand() % 10;
    }
  preencherMatrizMaior(matriz1, matriz2, matriz);
  exibeMatriz(matriz1);
  printf("\n");
  exibeMatriz(matriz2);
  printf("\n terceira matriz com os maior valores\n");
  exibeMatriz(matriz);
}