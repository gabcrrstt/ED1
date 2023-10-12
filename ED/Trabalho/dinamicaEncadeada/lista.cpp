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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Aluno criar_novo_aluno() {
  //automatiza a criação de um novo aluno
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

int inserir_aluno(Lista *alunos, Aluno novo_aluno) {
  //insere um novo aluno no inicio da lista
  No *novo_no = (No*) malloc(sizeof(No));
  if(novo_no == NULL) return 0; // para o programa aqui
  novo_no->dados_no = novo_aluno;
  novo_no->prox = alunos->cabeca; 
  alunos->cabeca = novo_no;
}

int remover_aluno(Lista *alunos, int matricula){
  //remove um aluno da lista pelo numero da matricula.
  if(vazia_lista(alunos)) return 0;
  No* i = alunos->cabeca;
  No* j = NULL;
  while(i != NULL && i -> dados_no.matricula != matricula){
    j = i;
    i = i -> prox;
  }
  if (i == NULL) return 0;
  if (j ==  NULL) {
    j ->prox = i->prox;
    free(i);
    return 1;
  }
  j ->prox = i->prox;
  free(i);
  return 1;
}

void alterar_cadastro(Lista *alunos, int matricula){
  //altera o cadastro de um aluno da lista pelo numero da matricula.
  //ativa um menu para o usuário pode escolher qual informação deseja alterar.
  No* aluno = alunos->cabeca;
  for(aluno ; aluno != NULL; aluno = aluno->prox) {
    if(aluno->dados_no.matricula == matricula) {
      exibir_dados_aluno(aluno->dados_no);
      break;
    }
  }
  if(aluno == NULL) {
    printf("Aluno nao encontrado\n");
    return;
  }
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
      strcpy(aluno->dados_no.nome, nome);
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
          scanf("%f", &aluno->dados_no.nota1);
          break;
        case 2:
          printf("Digite a nova nota: ");
          scanf("%f", &aluno->dados_no.nota2);
          break;
        case 3:
          printf("Digite a nova nota: ");
          scanf("%f", &aluno->dados_no.nota3);
          break;
        default:
          printf("Opcao invalida\n");
          break;
      }
      break;
    case 3:
      printf("Digite a nova matricula: ");
      scanf("%d", &aluno->dados_no.matricula);
      break;
    case 4:
      break;
    default:
      printf("Opcao invalida\n");
      break;
  }
  exibir_dados_aluno(aluno->dados_no);
}
void excluir_lista(Lista *alunos){
  //remove todos os alunos da lista.
  No* aluno = alunos->cabeca;
  No* p;
  for(aluno ; aluno != NULL; aluno = aluno->prox) {
    p = aluno;
    free(p);
  }
  alunos->cabeca = NULL;
  printf("\nlista limpa");
}
void buscar_dados_aluno(Lista *alunos, int matricula){
  //retorna os dados de um aluno da lista pelo numero da matricula.
  if(vazia_lista(alunos)){
    printf("\nnao ha alunos cadastrados.");
    return;
  }
  No* aluno = alunos->cabeca;
  for(aluno ; aluno != NULL; aluno = aluno->prox) {
    if(aluno->dados_no.matricula == matricula) {
      exibir_dados_aluno(aluno->dados_no);
      return;
    }
  }
  printf("\naluno nao encontrado");
}
void exibir_todos_dados_alunos(Lista *alunos){
  No* aluno = alunos->cabeca;
  for(aluno ; aluno != NULL; aluno = aluno->prox) {
    exibir_dados_aluno(aluno->dados_no);
  }
}
void encontrar_aluno_com_maior_nota_da_primeira_prova(Lista *alunos){
  No* aluno = alunos->cabeca;
  float maior = 0.0 ;
  No* aluno_maiorN1 = NULL;
  for(aluno; aluno != NULL; aluno = aluno->prox) {
    if(aluno->dados_no.nota1 > maior) {
      aluno_maiorN1 = aluno;
      maior = aluno_maiorN1->dados_no.nota1;
    }
  }
  printf("\naluno com maior nota na primeira prova: ");
  exibir_dados_aluno(aluno_maiorN1->dados_no);
}
void encontrar_aluno_com_maior_media_geral(Lista *alunos){
  No* aluno = alunos->cabeca;
  float maior = 0.0 ;
  No* aluno_maior = NULL;
  for(aluno; aluno != NULL; aluno = aluno->prox) {
    float nota = ((aluno->dados_no.nota1 + aluno->dados_no.nota2 + aluno->dados_no.nota3) / 3);
    if( nota > maior) {
      aluno_maior = aluno;
      maior = nota;
    }
  }
  printf("\naluno com maior media geral: ");
  exibir_dados_aluno(aluno_maior->dados_no);
  printf("\n--->media geral: %.2f\n", maior);
}
void encontrar_aluno_com_menor_media_geral(Lista *alunos){
  No* aluno = alunos->cabeca;
  float menor = 100.0 ;
  No* aluno_menor = NULL;
  for(aluno; aluno != NULL; aluno = aluno->prox) {
    float nota = ((aluno->dados_no.nota1 + aluno->dados_no.nota2 + aluno->dados_no.nota3) / 3);
    if( nota < menor) {
      aluno_menor = aluno;
      menor = nota;
    }
  }
  printf("\naluno com menor media geral: ");
  exibir_dados_aluno(aluno_menor->dados_no);
  printf("\n--->media geral: %.2f\n", menor);
}
void listar_alunos_aprovados_e_reprovados(Lista *alunos){
  No* aluno = alunos->cabeca;
  for(aluno ; aluno != NULL; aluno = aluno->prox) {
    float nota = ((aluno->dados_no.nota1 + aluno->dados_no.nota2 + aluno->dados_no.nota3) / 3);
    if( nota >= 7) {
      printf("\naluno aprovado: ");
      exibir_dados_aluno(aluno->dados_no);
    }
    else {
      printf("\naluno reprovado: ");
      exibir_dados_aluno(aluno->dados_no);
    }
  }
}
int verificar_se_lista_esta_ordenada(Lista *alunos) {
  //verifica se a lista está ordenada de forma crescente.
  No* aluno = alunos->cabeca;
  while (aluno->prox != NULL) {
    if(aluno->dados_no.matricula < aluno->prox->dados_no.matricula) {
      return 0;
    }
    aluno = aluno->prox;
  }
  return 1;
}
void fazer_copia_lista_l1_em_lista_l2(Lista *alunos, Lista *alunos2){
  //faz uma copia da lista l1 em l2 a partir da inserção de elementos.
  No* aluno = alunos->cabeca;
  for(aluno ; aluno != NULL; aluno = aluno->prox) {
    inserir_aluno(alunos2, aluno->dados_no);
  } 
}
void inverter_lista_l1_colocando_resultado_em_lista_l2(Lista *alunos, Lista *alunos2){
  if (vazia_lista(alunos)) {
    printf("\nnao ha alunos cadastrados.");
    return;
  }
  No* aluno = alunos->cabeca;
  No* aluno2 = alunos2->cabeca;
  for(aluno ; aluno != NULL; aluno = aluno->prox) {
    inserir_aluno(alunos2, aluno->dados_no);
  }
  for(aluno2 ; aluno2 != NULL; aluno2 = aluno2->prox) {
    inserir_aluno(alunos, aluno2->dados_no);
  }
  printf("\nlista invertida: ");
  exibir_todos_dados_alunos(alunos2);
}

/*
Nota
A função de intercalar não apresenta muito sentido nesse caso, tendo em vista que trabalhamos apenas
com uma lista encadeada. Para efeito dessa parte do trabalho, poderiamos intercalar a lista principal
com a lista gerada pela função "fazer_copia_lista_l1_em_lista_l2". No entanto, essa função somente
copia lista, ou seja , intercalariamos 2 listas iguais, o que não apresenta sentido nesse caso.
*/
void intercalar_duas_listas_l1_e_l2_gerando_lista_l3(Lista *alunos, Lista *alunos2,  Lista *alunos3);

//auxiliares
void inicializa_lista(Lista *alunos) {
  alunos->cabeca = NULL;
}
int vazia_lista(Lista *alunos) {
  return alunos->cabeca == NULL;
}

void exibir_dados_aluno(Aluno aluno){
  printf("\n----------------------------------------------------\n");
  printf("\nMatricula: %d", aluno.matricula);
  printf("\nNome: %s", aluno.nome);
  printf("\nNotas: P1: %.2f P2: %.2f P:3 %.2f\n", aluno.nota1, aluno.nota2, aluno.nota3);
  printf("\n----------------------------------------------------\n");
}
