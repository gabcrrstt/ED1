#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int iniciar(ILista *L){
  L ->Nelem = 5;
  return 1;
}

int aux_vazia(ILista *L) {
  return L->Nelem == 0;
}

void exibir_lista(ILista *L){
  int i;
  if(aux_vazia(L)) printf("Nao ha elementos na lista");
  for(i=0;i<L->Nelem;i++){
    printf("%d ", L->A[i].chave);
  }
}

void exibir_lista_registro(IListaReg *L){
  int i;
  for(i=0;i<L->Nelem;i++){
    printf("%d %d\n", L->A[i].chave, L->A[i].cont);
    printf("\n");
  }
}

int ordenada(ILista *L){
  if(aux_vazia(L)) return 0;
  int nCrescente = 0;
  int nDecrescente = 0;
  for(int i  = 0; i < (L->Nelem) - 1; i++){
    if(L->A[i].chave < L->A[i +1].chave) nCrescente++;
    if(L->A[i].chave > L->A[i +1].chave) nDecrescente++;
  }
  if((nDecrescente == L->Nelem - 1) || (nCrescente == L->Nelem -1)) return 1;
  return 0;
}

void copia_lista(ILista *L, ILista *P){
  if(aux_vazia(L))  printf("\na primeira lista nao pode ser vazia.");
  int i = 0;
  P->Nelem = 0;
  while(i < L->Nelem) {
    P->A[i] = L->A[i];
    P->Nelem++;
    i++;
  }
}

void copia_lista_sem_repetidos(ILista *L, ILista *P){
  int i = 0,j = 0;
  while(i < L->Nelem){
    while(j < P->Nelem){
      if(L->A[i].chave == P->A[j].chave) break;
      j++;
    }
    if(j == P->Nelem){
      P->A[P->Nelem] = L->A[i];
      P->Nelem++;
    }
    i++;
  }
}

void inverte_lista(ILista *L, ILista *P){
  if(aux_vazia(L)) printf("\na primeira lista nao pode ser vazia.");
  P->Nelem = 0;
  int i, j;
  for( i  =  L->Nelem, j = 0; i >= 0; i--, j++){
    P->A[j] = L->A[i];
  }
  P->Nelem = j;
}

void intercala_lista(ILista *L, ILista *P, ILista *K) {
 
  if(aux_vazia(L) || aux_vazia(P)) printf("\na primeira e a segunda lista nao podem ser vazia.");
  int i = 0, j = 0, k = 0;
  while(i < L->Nelem && j < P->Nelem){
    if(L->A[i].chave < P->A[j].chave){
      K->A[k] = L->A[i];
      i++;
    }
    else{
      K->A[k] = P->A[j];
      j++;
    }
    k++;
  }
  while(i < L->Nelem){
    K->A[k] = L->A[i];
    i++;
    k++;
  }
  while(j < P->Nelem){
    K->A[k] = P->A[j];
    j++;
    k++;
  }
  K->Nelem = k;
}

void contador_registros(ILista *L, IListaReg *K){
  if(aux_vazia(L)) printf("\na lista nao pode ser vazia.");
  int i, j;
  for(i = 0; i<L->Nelem; i++){
    K->A[i].chave = L->A[i].chave;
    K->A[i].cont = 0;
    for(j = 0; j <L->Nelem; j++){
      if(L->A[i].chave == L->A[j].chave){
        K->A[i].cont++;
      }
    }
  }
  K->Nelem = L->Nelem;
}

void frequencia_lista(ILista *L) {
  int i , j;
  IListaReg K;
  contador_registros(L, &K);
  int indice_maior, maior, indice_menor, menor;
  for(i = 0; i<(K).Nelem; i++) {
    if(i == 0){
      indice_maior = 0;
      indice_menor =  0;
      menor = (K).A[i].cont;
      maior = (K).A[i].cont;
    }
    if((K).A[i].cont > maior){
      maior =  (K).A[i].cont;
      indice_maior = i;
    }

    if((K).A[i].cont < menor){
      menor =  (K).A[i].cont;
      indice_menor = i;
    }
  }
  printf("\nO maior registro e sua frequencia : %d %d", (K).A[indice_maior].chave, (K).A[indice_maior].cont);
  printf("\nO menor registro e sua frequencia : %d %d", (K).A[indice_menor].chave, (K).A[indice_menor].cont);
}

main() {
  ILista l = {10, 30, 50, 70, 10 , 10};
  (l).Nelem = 6;
  frequencia_lista(&l);

}