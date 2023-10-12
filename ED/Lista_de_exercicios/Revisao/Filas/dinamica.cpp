#include <stdlib.h>
#include <stdio.h>
#include "dinamica.h"


void criar(Lista *L){
  L->Inicio = NULL;
}

void inserir (Lista *L, tipo_elem v){
  No *novo = (No*) malloc(sizeof(No));
  novo->info = v;
  novo->prox = L->Inicio;
  L->Inicio = novo;
}

int vazia(Lista *L){
  return L->Inicio == NULL;
}
int primeiro(Lista *L){
  if(vazia(L)){
    printf("Lista vazia\n");
    return 0;
  }
  return L->Inicio->info.chave;
}

void remover_final(Lista *L){
  if(vazia(L)){
    printf("Lista vazia\n");
    return;
  }
  No *p = L->Inicio;
  while(p->prox != NULL){
    p = p->prox;
  }
  free(p);
}

void reverso(Lista *L){
  if(vazia(L)){
    printf("Lista vazia\n");
    return;
  }
  No *p, *q;
  p = L->Inicio;
  q = p->prox;
  p->prox = NULL;
  while(q != NULL){
    No *r = q->prox;
    q->prox = p;
    p = q;
    q = r;
  }
  L->Inicio = p;
}

int numElem(Lista *L){
  if(vazia(L)){
    printf("Lista vazia\n");
    return 0;
  }
  No *p;
  int cont = 0;
  p = L->Inicio;
  while(p != NULL){
    cont++;
    p = p->prox;
  }
  return cont;
}

void exibir_lista(Lista *L){
  for(No *x = L->Inicio; x!= NULL; x = x->prox){
    printf("\n%d", x->info.chave);
  }
}
main() {
  Lista lista;
  criar(&lista);
  tipo_elem x;
  tipo_elem y;
  tipo_elem j;
  tipo_elem p;
  x.chave = 10;
  y.chave = 87;
  j.chave = 13;
  p.chave = 90;

  inserir(&lista, x);
  inserir(&lista, y);
  inserir(&lista, j);
  inserir(&lista, p);
  printf("\n---------------antes de reverter------------------");
  exibir_lista(&lista);
  printf("\n-----------------------------------");
  reverso(&lista);
   printf("\n----------depois de reverter----------------");
  exibir_lista(&lista);
}