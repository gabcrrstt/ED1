/*
 Alunos: Gabrielly Cristine
* Curso: Ciência da Computação
* Trabalho 2: AVL
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: Apple clang version 14.0.3 (clang-1403.0.22.14.1)
* IDE : Xcode
* Sistema Operacional: MacOs Veentura 13.1
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "avl.h"


int main(){
    int op=0, matricula, res, ord;
    
    No* raiz = NULL;
    Aluno aluno;
    
    FILE *fp;
    fp= fopen("alunos.txt","r+");
    if (!fp) {
        printf("Erro na abertura do arquivo");
        exit(0);
    } else {
        while(!feof(fp) ) {
            while (op != 8) {
                printf("Escolha uma opcao:\n");
                printf("1. Inserir aluno\n");
                printf("2. Remover aluno\n");
                printf("3. Alterar cadastro do aluno\n");
                printf("4. Excluir a arvore\n");
                printf("5. Buscar dados de um aluno\n");
                printf("6. Exibir todos os dados de todos os alunos (pre-ordem, in-ordem e pos-ordem)\n");
                printf("7. Listar alunos aprovados e reprovados\n");
                printf("8. Sair\n");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        printf("Digite a matricula do aluno: ");
                        scanf("%d", &aluno.matricula);
                        printf("Digite o nome do aluno: ");
                        scanf("%s", aluno.nome);
                        printf("Digite a 1 nota do aluno: ");
                        scanf("%f", &aluno.nota);
                        printf("Digite a 2 nota do aluno: ");
                        scanf("%f", &aluno.nota2);
                        printf("Digite a 3 nota do aluno: ");
                        scanf("%f", &aluno.nota3);
                        raiz = inserirAluno(raiz, aluno);
                        printf("Aluno inserido com sucesso.\n");
                        break;
                    case 2:
                        printf("Digite a matricula do aluno a ser removido: ");
                        scanf("%d", &matricula);
                        raiz = removerAluno(raiz, matricula);
                        printf("Aluno removido com sucesso.\n");
                        break;
                    case 3:
                        printf("Digite a matricula do aluno a ser alterado: ");
                        scanf("%d", &matricula);
                        alterarCadastroAluno(raiz, matricula);
                        break;
                    case 4:
                        excluirArvore(raiz);
                        raiz = NULL;
                        printf("Arvore excluida com sucesso.\n");
                        break;
                    case 5:
                        printf("Digite a matricula do aluno a ser buscado: ");
                        scanf("%d", &matricula);
                        No* alunoEncontrado = buscarAluno(raiz, matricula);
                        if (alunoEncontrado != NULL) {
                            printf("Aluno encontrado:\n");
                            exibirAluno(alunoEncontrado->aluno);
                        } else {
                            printf("Aluno nao encontrado.\n");
                        }
                        break;
                    case 6:
                        printf("\nPre-ordem:\n\n");
                        percorrerPreOrdem(raiz);
                        printf("\nIn-ordem:\n\n");
                        percorrerInOrdem(raiz);
                        printf("\nPos-ordem:\n\n");
                        percorrerPosOrdem(raiz);
                        break;
                    case 7:
                        printf("Lista de alunos aprovados e reprovados:\n");
                        listarAprovadosReprovados(raiz);
                        break;
                    default:
                        break;
                }
            }
            salvarDados(raiz, "dados_modificados.txt");
            excluirArvore(raiz);
            fclose(fp);
            return 0;
        }
    }
    
}



