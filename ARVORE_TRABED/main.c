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

#include <stdio.h>
#include "abb.h"

int main() {
    Arvore* arvore = cria_arvore();

    insere(arvore, 10);
    insere(arvore, 5);
    insere(arvore, 15);
    insere(arvore, 7);
    insere(arvore, 3);
    insere(arvore, 12);
    insere(arvore, 17);

    printf("Pre-ordem: ");
    exibe_pre_ordem(arvore);

    printf("In-ordem: ");
    exibe_in_ordem(arvore);

    printf("Pos-ordem: ");
    exibe_pos_ordem(arvore);

    printf("Altura da arvore: %d\n", altura(arvore));
    printf("Numero de nos na arvore: %d\n", num_nos(arvore));

    int valor = 12;
    No* no_encontrado = busca(arvore, valor);
    if (no_encontrado != NULL) {
        printf("No com valor %d encontrado!\n", valor);
    } else {
        printf("No com valor %d nao encontrado.\n", valor);
    }

    valor = 20;
    no_encontrado = busca(arvore, valor);
    if (no_encontrado != NULL) {
        printf("No com valor %d encontrado!\n", valor);
    } else {
        printf("No com valor %d nao encontrado.\n", valor);
    }

    valor = 5;
    remove_no(arvore, valor);

    printf("Pre-ordem apos remocao: ");
    exibe_pre_ordem(arvore);

    destroi_arvore(arvore);

    return 0;
}
