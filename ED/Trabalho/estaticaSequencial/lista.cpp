/**********************************************************
*****
* Alunos: William Cardoso Barbosa 
* Curso: Ciência da Computação
* Trabalho 1: Listas Lineares
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: gcc (tdm-1) 4.9.2
* IDE : Vscode
* Sistema Operacional: Windows 11 e Windows 10
***********************************************************
****/
#include "lista.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Aluno criar_novo_aluno() {
  Aluno novo_aluno;
  printf("Digite o nome do aluno: ");
  scanf("%s", novo_aluno.nome);
  printf("Digite a matricula do aluno: ");
  scanf("%d", &novo_aluno.matricula);
  printf("Digite a nota da primeira prova: ");
  scanf("%f", &novo_aluno.nota1);
  printf("Digite a nota da segunda prova: ");
  scanf("%f", &novo_aluno.nota2);
  printf("Digite a nota da terceira prova: ");
  scanf("%f", &novo_aluno.nota3);
  return novo_aluno;
}

int inserir_aluno(Lista *alunos, Aluno novo_aluno){
  if(cheia(alunos)) return 0;
  alunos->A[alunos->nElem] = novo_aluno;
  alunos->nElem++;
  return 1;
}

int remover_aluno(Lista *alunos, int matricula){
  if(vazia_lista(alunos)) return 0;
  int posicao = busca_sequencial(alunos, matricula);
  if(posicao == -1) return 0;
  for(int i = posicao; i < alunos->nElem - 1; i++){
    alunos->A[i] = alunos->A[i + 1];
  }
  alunos->nElem--;
  return 1;
}

void alterar_cadastro(Lista *alunos, int matricula){
  int posicao = busca_sequencial(alunos, matricula);
  if(posicao == -1) {
    printf("Aluno nao encontrado\n");
    return;
  }
  Aluno aluno = alunos->A[posicao];
  int opcao, opNotas;
  printf("1 - Alterar nome\n");
  printf("2 - Alterar nota\n");
  printf("3 - Alterar matricula\n");
  printf("4 - Sair\n");
  scanf("%d", &opcao);
  switch(opcao) {
    case 1:
      printf("Digite o novo nome: ");
      char nome[20];
      scanf("%s", nome);
      strcpy(aluno.nome, nome);
      break;
    case 2:
      printf("\nQue nota voce deseja alterar?\n");
      printf("1 - Primeira nota\n");
      printf("2 - Segunda nota\n");
      printf("3 - Terceira nota\n");
      scanf("%d", &opNotas);
      switch(opNotas) {
        case 1:
          printf("Digite a nova nota: ");
          scanf("%f", &aluno.nota1);
          break;
        case 2:
          printf("Digite a nova nota: ");
          scanf("%f", &aluno.nota2);
          break;
        case 3:
          printf("Digite a nova nota: ");
          scanf("%f", &aluno.nota3);
          break;
        default:
          printf("Opcao invalida\n");
          break;
      }
      break;
    case 3:
      printf("Digite a nova matricula: ");
      scanf("%d", &aluno.matricula);
      break;
    case 4:
      break;
    default:
      printf("Opcao invalida\n");
      break;
  }
  exibir_dados_aluno(aluno);
}

void excluir_lista(Lista *alunos){}
void buscar_dados_aluno(Lista *alunos, int matricula){}
void exibir_todos_dados_alunos(Lista *alunos){}
void encontrar_aluno_com_maior_nota_da_primeira_prova(Lista *alunos){}
void encontrar_aluno_com_maior_media_geral(Lista *alunos){}
void encontrar_aluno_com_menor_media_geral(Lista *alunos){}
void listar_alunos_aprovados_e_reprovados(Lista *alunos){}
int verificar_se_lista_esta_ordenada(Lista *alunos){}
void fazer_copia_lista_l1_em_lista_l2(Lista *alunos, Lista *alunos2){}
void inverter_lista_l1_colocando_resultado_em_lista_l2(Lista *alunos, Lista *alunos2){}
void intercalar_duas_listas_l1_e_l2_gerando_lista_l3(Lista *alunos, Lista *alunos2,  Lista *alunos3){}

//auxiliares
void inicializa_lista(Lista *alunos) {
  alunos->nElem = 0;
}

int vazia_lista(Lista *alunos){
  return alunos->nElem == 0;
}

int cheia(Lista *alunos) {
  return alunos->nElem == MAX;
}

int busca_sequencial(Lista *alunos, int matricula){
  int i;
  for(i = 0; i < alunos->nElem; i++){
    if(alunos->A[i].matricula == matricula) return i;
  }
  return -1;
}

void exibir_dados_aluno(Aluno aluno) {
  printf("\n----------------------------------------------------\n");
  printf("\nMatricula: %d", aluno.matricula);
  printf("\nNome: %s", aluno.nome);
  printf("\nNotas: P1: %.2f P2: %.2f P:3 %.2f\n", aluno.nota1, aluno.nota2, aluno.nota3);
  printf("\n----------------------------------------------------\n");
}