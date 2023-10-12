#include "lista.h"
#include <stdio.h>

void iniciar(Lista *L){

    L -> nelem=0;
}

int vazia(Lista *L){

    return(L->nelem==0);
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
        printf("%d", L->A[i].chave);
    }
}

int inserir_final(Lista *L, tipo_elem v){

    if(cheia(L))
        return 0;

    L->A[L->nelem]=v;
    L-> nelem++;
        return 1;
}

int inserir_inicio(Lista *L, tipo_elem v){

    int i;

    if(cheia(L))
        return 0;
    for(i=L ->nelem; i>0; i--){
        L->A[i]= L->A[i-1];
    }
    L->A[0]=v;
    L->nelem++;
        return 1;
}

int inserir_posi(Lista *L, tipo_elem v, int k){

    int i;

    if(cheia(L))
        return 0;
    for(i=L->nelem; i>k; i--){
        L->A[i]=L->A[i-1];
    }

    L-> A[k]=v;
    L->nelem++;
        return 1;
}

int inserir_ord(Lista *L, tipo_elem v){

    int i;

    if(cheia(L))
        return 0;

    i=0;

    while(i<L->nelem && v.chave > L-> A[i].chave)
        i++;
        return(inserir_posi(L,v,i));
}

int remover(Lista *L, int chave){

    int i;

    if(vazia(L))
        return 0;

    for(i=0; i<L->nelem; i++){
        if(L->A[i].chave==chave)
            break;
    }
    if(i==L->nelem)
        return 0;
    //achou e remove

    while(i<L-> nelem-1)
        L->A[i]=L->A[i+1];

    L->nelem--;

    return 1;
}
