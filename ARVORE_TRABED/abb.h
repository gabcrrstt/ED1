/**********************************************************
*****
* Alunos: Gabrielly Cristine 
* Curso: Ci�ncia da Computa��o
* Trabalho 1: Listas Lineares
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: gcc (tdm-1) 4.9.2
* IDE : Vscode
* Sistema Operacional: MacOs Veentura 13.1
***********************************************************
****/
 
#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

typedef struct no No;
typedef struct arvore Arvore;

Arvore* cria_arvore();
No* cria_no(int valor);
void destroi_arvore(Arvore* arvore);
void destroi_no(No* no);
No* busca(Arvore* arvore, int valor);
void insere(Arvore* arvore, int valor);
void remove_no(Arvore* arvore, int valor);
void exibe_pre_ordem(Arvore* arvore);
void exibe_in_ordem(Arvore* arvore);
void exibe_pos_ordem(Arvore* arvore);
int altura(Arvore* arvore);
int conta_nos(Arvore* arvore);

#endif // ABB_H_INCLUDED
