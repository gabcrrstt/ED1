#include <stdio.h>
#include <stdlib.h>

/*
Leia 10 números inteiros e armazene em um vetor. Em seguida escreva os elementos ´ 
que são primos e suas respectivas posições no vetor
*/
main() {
  int vetor[10];
  printf("digite alguns elementos para o vetor: ");
  for(int i = 0; i < 10; i++) {
    printf("\n%d/10- digite um numero: ", i+1);
    scanf("%d",&vetor[i]);
  }
  for(int j  = 0; j < 10; j++) if (vetor[j] % 2 ) printf("\n[%d] e primo na posicao [%d]", vetor[j], j);
}