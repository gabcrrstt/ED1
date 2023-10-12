/*
 Alunos: Gabrielly Cristine
* Curso: Ciência da Computação
* Trabalho 1: Listas Lineares
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: Apple clang version 14.0.3 (clang-1403.0.22.14.1)
* IDE : Xcode
* Sistema Operacional: MacOs Veentura 13.1
 */
#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

No* criar_no(int chave) {
    // Aloca memória para um novo nó da árvore
    No* novo_no = (No*)malloc(sizeof(No));
    // Define a chave do nó com o valor fornecido
    novo_no->chave = chave;
    // Inicializa o ponteiro para o filho da esquerda como NULL
    novo_no->esq = NULL;
    // Inicializa o ponteiro para o filho da direita como NULL
    novo_no->dir = NULL;
    // Retorna o ponteiro para o nó recém-criado
    return novo_no;
}


void destruir_no(No* no) {// Libera a memória alocada para o nó
    free(no);
}

void destruir_arvore_recursivo(No* no) {
    // Verifica se o nó é válido (não é NULL)
    if (no != NULL) {
        // Chama a função destruir_arvore_recursivo para o filho da esquerda
        destruir_arvore_recursivo(no->esq);
        // Chama a função destruir_arvore_recursivo para o filho da direita
        destruir_arvore_recursivo(no->dir);
        // Chama a função destruir_no para o próprio nó
        destruir_no(no);
    }
}


void destruir_arvore(Arvore* arvore) {
    // Chama a função destruir_arvore_recursivo para a raiz da árvore
    destruir_arvore_recursivo(arvore->raiz);
    // Define a raiz da árvore como NULL, indicando que a árvore está vazia
    arvore->raiz = NULL;
}

void inserir_recursivo(No* raiz, int chave) {
    // Verifica se a chave é menor que a chave do nó atual
    if (chave < raiz->chave) {
        // Verifica se o filho esquerdo é NULL, indicando que é o local de inserção
        if (raiz->esq == NULL) {
            // Cria um novo nó com a chave informada e define como filho esquerdo do nó atual
            raiz->esq = criar_no(chave);
        } else {
            // Caso contrário, chama a função recursivamente, passando o filho esquerdo como nova raiz
            inserir_recursivo(raiz->esq, chave);
        }
    }
    // Verifica se a chave é maior que a chave do nó atual
    else if (chave > raiz->chave) {
        // Verifica se o filho direito é NULL, indicando que é o local de inserção
        if (raiz->dir == NULL) {
            // Cria um novo nó com a chave informada e define como filho direito do nó atual
            raiz->dir = criar_no(chave);
        } else {
            // Caso contrário, chama a função recursivamente, passando o filho direito como nova raiz
            inserir_recursivo(raiz->dir, chave);
        }
    }
}

void inserir(Arvore* arvore, int chave) {
    // Verifica se a árvore está vazia (raiz é NULL)
    if (arvore->raiz == NULL) {
        // Cria um novo nó com a chave informada e define como raiz da árvore
        arvore->raiz = criar_no(chave);
    } else {
        // Chama a função inserir_recursivo para inserir o elemento na árvore
        inserir_recursivo(arvore->raiz, chave);
    }
}

No* buscar_recursivo(No* raiz, int chave) {
    // Verifica se a raiz é NULL ou se a chave é igual à chave do nó atual
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }

    // Verifica se a chave é menor que a chave do nó atual
    if (chave < raiz->chave) {
        // Chama a função recursivamente, passando o filho esquerdo como nova raiz
        return buscar_recursivo(raiz->esq, chave);
    }

    // A chave é maior que a chave do nó atual
    // Chama a função recursivamente, passando o filho direito como nova raiz
    return buscar_recursivo(raiz->dir, chave);
}

void busca(Arvore* arvore, int chave) {
    // Chama a função buscar_recursivo para buscar o elemento na árvore
    No* no_encontrado = buscar_recursivo(arvore->raiz, chave);
    
    // Verifica se o nó encontrado é diferente de NULL
    if (no_encontrado != NULL) {
        // Elemento encontrado, imprime a mensagem com o valor da chave
        printf("Elemento encontrado: %d\n", no_encontrado->chave);
    } else {
        // Elemento não encontrado
        printf("Elemento não encontrado.\n");
    }
}
No* encontrar_menor_valor(No* raiz) {
    No* atual = raiz;
    
    // Percorre a árvore pelo ramo esquerdo até encontrar o nó mais à esquerda
    while (atual->esq != NULL) {
        atual = atual->esq;
    }
    
    // Retorna o nó encontrado, que será o nó com o menor valor na árvore
    return atual;
}

No* remover_recursivo(No* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }

    if (chave < raiz->chave) {
        raiz->esq = remover_recursivo(raiz->esq, chave);
    } else if (chave > raiz->chave) {
        raiz->dir = remover_recursivo(raiz->dir, chave);
    } else {
        // Caso 1: Nó não possui filhos ou possui apenas um filho
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Caso 2: Nó possui dois filhos
        No* temp = raiz->dir;
        while (temp->esq != NULL) {
            temp = temp->esq;
        }
        raiz->chave = temp->chave;
        raiz->dir = remover_recursivo(raiz->dir, temp->chave);
    }

    return raiz;
}

int altura_recursivo(No* raiz) {
    // Caso base: se a raiz for NULL, a altura é 0
    if (raiz == NULL) {
        return 0;
    } else {
        // Calcula a altura das subárvores esquerda e direita recursivamente
        int altura_esq = altura_recursivo(raiz->esq);
        int altura_dir = altura_recursivo(raiz->dir);
        
        // Retorna a altura máxima entre as subárvores esquerda e direita,
        // incrementada de 1 para contar o próprio nó raiz
        return (altura_esq > altura_dir) ? altura_esq + 1 : altura_dir + 1;
    }
}

int numero_nos_recursivo(No* raiz) {
    // Caso base: se a raiz for NULL, a árvore está vazia e não possui nós
    if (raiz == NULL) {
        return 0;
    } else {
        // Chamada recursiva para contar os nós das subárvores esquerda e direita,
        // e soma 1 para contar o próprio nó raiz
        return numero_nos_recursivo(raiz->esq) + numero_nos_recursivo(raiz->dir) + 1;
    }
}


Arvore criar_arvore() {
    // Agora você tem uma árvore vazia pronta para ser utilizada
    Arvore arvore;
    arvore.raiz = NULL;
    return arvore;
}

void destrui_arvore(Arvore* arvore) {
    // A árvore foi completamente destruída e a memória alocada por ela foi liberada
    destruir_arvore_recursivo(arvore->raiz);
    arvore->raiz = NULL;
}

int buscar(Arvore* arvore, int chave) {
    No* no_encontrado = buscar_recursivo(arvore->raiz, chave);
    if (no_encontrado != NULL) {
        return no_encontrado->chave;
    } else {
        return -1; // Valor de retorno indicando que o elemento não foi encontrado
    }
}

// Função para remover um nó com a chave especificada da árvore
void remover(Arvore* arvore, int chave) {
    arvore->raiz = remover_recursivo(arvore->raiz, chave);
}

// Função para exibir os elementos da árvore em pré-ordem
void exibir_pre_ordem(No* no) {
    if (no != NULL) {
        printf("%d ", no->chave); // Exibe a chave do nó
        exibir_pre_ordem(no->esq); // Percorre a subárvore esquerda em pré-ordem
        exibir_pre_ordem(no->dir); // Percorre a subárvore direita em pré-ordem
    }
}

// Função para exibir os elementos da árvore em ordem
void exibir_em_ordem(No* no) {
    if (no != NULL) {
        exibir_em_ordem(no->esq); // Percorre a subárvore esquerda em ordem
        printf("%d ", no->chave); // Exibe a chave do nó
        exibir_em_ordem(no->dir); // Percorre a subárvore direita em ordem
    }
}

// Função para exibir os elementos da árvore em pós-ordem
void exibir_pos_ordem(No* no) {
    if (no != NULL) {
        exibir_pos_ordem(no->esq); // Percorre a subárvore esquerda em pós-ordem
        exibir_pos_ordem(no->dir); // Percorre a subárvore direita em pós-ordem
        printf("%d ", no->chave); // Exibe a chave do nó
    }
}

// Função para obter a altura da árvore
int altura(Arvore* arvore) {
    return altura_recursivo(arvore->raiz);
}

// Função para obter o número de nós da árvore
int numero_nos(Arvore* arvore) {
    return numero_nos_recursivo(arvore->raiz);
}
