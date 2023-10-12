
#include "estatica.h"
#include <stdlib.h>
#include <stdio.h>

void criar(Lista *L){
  L->Nelem = 0;
}
void push(Lista *L, tipo_elem v){
  L->A[L->Nelem] = v;
  L->Nelem++;
}
int vazia(Lista *L){
  return L->Nelem == 0;
}
int topo(Lista *L){
  if(vazia(L)){
    printf("Lista vazia\n");
    return 0;
  }
  return L->A[L->Nelem-1].chave;
}
void pop(Lista *L){
  if(vazia(L)){
    printf("Lista vazia\n");
    return;
  }
  L->Nelem--;
}
void destruir(Lista *L){
  L->Nelem = 0;
}
