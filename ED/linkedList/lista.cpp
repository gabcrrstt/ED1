#include"lista.h"
#include<stdlib.h>
#include<stdio.h>


void iniciar(Lista *L){
  int i;
  L->Inicio = NIL;
  L->Dispo = 0;
  for(i = 0;  i<MAX; i++){
    L->A[i].pos = i+1;
  }
  L->A[MAX-1].pos = NIL; // a ultima posicao da lista e NIL
}

int vazia(Lista *L){
  return L->Inicio==NIL;
}

int cheia(Lista *L) {
  return L->Dispo==MAX;
}

int inserir(Lista *L, tipo_elem v);
int inserir_final(Lista *L, tipo_elem v);
int inserir_ord(Lista *L, tipo_elem v){
  int i, k;
  i = L->Inicio;
  while (i != NIL && L->A[i].info.chave <= v.chave) {
    k = i;
    i = L->A[i].pos;
  }
  if(k == NIL) return inserir_inicio(L, v);
  return inserir_apos(L, v, k);
}
int inserir_posi(Lista *L, tipo_elem v, int k);
int inserir_apos(Lista *L, tipo_elem v, int k){
  //pega primeira posição da lista disponivel
  if(cheia(L)) return 0;
  int q =  L->Dispo;
  L->Dispo = L->A[L->Dispo].pos;

  //atualizar os campos de q
  L->A[q].info = v;
  L->A[q].pos = L->A[k].pos;
  L->A[q].pos = q ;
  return 1;
}

int inserir_inicio(Lista *L, tipo_elem v){
  int k;
  if(cheia(L)){
    return 0;
  }
  //pega o primeiro disponivel
  k = L -> Dispo;
  L->Dispo = L->A[L->Dispo].pos;

  //atualiza os campos info e pos
  L->A[k].info = v;
  L -> A[k].pos = L->Inicio;
  //atualiza o incio
  L->Inicio = k;
  return 1;
}

int buscaSequencial(Lista *L, int chave){
  int i;
  for(i = L->Inicio; i != NIL; i = L->A[i].pos){
    if(L->A[i].info.chave == chave) return i;
  }
  return NIL;
}

int remover(Lista *L, int chave){
  int pos_elem = buscaSequencial(L, chave);
  if(pos_elem == NIL) return 0;
  int k = L->A[pos_elem].pos; // posicao que o elemento a ser removido está apontando
  L->A[pos_elem].pos = L->Dispo; // a posição que o elemento a ser removido está apontando vai ser a ultima posicao do disponivel
  L->Dispo = pos_elem; // dispo passa a apontar para a posição do elemento que foi removido.
  L->A[pos_elem].pos = k;
  return 1;

}

int tamanho(Lista *L){
  int i;
  int cont;
  for(cont = 0 , i=L->Inicio; i != NIL; i = L->A[i].pos, cont++);
  return cont;
}

void apagar(Lista *L){
  iniciar(L);
}

void finalizar(Lista *L);
void exibir(Lista *L){
  if(vazia(L)) printf("Lista vazia.\n");
  else {
    int i;
    for( i=L->Inicio; i != NIL; i = L->A[i].pos){
      printf("%d ", L->A[i].info.chave);
    }
  }
}

void inverte(Lista *L){
  int i, j, k;
  for(i = L->Inicio, j = L->A[i].pos, k = L->A[j].pos; i != NIL; i = j, j = k, k = L->A[j].pos){
    L->A[j].pos = i;
  }
  L->Inicio = j;
}

main() {
  
}