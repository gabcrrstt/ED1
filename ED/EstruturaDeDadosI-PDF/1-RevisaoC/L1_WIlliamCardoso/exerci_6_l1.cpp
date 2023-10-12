#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que peça ao usuário para digitar 10 valores e some-os (não usar 
vetor, usar variável simples)
*/
main() {
  int soma = 0, numero;
  for(int i = 0; i < 10; i++) {
    printf("%d-Digite um numero: ", i+1);
    scanf("%d", &numero);
    soma += numero;
  }
  printf("Soma: %d\n", soma);
}