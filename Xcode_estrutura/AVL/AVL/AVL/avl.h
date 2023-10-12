/*
 Alunos: Gabrielly Cristine
* Curso: Ciência da Computação
* Trabalho 2: AVL
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: Apple clang version 14.0.3 (clang-1403.0.22.14.1)
* IDE : Xcode
* Sistema Operacional: MacOs Veentura 13.1
 */


#ifndef avl_h
#define avl_h
#include <stdio.h>

// Definição da estrutura do aluno
typedef struct {
    int matricula;
    char nome[50];
    float nota,nota2,nota3;
} Aluno;

// Definição do nó da árvore
typedef struct No {
    Aluno aluno;
    struct No* esquerda;
    struct No* direita;
    int altura;
} No;

int altura(No* no);
int fatorBalanceamento(No* no);
void atualizarAltura(No* no);
No* criarNo(Aluno aluno);
No* rotacaoEsquerda(No* no);
No* rotacaoDireita(No* no);
No* balancearArvore(No* no);
No* inserirAluno(No* raiz, Aluno aluno);
No* buscarAluno(No* raiz, int matricula);
No* encontrarMinimo(No* no);
No* removerAluno(No* raiz, int matricula);
void alterarCadastroAluno(No* raiz, int matricula);
void exibirAluno(Aluno aluno);
void percorrerPreOrdem(No* raiz);
void percorrerInOrdem(No* raiz);
void percorrerPosOrdem(No* raiz);
void excluirArvore(No* raiz);
void listarAprovadosReprovados(No* raiz);

No* carregarDados(No* raiz, const char* nomeArquivo);
void salvarDados(No* raiz, const char* nomeArquivo);
void salvarDadosRecursivo(No* raiz, FILE* arquivo);


#endif /* avl_h */
