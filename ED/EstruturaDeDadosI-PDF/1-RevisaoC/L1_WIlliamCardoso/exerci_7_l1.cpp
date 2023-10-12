#include <stdlib.h>
#include <stdio.h>
/*
Escreva um programa que leia 10 números e escreva o menor valor lido e o maior valor 
lido
*/
main()
{
  int menor, maior, numero;
  for (int i = 0; i < 10; i++)
  {
    printf("%d/10-digite um numero: ", i+1);
    scanf("%d", &numero);
    if (i == 0){
      maior = numero;
      menor = numero;
    }
    else
    {
      if (numero > maior)
        maior = numero;
      if (numero < menor)
        menor = numero;
    }
  }
  printf("o maior numero e: %d ", maior);
  printf("o menor numero e: %d", menor);
}