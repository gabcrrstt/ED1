#include <stdlib.h>
#include <stdio.h>
/*
Faça um algoritmo que leia um número positivo e imprima seus divisores.
*/
main()
{
  int numero;
  printf("\n digite um numero inteiro: ");
  scanf("%d", &numero);
  for (int i = numero; (i >= 1) ; i--){
    if(numero % i == 0){
      printf("\n%d e divisor de %d", i, numero);
    }
  }
}
