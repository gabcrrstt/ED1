#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais 
elementos. Escreva ao final a matriz obtida.
*/

void criaMatriz(int matriz[][5]) {
  int i, j;
  for (i = 0; i < 4; i++) 
    for (j = 0; j < 4; j++) {
      if(i == j) {
        matriz[i][j] = 1;
      } else {
        matriz[i][j] =0;
      }
    }
  
}
void exibeMatriz(int vetor[][5])
{
    int i,j;
    for (i = 0; i < 4; i++)
    {
       for (j = 0; j < 4; j++)
      {
        printf(" %d\t", vetor[i][j]);
      }
      printf("\n");
    }
}
main() {
  int matriz[5][5];
  criaMatriz(matriz);
  exibeMatriz(matriz);
}