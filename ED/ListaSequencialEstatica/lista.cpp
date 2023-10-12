#include "lista.h"
#include <stdio.h>



void iniciar(Lista *L){
    L -> nelem=0;
}

int vazia(Lista *L){
    return(L->nelem == 0);
}


int cheia(Lista *L){

    return(L->nelem==MAX);
}


int tamanho(Lista *L){

    return(L->nelem);
}

void apagar(Lista *L){

    L->nelem=0;
}

void exibir(Lista *L){
    int i;
    if(vazia(L)) printf("Nao ha elementos na lista");
    for(i=0;i<L->nelem;i++){
        printf("%d ", L->A[i].chave);
    }
    printf("\n");
}

int inserir_final(Lista *L, tipo_elem v){
    if(cheia(L)) return 0;

    L->A[L->nelem]=v;
    L-> nelem++;
    return 1;
}

int inserir_inicio(Lista *L, tipo_elem v){
    if(cheia(L)) return 0;
    else {
        int i;
        for(i = 0; i< L->nelem + 1 ; i++){
            tipo_elem aux = L->A[i]; // l->[0] = 5 l->[1] = 2 l->[2] = 3
            L->A[i] = v; // L->[2] = 2
            v = aux;
        }
        L->nelem++;
    }
}

int inserir_posi(Lista *L, tipo_elem v, int k){
    int i;
    if(cheia(L))
        return 0;
    tipo_elem V = v;
    for(i = k; i< L->nelem + 1; i++){
            tipo_elem aux = L->A[i];
            L->A[i] = V;
            V = aux;
        }
    L->nelem++;
}

int inserir_ord(Lista *L, tipo_elem v){
    int i;
    if(cheia(L)) return 0;
    i=0;

    while(i<L->nelem && v.chave > L-> A[i].chave)
        i++;
        return(inserir_posi(L,v,i));
}

int remover(Lista *L, int chave){
    int i = 0, j;
    if(vazia(L)) return 0;
    for(i ; L->A[i].chave != chave; i++ );
    for ( j = i; j < L->nelem; j++) L->A[j] = L->A[j+1]; 
    L->nelem--;
    return 1;  
}

/*
Empurra os elementos da posição N até o final da lista para esquerda.

*/
