#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int op;
    Lista L;
    tipo_elem v;
    iniciar(&L);

    do {
        //menu
        printf("1-Vazia\n");
        printf("2-Cheia\n");
        printf("3-Inserir Ordenado\n");
        printf("4-Inserir no Final\n");
        printf("5-Inserir no Inicio\n");
        printf("6-Remover um Elemento\n");
        printf("7-Apagar a Lista\n");
        printf("8-Exibir Todos os Elementos\n");
        printf("9-Numero de elementos da lista\n");
        printf("10-Sair\n");
        printf("Digite a opcao\n");
        scanf("%d",&op);

    switch(op){

        case 1:
        if(vazia(&L)){
            printf("a lista esta vazia.\n");
        }
        else {
        printf("a lista não esta vazia.\n");
        }
        break;

        case 2:
        if(cheia(&L)){
            printf("a lista esta cheia.\n");
        }
        else {
            printf("a lista não esta cheia.\n");
        }
        break;

        case 3:
        printf("\ndigite um valor: ");
        scanf("%d", &v.chave);

        if(inserir_ord(&L, v)) {
            printf("\nelemento inserido com sucesso.");
        }
        else{
            printf("\n nao foi possivel inserir um elemento.");
        }
        break;

        case 4:
        printf("\ndigite um valor: ");
        scanf("%d", &v.chave);

        if(inserir_final(&L, v)) {
            printf("\nelemento inserido com sucesso.");
        }
        else {
            printf("\n nao foi possivel inserir um elemento.");
        }
        break;

        case 5:
        printf("\ndigite um valor: ");
        scanf("%d", &v.chave);

        if(inserir_inicio(&L, v)) {
            printf("\nelemento inserido com sucesso.");
        }
        else {
            printf("\n nao foi possivel inserir um elemento.");
        }
        break;

        case 6:
        int chave;
        printf("\ndigite a chave: ");
        scanf("%d", &chave);

        if(remover(&L, chave)) {
            printf("\nelemento removido com sucesso.");
        }
        else {
            printf("\n nao foi possivel remover um elemento.");
        }
        break;

        case 7:
        apagar(&L);
        break;

        case 8:
        exibir(&L);
        break;

        case 9:
        printf("\na lista tem %d", tamanho(&L));
        break;

        default:
        break;
        }
    }
        while (op != 10);
        apagar(&L);

        return 0;
    }//end main
