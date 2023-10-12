#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10
/*
Faça um programa que leia dois vetores de 10 elementos. Crie um vetor que seja a
intersecção entre os 2 vetores anteriores, ou seja, que contém apenas os números que
estão em ambos os vetores. Não deve conter números repetidos.
*/

void exibeVetor(int vetor[LEN], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);
    }
}

int verificaSeExiste(int vetor[LEN], int tam, int numero)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        if (vetor[i] == numero)
        {
            return 1;
        }
    }
    return 0;
}

void intersecao(int vetor1[LEN], int vetor2[LEN], int vetor3[LEN], int &tam)
{
    int i, j, k;
    k = 0;
    for (i = 0; i < LEN; i++)
    {
        for (j = 0; j < LEN; j++)
        {
            if (vetor1[i] == vetor2[j] )
            {
                if(!verificaSeExiste(vetor3, k, vetor1[i]))
                {
                    vetor3[k] = vetor1[i];
                    k++;
                }
            }
        }
    }
    tam = k;
}

main()
{
    int vetor[LEN], vetor2[LEN], vetor3[LEN];
    int i, t;
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
    intersecao(vetor, vetor2, vetor3, t);
    exibeVetor(vetor3, t);
}