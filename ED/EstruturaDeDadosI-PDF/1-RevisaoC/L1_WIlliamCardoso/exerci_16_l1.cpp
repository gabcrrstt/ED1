#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define LEN 10
#define LEN_CONJU LEN + LEN
/*
  Faça um programa que leia dois vetores de 10 elementos. Crie um vetor que seja a união
entre os 2 vetores anteriores, ou seja, que contém os números dos dois vetores. Não
deve conter números repetidos.
*/

void exibeVetor(int vetor[LEN], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);
    }
}

void conjucao(int vetor1[LEN], int vetor2[LEN], int vetor3[LEN_CONJU])
{
    int i;
    for (i = 0; i < LEN; i++)
    {

        vetor3[i] = vetor1[i]; 
        vetor3[i+LEN] = vetor2[i]; 
    }
}

void removeRepetidos(int vetor[LEN_CONJU], int &tamanho)
{

  int  i, j, k;    
  for(i = 0; i < tamanho; i ++)  
  {  
      for  (j = i + 1; j < tamanho; j++)  
      {  
        if  (vetor[i] == vetor[j])  
        {  
            for( k = j; k < tamanho - 1; k++)  
            {  
                vetor[k] = vetor[k + 1];  
            }  
            tamanho--;  
            j--;      
        }  
      }  
  }
}
main() {
  int vetor[LEN], vetor2[LEN], vetor3[LEN_CONJU], i, tamahnho;
   srand(time(NULL));
    for (i = 0; i < LEN; i++)
    {
        vetor[i] = rand() % 5;
        vetor2[i] = rand() % 5;
    }

    printf("Vetor 1: \n");
    exibeVetor(vetor, LEN);
    printf("\nVetor 2: \n");
    exibeVetor(vetor2, LEN);
    printf("\nVetor 3: \n");
    conjucao(vetor, vetor2, vetor3);
    tamahnho = sizeof(vetor3)/sizeof(int);
    removeRepetidos(vetor3, tamahnho);
    exibeVetor(vetor3, tamahnho);
}