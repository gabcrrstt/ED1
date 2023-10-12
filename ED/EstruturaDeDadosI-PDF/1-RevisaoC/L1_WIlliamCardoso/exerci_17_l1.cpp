#include <stdio.h>
#include <stdlib.h>


/*
.Leia uma matriz 4 x 4, conte e escreva quantos valores maiores que 10 ela possui.
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

void lerMatriz(int matriz[][4]) {
  int i, j, maior10 = 0;
  for (i = 0; i < 4; i++) 
    for (j = 0; j < 4; j++) {
      printf("Digite o valor da posicao [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
      if(matriz[i][j] > 10) {
        maior10++;
      }
    }
    printf("\nexistem %d valores maiores que 10\n", maior10);
}

main() {
  int matriz[4][4];
  lerMatriz(matriz);
  exibeMatriz(matriz);
}