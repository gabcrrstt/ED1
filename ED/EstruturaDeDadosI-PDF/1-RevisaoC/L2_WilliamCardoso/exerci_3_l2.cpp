#include <stdlib.h>
#include <stdio.h>

/*
3- Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas. Imprima o 
endereço de cada posição dessa matriz
*/

main()
{
  float arrayT[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 3; i++){

   for (int j = 0; j < 3; j++)
    printf("\n%x", &arrayT[i][j]);
  }
}