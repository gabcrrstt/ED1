#include<stdlib.h>
#include<stdio.h>
#include "lista.h"


void iniciar(Lista *L){
  L->Inicio = NULL;
}
int vazia(Lista *L){
  return L->Inicio == NULL;
}
int inserir(Lista *L, tipo_elem v){}
int inserir_final(Lista *L, tipo_elem v){
  No *p, *q;
  q = NULL;
  p = L->Inicio;
  while(p != NULL) {
   q = p;
   p = p->prox;
  }
  if(q == NULL) return inserir_inicio(L, v);
  return inserir_apos(L, v, q);
}
int inserir_ord(Lista *L, tipo_elem v){
  No *p, *q;
  if(vazia(L)){
    return inserir_inicio(L, v);
  }
  q = NULL;
  p = L->Inicio;
  while(p != NULL && p->info.chave <= v.chave){
    q = p;
    p = p->prox;
  }
  if (q == NULL) return inserir_inicio(L, v);
  return inserir_apos(L, v, q);
}
int inserir_inicio(Lista *L, tipo_elem v){
  //ordem constante de complexidade O(1)
  No *novoNo =( No*) malloc(sizeof(No));
  if(novoNo == NULL) return 0;
  novoNo->info = v;
  novoNo->prox = NULL;
  L->Inicio = novoNo;
}

int inserir_apos(Lista *L, tipo_elem v, No *k){
  No *novoNo =( No*) malloc(sizeof(No));
  if(novoNo == NULL) return 0;
  novoNo->info = v;
  novoNo->prox = k->prox;
  k->prox = novoNo;
  return 1;
}
int remover(Lista *L, int chave){
  No*p = L->Inicio;
  No *q = NULL;
  while(p != NULL && p -> info.chave != chave) {
    q = p;
    p = p->prox;
  }
  if(p == NULL) return 0; 
  if(q == NULL){ 
    L->Inicio = p->prox;
    free(p);
    return 1;
  }
  q ->prox = p->prox;
  free(p);
  return 1;
}
int tamanho(Lista *L){
  int cont = 0;
   for(No *i = L->Inicio; i != NULL; i = i->prox){
    cont++;
  }
  return cont;
}
void Destruir(Lista *L){
  for(No *i = L->Inicio; i != NULL; i = i->prox){
    free(i);
  }
}
void exibir(Lista *L){
  if(vazia(L)){
    printf("Lista vazia\n");
  }
  for(No *i = L->Inicio; i != NULL; i = i->prox){
    printf("%d\n", i->info.chave);
  }
}
No* buscaSequencial(Lista *L, int chave, No*p){
  if(p == NULL) return NULL;
  if(p->info.chave == chave) return p;
  return buscaSequencial(L, chave, p->prox);
}
int exibirUmElem(Lista *L, No *p){
  if (p == NULL){
    printf("Elemento nao encontrado\n");
    return 0;
  }
  printf("%d\n", p->info.chave);
}
