/*
 Alunos: Gabrielly Cristine
* Curso: Ciência da Computação
* Trabalho 1: Listas Lineares
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: Apple clang version 14.0.3 (clang-1403.0.22.14.1)
* IDE : Xcode
* Sistema Operacional: MacOs Veentura 13.1
 */

#ifndef abb_h
#define abb_h

// Definição da estrutura de nó da ABB
typedef struct no {
    int chave;
    struct no* esq;  // Ponteiro para o nó filho esquerdo
    struct no* dir;  // Ponteiro para o nó filho direito
} No;

// Definição da estrutura da ABB
typedef struct {
    No* raiz;  // Ponteiro para o nó raiz da árvore
} Arvore;

// Funções auxiliares
No* criar_no(int chave);
void destruir_no(No* no);
void destruir_arvore_recursivo(No* no);
void inserir_recursivo(No* raiz, int chave);
No* buscar_recursivo(No* raiz, int chave);
No* remover_recursivo(No* raiz, int chave);
int altura_recursivo(No* raiz);
int numero_nos_recursivo(No* raiz);

// Funções da ABB
Arvore criar_arvore();
void destruir_arvore(Arvore* arvore);
void inserir(Arvore* arvore, int chave);
int buscar(Arvore* arvore, int chave);
void remover(Arvore* arvore, int chave);
void exibir_pre_ordem(No* no);
void exibir_em_ordem(No* no);
void exibir_pos_ordem(No* no);
int altura(Arvore* arvore);
int numero_nos(Arvore* arvore);


#endif /* abb_h */
