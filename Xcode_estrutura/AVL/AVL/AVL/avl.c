/*
 Alunos: Gabrielly Cristine
* Curso: Ciência da Computação
* Trabalho 2: AVL
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: Apple clang version 14.0.3 (clang-1403.0.22.14.1)
* IDE : Xcode
* Sistema Operacional: MacOs Veentura 13.1
 */

#include "avl.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para obter a altura de um nó
int altura(No* no) {
    if (no == NULL)
        return 0; // se o no for null entao altura é 0
    return no->altura; // retorna altura do no
}

// Função para calcular o fator de balanceamento de um nó
int fatorBalanceamento(No* no) {
    if (no == NULL)
        return 0; // Retorna 0 se o nó for nulo (fator balanceamento nulo)
    return altura(no->esquerda) - altura(no->direita); // Calcula o fator de balanceamento do nó
}

// Função para atualizar a altura de um nó
void atualizarAltura(No* no) {
    int alturaEsquerda = altura(no->esquerda); // pega a altura da subárvore esquerda
    int alturaDireita = altura(no->direita); // pega a altura da subárvore direita
    no->altura = (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1; // Atualiza a altura do nó com a maior altura das subárvores + 1
}

// Função para criar um novo nó com os dados de um aluno
No* criarNo(Aluno aluno) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->aluno = aluno;
    novoNo->esquerda = NULL; //  ponteiro da subárvore esquerda como nulo
    novoNo->direita = NULL; //  ponteiro da subárvore direita como nulo
    novoNo->altura = 1; // Define a altura do nó como 1
    return novoNo; // Retorna o novo nó criado
}

// Função para rotacionar a subárvore para a esquerda
No* rotacaoEsquerda(No* no) {
    No* novoRaiz = no->direita; // Define o novo nó raiz como o nó direito do nó atual
    No* subArvore = novoRaiz->esquerda; // Armazena a subárvore esquerda do novo nó raiz

    novoRaiz->esquerda = no; // Define o nó atual como subárvore esquerda do novo nó raiz
    no->direita = subArvore; // Define a antiga subárvore esquerda do novo nó raiz como a subárvore direita do nó atual

    atualizarAltura(no); // Atualiza a altura do nó atual
    atualizarAltura(novoRaiz); // Atualiza a altura do novo nó raiz

    return novoRaiz; // Retorna o novo nó raiz
}

// Função para rotacionar a subárvore para a direita
No* rotacaoDireita(No* no) {
    No* novoRaiz = no->esquerda; // Define o novo nó raiz como o nó esquerdo do nó atual
    No* subArvore = novoRaiz->direita; // Armazena a subárvore direita do novo nó raiz

    novoRaiz->direita = no; // Define o nó atual como subárvore direita do novo nó raiz
    no->esquerda = subArvore; // Define a antiga subárvore direita do novo nó raiz como a subárvore esquerda do nó atual

    atualizarAltura(no); // Atualiza a altura do nó atual
    atualizarAltura(novoRaiz); // Atualiza a altura do novo nó raiz

    return novoRaiz; // Retorna o novo nó raiz
}

// Função para balancear a árvore AVL
No* balancearArvore(No* no) {
    atualizarAltura(no); // atualiza a altura do nó atual

    int fator = fatorBalanceamento(no); // calcula o fator de balanceamento do nó

    // Caso o nó esteja desbalanceado, balancear a arvore
    if (fator > 1) {
        if (fatorBalanceamento(no->esquerda) < 0)
            no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }
    if (fator < -1) {
        if (fatorBalanceamento(no->direita) > 0)
            no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no; // retorna o nó atual
}

// Função para inserir um aluno na árvore
No* inserirAluno(No* raiz, Aluno aluno) {
    if (raiz == NULL)
        return criarNo(aluno);

    if (aluno.matricula < raiz->aluno.matricula)
        raiz->esquerda = inserirAluno(raiz->esquerda, aluno);
    else if (aluno.matricula > raiz->aluno.matricula)
        raiz->direita = inserirAluno(raiz->direita, aluno);
    else
        return raiz; // nao permiti alunos com matriculas iguais

    return balancearArvore(raiz);
}

// Função para buscar um aluno na árvore por matrícula
No* buscarAluno(No* raiz, int matricula) {
    if (raiz == NULL || raiz->aluno.matricula == matricula)
        return raiz;

    if (matricula < raiz->aluno.matricula)
        return buscarAluno(raiz->esquerda, matricula);

    return buscarAluno(raiz->direita, matricula);
    /*
     percorre a árvore comparando a matrícula do nó atual com a matrícula buscada. Se a matrícula for encontrada ou se o nó atual for nulo, a função retorna o nó atual.
     */
}

// Função para encontrar o nó com o valor mínimo na árvore
No* encontrarMinimo(No* no) {
    No* atual = no;

    while (atual->esquerda != NULL) //percorre a arvore sempre indo pela esquerda ate achar um no sem filho da esquerda
        atual = atual->esquerda;

    return atual;
}
// Funcao para remover o aluno
No* removerAluno(No* raiz, int matricula) {
    // Verifica se a árvore está vazia
    if (raiz == NULL)
        return raiz;

    // Verifica se a matrícula desejada é menor que a matrícula do nó atual
    if (matricula < raiz->aluno.matricula)
        raiz->esquerda = removerAluno(raiz->esquerda, matricula);
    // Verifica se a matrícula desejada é maior que a matrícula do nó atual
    else if (matricula > raiz->aluno.matricula)
        raiz->direita = removerAluno(raiz->direita, matricula);
    else {
        // Se encontrou o nó com a matrícula desejada

        // Verifica se o nó tem pelo menos um filho nulo (esquerdo ou direito)
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            // Cria um ponteiro 'temp' para o filho não nulo ou para NULL se ambos forem nulos
            No* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;

            // Verifica se ambos os filhos são nulos
            if (temp == NULL) {
                // Se ambos os filhos são nulos, define a raiz como nula
                temp = raiz;
                raiz = NULL;
            } else {
                // Se apenas um dos filhos é nulo, copia o conteúdo do filho para o nó atual
                *raiz = *temp;
            }

            // Libera a memória ocupada pelo nó a ser removido
            free(temp);
        } else {
            // Se o nó a ser removido tem dois filhos não nulos

            // Encontra o nó mínimo na subárvore direita
            No* temp = encontrarMinimo(raiz->direita);
            // Copia o valor do aluno do nó mínimo para o nó atual
            raiz->aluno = temp->aluno;
            // Remove recursivamente o nó mínimo da subárvore direita
            raiz->direita = removerAluno(raiz->direita, temp->aluno.matricula);
        }
    }

    // Verifica se a raiz se tornou nula após a remoção
    if (raiz == NULL)
        return raiz;

    // Rebalanceia a árvore após a remoção do nó
    return balancearArvore(raiz);
}
// Função para alterar o cadastro de um aluno
void alterarCadastroAluno(No* raiz, int matricula) {
    // Busca o nó correspondente à matrícula do aluno
    No* no = buscarAluno(raiz, matricula);

    // Verifica se o aluno foi encontrado
    if (no == NULL) {
        printf("Aluno nao encontrado.\n");
        return;
    }

    // Solicita ao usuário as novas informações do aluno
    printf("Digite o novo nome: ");
    scanf("%s", no->aluno.nome);

    printf("Digite a nova nota 1: ");
    scanf("%f", &no->aluno.nota);
    
    printf("Digite a nova nota 2: ");
    scanf("%f", &no->aluno.nota2);
    
    printf("Digite a nova nota 3: ");
    scanf("%f", &no->aluno.nota3);

    printf("Cadastro do aluno alterado com sucesso.\n");
}

// Função para exibir os dados de um aluno
void exibirAluno(Aluno aluno) {
    printf("Matricula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);
    printf("Nota: %.2f\n", aluno.nota);
    printf("Nota: %.2f\n", aluno.nota2);
    printf("Nota: %.2f\n", aluno.nota3);
    printf("-------------------------\n");
}

// Função para percorrer a árvore em pré-ordem
void percorrerPreOrdem(No* raiz) {
    if (raiz != NULL) {
        // Exibe os dados do aluno
        exibirAluno(raiz->aluno);
        // percorre as subarvores
        percorrerPreOrdem(raiz->esquerda);

        percorrerPreOrdem(raiz->direita);
    }
}

// Função para percorrer a árvore em in-ordem
void percorrerInOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerInOrdem(raiz->esquerda); // da esquerda
        exibirAluno(raiz->aluno); // exibe aluno
        percorrerInOrdem(raiz->direita); //percorre a da direita
    }
}

// Função para percorrer a árvore em pós-ordem
void percorrerPosOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerPosOrdem(raiz->esquerda);
        percorrerPosOrdem(raiz->direita); // percorre as subarvore

        // Exibe os dados do aluno
        exibirAluno(raiz->aluno);
    }
}

// Função para excluir a árvore
void excluirArvore(No* raiz) {
    if (raiz != NULL) {
        
        excluirArvore(raiz->esquerda);
        excluirArvore(raiz->direita); // exclui as arvores

        // e libera a memória ocupada pelo nó atual
        free(raiz);
    }
}

// Função para listar os alunos aprovados e reprovados
void listarAprovadosReprovados(No* raiz) {
    if (raiz != NULL) {
        // percorre a subarvore esquerda
        listarAprovadosReprovados(raiz->esquerda);

        // calcula a média das notas do aluno
        float media = (raiz->aluno.nota + raiz->aluno.nota2 + raiz->aluno.nota3) / 3.0;

               // verifica se o aluno foi aprovado ou reprovado
               if (media >= 6.0)
                   printf("Aprovado:\n\n");
               else
                   printf("\nReprovado:\n\n");

        // exibe os dados do aluno
        exibirAluno(raiz->aluno);

        // percorre a subárvore direita
        listarAprovadosReprovados(raiz->direita);
    }
}

/*
 funcoes de arquivo
 */

// Função para carregar os dados de um arquivo texto na árvore
No* carregarDados(No* raiz, const char* nomeArquivo) {
    FILE* arquivo = fopen("alunos.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", "alunos.txt");
        return raiz;
    }

    int matricula;
    char nome[50];
    float nota,nota2,nota3;

    // Lê os dados do arquivo e insere os alunos na árvore
    while (fscanf(arquivo, "%d %s %f", &matricula, nome, &nota, &nota2,&nota3) == 5) {
        Aluno aluno;
        aluno.matricula = matricula;
        strcpy(aluno.nome, nome);
        aluno.nota = nota;
        aluno.nota2 =nota2;
        aluno.nota3 = nota3;

        raiz = inserirAluno(raiz, aluno);
    }

    fclose(arquivo);

    return raiz;
}
// Função para salvar os dados da árvore em um arquivo texto
void salvarDados(No* raiz, const char* nomeArquivo) {
    FILE* arquivo = fopen("alunos.txt", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para escrita.\n","alunos.txt");
        return;
    }

    // Chama a função recursiva para salvar os dados no arquivo
    salvarDadosRecursivo(raiz, arquivo);

    fclose(arquivo);
}

// Função auxiliar para salvar os dados da árvore em um arquivo texto (recursiva)
void salvarDadosRecursivo(No* raiz, FILE* arquivo) {
    if (raiz == NULL)
        return;

    // Escreve os dados do aluno no arquivo
    fprintf(arquivo, "%d %s %.2f\n", raiz->aluno.matricula, raiz->aluno.nome, raiz->aluno.nota,raiz->aluno.nota2, raiz->aluno.nota3);

    // Chama a função recursivamente para percorrer a subárvore esquerda e direita
    salvarDadosRecursivo(raiz->esquerda, arquivo);
    salvarDadosRecursivo(raiz->direita, arquivo);
}
