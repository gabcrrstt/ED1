/**********************************************************
*****
* Alunos: Gabrielly Cristine 
* Curso: Ci�ncia da Computa��o
* Trabalho 1: Listas Lineares
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: gcc (tdm-1) 4.9.2
* IDE : Vscode
* Sistema Operacional: MacOs Veentura 13.1
***********************************************************
****/

#include <stdlib.h>
#include <stdio.h>
#include "abb.h"



Arvore *cria_arvore()
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

No *cria_no(int valor)
{
    No *no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void destroi_arvore(Arvore *arvore)
{
    if (arvore == NULL)
    {
        return;
    }
    destroi_no(arvore->raiz);
    free(arvore);
}


void exibe_pre_ordem(Arvore *arvore)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        return;
    }
    printf("%d ", arvore->raiz->valor);
    exibe_pre_ordem_recursivo(arvore->raiz->esquerda);
    exibe_pre_ordem_recursivo(arvore->raiz->direita);
    printf("\n");
}

void exibe_pre_ordem_recursivo(No *no)
{
    if (no == NULL)
    {
        return;
    }
    printf("%d ", no->valor);
    exibe_pre_ordem_recursivo(no->esquerda);
    exibe_pre_ordem_recursivo(no->direita);
}

void exibe_in_ordem(Arvore *arvore)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        return;
    }
    exibe_in_ordem_recursivo(arvore->raiz->esquerda);
    printf("%d ", arvore->raiz->valor);
    exibe_in_ordem_recursivo(arvore->raiz->direita);
    printf("\n");
}
