#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa que leia um número inteiro positivo n e em seguida imprima n
linhas do chamado Triangulo de Floyd. Para n = 6, temos:
*/

main()
{
  int n, soma = 0;
  printf("digite um numero: ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1 ; j <= i; j++)
    {
      soma += 1;
      printf(" %d", soma);
    }
    printf("\n");
  }
}