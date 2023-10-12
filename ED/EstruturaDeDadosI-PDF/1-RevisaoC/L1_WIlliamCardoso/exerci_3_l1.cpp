#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que leia um número inteiro maior do que zero e devolva, na tela, 
a soma de todos os seus algarismos. Por exemplo, ao número 251 corresponderá o valor 
8 (2 + 5 + 1). Se o número lido não for maior do que zero, o programa terminará com a 
mensagem “Número inválido”
*/
main() {
  int numero, soma = 0;
  printf("Digite um numero inteiro maior do que zero: ");
  scanf("%d", &numero);
  if (numero > 0) {
    for(numero ;numero > 0 ; numero /= 10 )
      soma += numero % 10;
    printf(" a soma dos algarismos e %d", soma);
  } else {
    printf("Numero invalido");
  }

}