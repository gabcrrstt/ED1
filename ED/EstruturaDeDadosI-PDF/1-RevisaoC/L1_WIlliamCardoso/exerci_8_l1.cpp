#include <stdlib.h>
#include <stdio.h>
/*
Faça um programa que leia um número inteiro positivo par N e imprima todos os
números pares de 0 até N em ordem decrescente. Faça com o menor número de
comparações possível.
*/
main()
{
  int numero;
  printf("\ndigite um numero par: ");
  scanf("%d", &numero);
  for (int i = numero; i >= 0; i -= 2)
    printf("\n la vai um inteiro par %d", i);
}