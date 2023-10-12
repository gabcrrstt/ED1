#include <stdlib.h>
#include <stdio.h>

/*
Faça um programa que preenche uma matriz 4 x 4 com o produto do valor da linha e da 
coluna de cada elemento. Em seguida, imprima na tela a matriz.
*/

void exibeMatriz(int vetor[][4])
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
void criaMatriz(int matriz[][4]) {
  int i, j;
  for (i = 0; i < 4; i++) 
    for (j = 0; j < 4; j++) {
       matriz[i][j] = i*j;
    }
}
main() {
  int vetor[4][4];
  criaMatriz(vetor);
  exibeMatriz(vetor);
}