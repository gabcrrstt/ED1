#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
24. Faça programa que leia uma matriz 3 x 6 com valores reais.
(a) Imprima a soma de todos os elementos das colunas ímpares. 
(b) Imprima a média aritmética dos elementos da segunda e quarta colunas.
(c) Substitua os valores da sexta coluna pela soma dos valores das colunas 1 e 2. 
(d) Imprima a matriz modificada
*/

void exibeMatriz(int vetor[3][6])
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 6; j++)
    {
      printf(" %d\t", vetor[i][j]);
    }
    printf("\n");
  }
}

void calcularMatriz(int matriz[3][6]) {
  int somaI = 0;
  float somaEleSeQ = 0;
  for(int i = 0; i < 3; i ++) {
    for(int j = 0; j < 6; j++) {
      if(j % 2 != 0) somaI += matriz[i][j];
      if(j == 1 || j == 3 ) somaEleSeQ += (float) matriz[i][j];
      if(j == 5 ) matriz[i][j] =  matriz[i][0] + matriz[i][1];
    }
  }
  printf("a soma de todos os elementos das colunas impares e : %d\n", somaI);
  printf("a media aritmetica dos elementos da segunda e quarta colunas e : %.2f\n", somaEleSeQ / 2.0);
}

main() {
int matriz1[3][6];
  int i, j;
  srand(time(NULL));
  for (i = 0; i < 3; i++)
    for (j = 0; j < 6; j++)
    {
      matriz1[i][j] = rand() % 5;
    }
  exibeMatriz(matriz1);
  calcularMatriz(matriz1);
  printf("\n matriz modificada \n");
  exibeMatriz(matriz1);
}