/*
 Alunos: Gabrielly Cristine
* Curso: CiÍncia da ComputaÁ„o
* Trabalho 1: Listas Lineares
* Estrutura de Dados I-- 2022 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: Apple clang version 14.0.3 (clang-1403.0.22.14.1)
* IDE : Xcode
* Sistema Operacional: MacOs Veentura 13.1
 */
 

#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//inicializa as listas
void inicializa_lista(Lista *alunos) {
    alunos->cabeca = NULL;
}
// se a lista esta vazia
int vazia_lista(Lista *alunos) {
    return alunos->cabeca == NULL;
}

// automatiza a criacao de um novo aluno
Aluno criar_novo_aluno() {
  Aluno aluno;
  printf("Digite o nome do aluno: ");
  scanf("%s", aluno.nome);
  printf("Digite a matricula do aluno: ");
  scanf("%d", &aluno.matricula);
  printf("Digite a nota 1 do aluno: ");
  scanf("%f", &aluno.nota1);
  printf("Digite a nota 2 do aluno: ");
  scanf("%f", &aluno.nota2);
  printf("Digite a nota 3 do aluno: ");
  scanf("%f", &aluno.nota3);
  aluno.media = (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;
  return aluno;
}


void excluir_lista(Lista * alunos){
    /*
     a funÁ„o excluir_lista libera a memÛria alocada para todos os nÛs da lista
     */
    No* p = alunos->cabeca;
        while(p != NULL){
            alunos->cabeca = p->prox;
            free(p);
            p = alunos->cabeca;
        }
}

//insere um novo aluno no inicio da lista
int inserir_aluno(Lista *alunos, Aluno novo_aluno) {
  No *novo_no = (No*) malloc(sizeof(No));
  if(novo_no == NULL) return 0; // para o programa aqui
  
  novo_no->dados_no = novo_aluno;
  novo_no->prox = alunos->cabeca;
  alunos->cabeca = novo_no;
  return 1;
  
}

//remove um aluno da lista pelo numero da matricula.
int remover_aluno(Lista *alunos, int matricula) {
  if (vazia_lista(alunos)) return 0; // Verifica se a lista est· vazia
  
  No* i = alunos->cabeca; // Ponteiro para percorrer a lista
  No* j = NULL; // Ponteiro auxiliar
  
  // Caso especial: o aluno a ser removido est· no inÌcio da lista
  if (i != NULL && i->dados_no.matricula == matricula) {
    alunos->cabeca = i->prox; // Atualiza a cabeÁa da lista
    free(i); // Libera a memÛria do nÛ
    return 1; // Indica que o aluno foi removido com sucesso
  }
  
  // Busca o aluno na lista
  while (i != NULL && i->dados_no.matricula != matricula) {
    j = i; // Armazena o nÛ anterior
    i = i->prox; // AvanÁa para o prÛximo nÛ
  }
  
  if (i == NULL) return 0; // Aluno n„o encontrado na lista
  
  j->prox = i->prox; // Atualiza os ponteiros do nÛ anterior
  free(i); // Libera a memÛria do nÛ encontrado
  return 1; // Indica que o aluno foi removido com sucesso
}
void alterar_cadastro(Lista *alunos, int matricula){
    //altera o cadastro de um aluno ja cadastrado buscando pela matricula
    
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

void buscar_dados_aluno(Lista *alunos, int matricula) {
  if (vazia_lista(alunos)) {
    printf("\nnao ha alunos cadastrados.");
    return;
  }
  
  No* aluno = alunos->cabeca; // Ponteiro para percorrer a lista
  
  // Percorre a lista em busca do aluno com a matrÌcula especificada
  for (aluno; aluno != NULL; aluno = aluno->prox) {
    if (aluno->dados_no.matricula == matricula) {
      exibir_dados_aluno(aluno->dados_no); // Exibe os dados do aluno encontrado
      return;
    }
  }
  
  printf("\n aluno nao encontrado"); // Aluno n„o encontrado na lista
}

void encontrar_aluno_com_maior_nota_da_primeira_prova(Lista *alunos) {
  if (vazia_lista(alunos)) {
    printf("\nnao ha alunos cadastrados.");
    return;
  }
  
  No* aluno = alunos->cabeca; // Ponteiro para percorrer a lista
  float maior = 0.0;
  No* aluno_maiorN1 = NULL; // Ponteiro para armazenar o aluno com a maior nota
  
  // Percorre a lista em busca do aluno com a maior nota na primeira prova
  for (aluno; aluno != NULL; aluno = aluno->prox) {
    if (aluno->dados_no.nota1 > maior) {
      aluno_maiorN1 = aluno;
      maior = aluno_maiorN1->dados_no.nota1;
    }
  }
  
  if (aluno_maiorN1 == NULL) {
    printf("\nNenhum aluno encontrado.");
    return;
  }
  
  printf("\naluno com maior nota na primeira prova: ");
  exibir_dados_aluno(aluno_maiorN1->dados_no); // Exibe os dados do aluno com a maior nota
}

void encontrar_aluno_com_maior_media_geral(Lista *alunos) {
  if (vazia_lista(alunos)) {
    printf("\nnao ha alunos cadastrados.");
    return;
  }
  
  No* aluno = alunos->cabeca; // Ponteiro para percorrer a lista
  float maior = 0.0;
  No* aluno_maior = NULL; // Ponteiro para armazenar o aluno com a maior mÈdia
  
  // Percorre a lista em busca do aluno com a maior mÈdia geral
  for (aluno; aluno != NULL; aluno = aluno->prox) {
    float media = (aluno->dados_no.nota1 + aluno->dados_no.nota2 + aluno->dados_no.nota3) / 3;
    if (media > maior) {
      aluno_maior = aluno;
      maior = media;
    }
  }
  
  if (aluno_maior == NULL) {
    printf("\nNenhum aluno encontrado.");
    return;
  }
  
  printf("\naluno com maior media geral: ");
  exibir_dados_aluno(aluno_maior->dados_no); // Exibe os dados do aluno com a maior mÈdia
  printf("\n--->media geral: %.2f\n", maior); // Exibe a mÈdia geral do aluno
}

void encontrar_aluno_com_menor_media_geral(Lista *alunos) {
  if (vazia_lista(alunos)) {
    printf("\nnao ha alunos cadastrados.");
    return;
  }
  
  No* aluno = alunos->cabeca; // Ponteiro para percorrer a lista
  float menor = 100.0;
  No* aluno_menor = NULL; // Ponteiro para armazenar o aluno com a menor mÈdia
  
  // Percorre a lista em busca do aluno com a menor mÈdia geral
  for (aluno; aluno != NULL; aluno = aluno->prox) {
    float media = (aluno->dados_no.nota1 + aluno->dados_no.nota2 + aluno->dados_no.nota3) / 3;
    if (media < menor) {
      aluno_menor = aluno;
      menor = media;
    }
  }
  
  if (aluno_menor == NULL) {
    printf("\nNenhum aluno encontrado.");
    return;
  }
  
  printf("\naluno com menor media geral: ");
  exibir_dados_aluno(aluno_menor->dados_no); // Exibe os dados do aluno com a menor mÈdia
  printf("\n--->media geral: %.2f\n", menor); // Exibe a mÈdia geral do aluno
}

void listar_alunos_aprovados_e_reprovados(Lista *alunos) {
  if (vazia_lista(alunos)) {
    printf("\nLista vazia!\n");
    return;
  }
  
  No* aluno = alunos->cabeca; // Ponteiro para percorrer a lista
  
  // Percorre a lista e verifica a situaÁ„o de cada aluno
  for (aluno; aluno != NULL; aluno = aluno->prox) {
    float media = (aluno->dados_no.nota1 + aluno->dados_no.nota2 + aluno->dados_no.nota3) / 3;
    
    if (media >= 6) {
      printf("\naluno aprovado: ");
      exibir_dados_aluno(aluno->dados_no); // Exibe os dados do aluno aprovado
    } else {
      printf("\naluno reprovado: ");
      exibir_dados_aluno(aluno->dados_no); // Exibe os dados do aluno reprovado
    }
  }
}

int verificar_se_lista_esta_ordenada(Lista *alunos) {
  No* aluno = alunos->cabeca; // Ponteiro para percorrer a lista
  
  while (aluno->prox != NULL) {
    if (aluno->dados_no.matricula < aluno->prox->dados_no.matricula) {
      return 0; // A lista n„o est· ordenada
    }
    aluno = aluno->prox; // AvanÁa para o prÛximo aluno
  }
  
  return 1; // A lista est· ordenada
}
void fazer_copia_lista_l1_em_lista_l2(Lista *alunos, Lista *alunos2) {
  No* aluno = alunos->cabeca; // Ponteiro para percorrer a lista original
  
  for (aluno; aluno != NULL; aluno = aluno->prox) {
    inserir_aluno(alunos2, aluno->dados_no); // Insere o aluno na lista de destino
  }
}


void inverter_lista_l1_colocando_resultado_em_lista_l2(Lista *alunos, Lista *alunos2) {
    /*
     inverte a ordem dos elementos na lista alunos, copia essa lista para a lista alunos2 e exibe a lista alunos invertida.
     */
  if (vazia_lista(alunos)) {
    printf("\nnao ha alunos cadastrados.");
    return;
  }

  // Copia a lista alunos em alunos2
  No* aluno = alunos->cabeca;
  for (aluno ; aluno != NULL; aluno = aluno->prox) {
    inserir_aluno(alunos2, aluno->dados_no);
  }

  // Inverte a lista alunos em si mesma
  No *anterior = NULL, *atual = alunos->cabeca, *proximo = NULL;
  while (atual != NULL) {
    proximo = atual->prox;
    atual->prox = anterior;
    anterior = atual;
    atual = proximo;
  }
  alunos->cabeca = anterior;

  // Exibe a lista invertida
  printf("\nlista invertida: ");
  aluno = alunos->cabeca;
  while (aluno != NULL) {
    exibir_dados_aluno(aluno->dados_no);
    aluno = aluno->prox;
  }
}

void inserir_aluno_fim_lista(Lista *alunos, Aluno novo_aluno) {
    // Aloca um novo nÛ e atribui o novo aluno a ele
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->dados_no = novo_aluno;
    novo_no->prox = NULL;

    // Se a lista estiver vazia, insere o novo nÛ como a cabeÁa
    if (alunos->cabeca == NULL) {
        alunos->cabeca = novo_no;
    } else {
        // Percorre a lista atÈ o ˙ltimo nÛ
        No *ultimo_no = alunos->cabeca;
        while (ultimo_no->prox != NULL) {
            ultimo_no = ultimo_no->prox;
        }

        // Insere o novo nÛ no final da lista
        ultimo_no->prox = novo_no;
    }
}
void intercalar_duas_listas_l1_e_l2_gerando_lista_l3(Lista *alunos, Lista *alunos2, Lista *alunos3) {
    /*
     intercalar os elementos de alunos e alunos2 em ordem crescente de matrÌcula gerando uma nova lista alunos3.
     */
   
    No *no1 = alunos->cabeca;
    No *no2 = alunos2->cabeca;

    // Percorre as duas listas enquanto houver elementos em ambas
    while (no1 != NULL && no2 != NULL) {
        // Compara as matrÌculas dos alunos dos nÛs correntes
        if (no1->dados_no.matricula < no2->dados_no.matricula) {
            // Insere o aluno da lista 1 na lista 3
            inserir_aluno_fim_lista(alunos3, no1->dados_no);
            no1 = no1->prox;
        } else {
            // Insere o aluno da lista 2 na lista 3
            inserir_aluno_fim_lista(alunos3, no2->dados_no);
            no2 = no2->prox;
        }
    }

    // Se ainda restarem elementos na lista 1, insere todos na lista 3
    while (no1 != NULL) {
        inserir_aluno_fim_lista(alunos3, no1->dados_no);
        no1 = no1->prox;
    }

    // Se ainda restarem elementos na lista 2, insere todos na lista 3
    while (no2 != NULL) {
        inserir_aluno_fim_lista(alunos3, no2->dados_no);
        no2 = no2->prox;
    }

        printf("\nLista 3:\n");
            No *no3 = alunos3->cabeca;
             while (no3 != NULL) {
            exibir_dados_aluno(no3->dados_no);
            no3 = no3->prox;
                }
}


void atualizar_arquivo(Lista *alunos) {
    FILE *fp;
    fp= fopen("/Users/gabriellycristine/Documents/Xcode_estrutura/DINAMICA/DINAMICA/alunos.txt","r+");
    
  if (fp == NULL) {
    printf("Erro na abertura do arquivo");
    return;
  }
  
  No *aluno = alunos->cabeca;
  while (aluno != NULL) {
      // Grava as informações do aluno no arquivo no formato: matricula;nome;nota1;nota2;nota3
    fprintf(fp, "%d;%s;%f;%f;%f\n", aluno->dados_no.matricula, aluno->dados_no.nome, aluno->dados_no.nota1, aluno->dados_no.nota2, aluno->dados_no.nota3);
    aluno = aluno->prox;
  }
  
  fclose(fp);
}

//exibir todos os alunos da lista
int exibir_todos_alunos(Lista *alunos, Aluno aluno){
    
    if(vazia_lista(alunos)) { // verifica se a lista esta vazia
        printf("\n LISTA VAZIA \n");
        return 0;
    }
    
    // imprime as informacoes de todos os alunos
        else {
            printf("===================================\n");
            printf(" INFORMACOES SOBRE OS ALUNOS\n");
            printf("===================================\n");
            No *atual = alunos->cabeca;
            while (atual != NULL) {
                Aluno aluno = atual->dados_no;
                printf("\nMatricula: %d\n", aluno.matricula);
                printf("Nome: %s\n", aluno.nome);
                printf("Notas: P1: %.2f P2: %.2f P3: %.2f\n", aluno.nota1, aluno.nota2, aluno.nota3);
                printf("Media: %.2f\n\n", aluno.media);
                atual = atual->prox;
            }
        }
        return 1;
}


void exibir_dados_aluno(Aluno aluno){
    /*
     È usada para imprimir as informaÁıes de um Aluno
     */
  printf("\n----------------------------------------------------\n");
  printf("\nMatricula: %d", aluno.matricula);
  printf("\nNome: %s", aluno.nome);
  printf("\nNotas: P1: %.2f P2: %.2f P:3 %.2f\n", aluno.nota1, aluno.nota2, aluno.nota3);
  printf("MÈdia: %.2f", aluno.media); // exibe a mÈdia
  printf("\n----------------------------------------------------\n");
}

