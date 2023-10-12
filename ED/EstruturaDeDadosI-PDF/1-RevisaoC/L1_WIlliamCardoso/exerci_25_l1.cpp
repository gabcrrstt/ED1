#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
25. Faça um programa que leia duas matrizes A e B de tamanho 3 x 3 e calcule C = A ∗ B.
*/

void exibeMatriz(int vetor[3][3])
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

main() {
  int A[3][3], B[3][3], C[3][3], i, j;
  srand(time(NULL));
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
    {
      A[i][j] = rand() % 5;
      B[i][j] = rand() % 5;
    }
  printf("\n matriz A \n");
  exibeMatriz(A);
  printf("\n matriz B \n");
  exibeMatriz(B);

  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
    {
      C[i][j] = A[i][j] * B[i][j]; 
    }
  printf("\n matriz C \n");
  exibeMatriz(C);

}