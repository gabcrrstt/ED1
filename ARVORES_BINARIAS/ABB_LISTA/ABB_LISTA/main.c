/*
 Alunos: Gabrielly Cristine
* Curso: Ciência da Computação
* Trabalho 1: Listas Lineares
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: Apple clang version 14.0.3 (clang-1403.0.22.14.1)
* IDE : Xcode
* Sistema Operacional: MacOs Veentura 13.1
 */
#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
int main() {
    Arvore arvore = criar_arvore();
    int op = 0;
    int chave, elemento;

    while (op != 11) {
        printf("1 - Verificar se a árvore está vazia\n");
        printf("2 - Inserir elemento\n");
        printf("3 - Remover elemento\n");
        printf("4 - Buscar elemento\n");
        printf("5 - Exibir elementos da árvore em pré-ordem\n");
        printf("6 - Exibir elementos da árvore em ordem\n");
        printf("7 - Exibir elementos da árvore em pós-ordem\n");
        printf("8 - Calcular altura da árvore\n");
        printf("9 - Calcular número de nós da árvore\n");
        printf("10 - Destruir árvore\n");
        printf("11 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                if (arvore.raiz == NULL) {
                    printf("A árvore está vazia.\n");
                } else {
                    printf("A árvore não está vazia.\n");
                }
                break;
            case 2:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &chave);
                inserir(&arvore, chave);
                printf("Elemento inserido com sucesso.\n");
                break;
            case 3:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &chave);
                if (buscar(&arvore, chave) != -1) {
                    remover(&arvore, chave);
                    printf("Elemento removido com sucesso.\n");
                } else {
                    printf("Elemento não encontrado.\n");
                }
                break;

            case 4:
                printf("Digite o elemento a ser buscado: ");
                scanf("%d", &chave);
                elemento = buscar(&arvore, chave);
                if (elemento != -1) {
                    printf("Elemento encontrado: %d\n", elemento);
                } else {
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 5:
                printf("Elementos em pré-ordem: ");
                exibir_pre_ordem(arvore.raiz);
                printf("\n");
                break;
            case 6:
                printf("Elementos em ordem: ");
                exibir_em_ordem(arvore.raiz);
                printf("\n");
                break;
            case 7:
                printf("Elementos em pós-ordem: ");
                exibir_pos_ordem(arvore.raiz);
                printf("\n");
                break;
            case 8:
                printf("Altura da árvore: %d\n", altura(&arvore));
                break;
            case 9:
                printf("Número de nós da árvore: %d\n", numero_nos(&arvore));
                break;
            case 10:
                destruir_arvore(&arvore);
                printf("Árvore destruída.\n");
                break;
            case 11:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                break;
        }
    }

    return 0;
}
