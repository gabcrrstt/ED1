#include <stdlib.h>
#include <stdio.h>

/*
6- Faça um programa que leia uma quantidade qualquer de números armazenando-os na memória e 
pare a leitura quando o usuário entrar com um número negativo. Em seguida, imprima o vetor lido. 
Use a função REALLOC
*/
main() {
  int *vetor = (int *) malloc(0*sizeof(int));
  int numero, i = 0;
  while (true) {
    printf("Digite um numero: ");
    scanf("%d", &numero);
    if (numero < 0) {
      break;
    }
    vetor = (int *) realloc(vetor, (i+1)*(sizeof(int)));
    vetor[i] = numero;
    i++;
  }
  printf("Vetor: ");
  for (int j = 0; j < i; j++) {
    printf("%d ", vetor[j]);
  }
  printf("\n");
  free(vetor);
}