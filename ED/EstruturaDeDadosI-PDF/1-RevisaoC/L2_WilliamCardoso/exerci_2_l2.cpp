#include <stdlib.h>
#include <stdio.h>

/*
2- Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de
cada posição desse array
*/
main()
{
  float arrayT[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int i = 0; i < sizeof(arrayT) / sizeof(float); i++)
    printf("\n%x", &arrayT[i]);
}