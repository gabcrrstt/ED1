#include <stdlib.h>
#include <stdio.h>
#include "estatica.h"

void criar(Lista *L){
  L->Nelem = 0;
}
void inserir(Lista *L, tipo_elem v){
  if(cheia(L)) printf("\nfila cheia");
  L->A[L->Nelem++] = v;
}
int vazia(Lista *L){
  return L->Nelem == 0;
}
int cheia(Lista *L){
  return L->Nelem == MAX;
}
int primeiro(Lista *L){
  if(vazia(L)) return NULL;
  return L->A[0].chave;
}
void remover(Lista *L){
  if(vazia(L)) printf("\nfila vazia");
  int i;
  for(i = 0; i < L->Nelem; i++) L->A[i] = L->A[i +1];
  L->Nelem--;
}

void reverso(Lista *L){
  int i, j;
  for(i = 0, j = L->Nelem - 1; i < j; i++, j--){
    tipo_elem aux = L->A[i];
    L->A[i] = L->A[j];
    L->A[j] = aux;
  }
}

int numElem(Lista *L) {
  return L->Nelem;
}