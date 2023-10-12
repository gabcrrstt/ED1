#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
/*
Faça um programa que calcule o desvio padrão de um vetor v contendo n = 10 números,
onde m é a média do vetor.
*/
void preencherVetor(int v[], float &media, int &soma)
{
  srand(time(NULL));
  soma = 0;
  for (int i = 0; i < 10; i++)
  {
    v[i] = rand() % 100;
    soma += v[i];
  }
  media = soma / 10;
}
main()
{
  int vetor[10];
  int soma;
  float media;
  preencherVetor(vetor, media, soma);
  float soma_desvio = 0;
  for (int i = 0; i < 10; i++)
  {
    soma_desvio += pow(vetor[i] - media, 2);
  }
  float desvio = sqrt(soma_desvio / 10);
  printf("Desvio padrao: %.2f\n", desvio);
}