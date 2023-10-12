#include <stdio.h>
#include "pilha.h"
#include <string.h>

void criar(Lista *L){
  L->Nelem = 0;
}
void push(Lista *L, tipo_elem v){
  L->A[L->Nelem] = v;
  L->Nelem++;
}
void exibir(Lista *L){
  int i;
  for(i=0; i<L->Nelem; i++){
    printf("%c", L->A[i].chave);
  }
  printf("\n");
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

Lista reverse(Lista *L){
  int i, j;
  Lista aux;
  criar(&aux);
  for(i=L->Nelem-1; i>=0; i--){
    push(&aux, L->A[i]);
  }
  return aux;
}

int palindromo(Lista *L){
  Lista aux = reverse(L);
  int i;
  for(i=0; i<L->Nelem; i++){
    if(L->A[i].chave != aux.A[i].chave){
      return 0;
    }
  }
  return 1;
}
