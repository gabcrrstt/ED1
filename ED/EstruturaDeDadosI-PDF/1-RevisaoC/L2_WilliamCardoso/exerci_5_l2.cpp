#include <stdlib.h>
#include <stdio.h>

/*
5- Crie um programa que:
(a) Aloque dinamicamente um array de 5 números inteiros;
(b) Peça para o usuário digitar os 5 números no espaço alocado;
(c) Mostre na tela os 5 números;
(d) Libere a memória alocada
*/
main()
{
  int i;
  int *vetor;
  int tamanho = 5;
  vetor = (int *)malloc(tamanho * sizeof(int));
  printf("Digite 5 numeros: ");
  for (i = 0; i < tamanho; i++)
  {
    scanf("%d", &vetor[i]);
  }
  printf("\n");
  for (i = 0; i < tamanho; i++)
  {
    printf("%d\n", vetor[i]);
  }
  free(vetor);
}