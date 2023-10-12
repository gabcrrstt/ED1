#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void inserir(Lista *L, tipo_elem v){
  if(cheia(L)) printf("\nlista cheia");
  int num_existe = verificar_item(L, v);
  if(num_existe != -1) printf("\nnumero ja esta na lista.");
  else {
    L->ult++;
    L->A[L->ult] = v;
  }
}
void iniciar(Lista *L){
  L->ult = 0;
}
int cheia(Lista *L) {
 return L->ult == MAX;
}
int vazia(Lista *L){
  return L->ult == 0;
}
int verificar_item(Lista *L, tipo_elem v){
  int i;
  for(i = 0; i <= L->ult; i++){
    if(L->A[i].chave == v.chave) return i;
  }
  return -1;
}

int verificar_item_sentinela(Lista *L, tipo_elem v){
  int i;
  int achou = 0;
  for(i = 0; i < L->ult; i++) {
    if(L->A[i].chave == v.chave){
      achou = 1;
      break;
    } 
  }
  if(achou) return i;
  return -1;
}

void elimina(Lista *L, tipo_elem v){
  if(vazia(L)) printf("\nlista vazia");
  int num_existe = verificar_item(L, v);
  if(num_existe != -1){
    int i;
    for(i = num_existe; i < L->ult; i++) {
      L->A[i] = L->A[i+1];
    }
    L->ult--;
  } else {
    printf("\nnumero nao esta na lista.");
  }
}
int busca(Lista *L, tipo_elem v){

}