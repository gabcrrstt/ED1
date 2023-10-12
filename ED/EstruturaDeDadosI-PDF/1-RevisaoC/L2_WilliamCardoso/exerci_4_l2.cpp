#include <stdio.h>

/*
4- Escreva um programa que imprima um vetor de inteiros na ordem inversa endereçando os
elementos com um ponteiro.
*/
main()
{
  int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *ponteiro = vetor;
  int i;
  for (i = 10 - 1; i >= 0; i--)
  {
    printf("%d\n", *ponteiro++);
  }
}