
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



#include "lista.h"

#include <string.h>

#include <stdio.h>

#include <stdlib.h>



void inicializa_lista(Lista *alunos)

{

  alunos->nElem = 0;

}



int vazia_lista(Lista *alunos)

{

  return alunos->nElem == 0;

}



int cheia(Lista *alunos)

{

  return alunos->nElem == MAX;

}



// CRIAR NOVO ALUNO



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









// INSERIR ALUNO

int inserir_aluno(Lista *alunos, Aluno novo_aluno){

    if(alunos->nElem == MAX){

        printf("\nLista cheia, impossivel inserir novo aluno.");

        return 0;

    }else{

        alunos->A[alunos->nElem] = novo_aluno;

        alunos->nElem++;

        printf("\nAluno inserido com sucesso!");

        return 1;

    }

}



// INSERIR O ALUNO NO FINAL DA LISTA

void inserir_aluno_fim_lista(Lista *alunos, Aluno aluno) {

    if (alunos->nElem == MAX) {

        printf("\nlista cheia. impossivel inserir.");

        return;

    }

    alunos->A[alunos->nElem] = aluno;

    alunos->nElem++;

}



// REMOVER ALUNO

int remover_aluno(Lista *alunos, int matricula){

		int i;



  if (vazia_lista(alunos)){



   			 return 0;

	}else{

	 int posicao = busca_sequencial(alunos, matricula);



 		 if (posicao == -1){



    			return 0;



		}else{

			for ( i = posicao; i < alunos->nElem - 1; i++)

  		{

    		alunos->A[i] = alunos->A[i + 1];

  		}



		  alunos->nElem--;

		  return 1;

}

}

}





void alterar_cadastro(Lista *alunos, int matricula)

{

  int posicao = busca_sequencial(alunos, matricula);

  if (posicao == -1)

  {

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

  switch (opcao)

  {

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

    switch (opNotas)

    {

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

  //exibir_alunos(aluno);

}



// EXCLUIR A LISTA





// BUSCAR DADOS DE ALGUM ALUNO ATRAVES DA MATRICULA E EXIBIR

int buscar_dados_aluno(Lista *alunos, int matricula)

{



	if(vazia_lista(alunos)){

    printf("\nnao ha alunos cadastrados.");

    return 0;

	}

	    int i;



    for (i = 0; i < alunos->nElem; i++) {

        if (alunos->A[i].matricula == matricula) {

        	exibir_dados_aluno(alunos->A[i]);

            return i;

        }

    }

    printf("\nAluno nao encontrado.\n");

    return -1;

}



// FUNCAO PARA ENCONTRAR ALUNO COM A MAIOR NOTA DA P1

void encontrar_aluno_com_maior_nota_da_primeira_prova(Lista *alunos) {

 	// VERIFICA SE A LISTA TEM ALGUM ALUNO

  if (vazia_lista(alunos)) {

    printf("\n nao ha alunos cadastrados.");

    return;

  }



  float maior = 0.0 ;

  int i, indice_maiorN1 = -1;

  // percorre a lista procurando o aluno com a maior nota da p1

  for(i = 0; i < alunos->nElem; i++) {

    if(alunos->A[i].nota1 > maior) {

      maior = alunos->A[i].nota1;

      indice_maiorN1 = i;

    }

  }

  // verifica se encontrou algum aluno com a nota da primeira prova

  if(indice_maiorN1 == -1) {

    printf("\nNenhum aluno encontrado.");

    return;

  }



  printf("\nAluno com maior nota na primeira prova: ");

  exibir_dados_aluno(alunos->A[indice_maiorN1]);

}



// FUNCAO PARA ENCONTRAR A MAIOR MEDIA GERAL

void encontrar_aluno_com_maior_media_geral(Lista *alunos){

  // VERIFICA SE A LISTA TEM ALGUM ALUNO

  if (vazia_lista(alunos)) {

    printf("\n nao ha alunos cadastrados.");

    return;

  }



  int i;

  float maior_media = 0;

  int posicao_aluno_maior_media = 0;

  // percorre a lista procurando a maior media

  for(i = 0; i < alunos->nElem; i++){

    float media = (alunos->A[i].nota1 + alunos->A[i].nota2 + alunos->A[i].nota3) / 3;

    //verifica se encontrou

    if(media > maior_media){

      maior_media = media;

      posicao_aluno_maior_media = i;

    }

  }

  //se encontrou o aluno com a maior media exibe

  printf("\nAluno com maior media geral: \n");

  exibir_dados_aluno(alunos->A[posicao_aluno_maior_media]);

  printf("\nMaior media geral: %.2f", maior_media);

}



// FUNCAO DA MENOR MEDIA GERAL ENTRE OS ALUNOS CADASTRADOS

void encontrar_aluno_com_menor_media_geral(Lista *alunos){



  if(vazia_lista(alunos)){

    printf("\nnao ha alunos cadastrados.");

    return;

  }



  float menor = (alunos->A[0].nota1 + alunos->A[0].nota2 + alunos->A[0].nota3) / 3;



  int indice_aluno_menor = 0;



  for(int i = 1; i < alunos->nElem; i++) {

    float media = (alunos->A[i].nota1 + alunos->A[i].nota2 + alunos->A[i].nota3) / 3;

    if(media < menor) {

      menor = media;

      indice_aluno_menor = i;

    }

  }

  printf("\naluno com menor media geral: ");

  exibir_dados_aluno(alunos->A[indice_aluno_menor]);

  printf("\n--->media geral: %.2f\n", menor);

}



// FUNCAO Q LISTA OS APROVADOS E REPROVADOS

void listar_alunos_aprovados_e_reprovados(Lista *alunos) {

  if (vazia_lista(alunos)) {

    printf("\nLista vazia!\n");

    return;

  }



  int i;

  printf("\nAlunos aprovados:\n");

  for (i = 0; i < alunos->nElem; i++) {

    Aluno aluno = alunos->A[i];

    float media = (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;

    if (media >= 6) {

      exibir_dados_aluno(aluno);

    }

  }



  printf("\nAlunos reprovados:\n");

  for (i = 0; i < alunos->nElem; i++) {

    Aluno aluno = alunos->A[i];

    float media = (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;

    if (media < 6) {

      exibir_dados_aluno(aluno);

    }

  }

}

// VERIFICA SE ESTA ORDENADO OU NAO

int verificar_se_lista_esta_ordenada(Lista *alunos) {

  if (alunos->nElem <= 1) { // lista vazia ou com apenas um elemento est� sempre ordenada

    return 1;

  }

  int i;

  for (i = 1; i < alunos->nElem; i++) {

    if (alunos->A[i].matricula < alunos->A[i-1].matricula) {

      return 0; // a lista nao est� ordenada

    }

  }

  return 1; // a lista esta ordenada

}



void fazer_copia_lista_l1_em_lista_l2(Lista *alunos, Lista *alunos2) {

  // Verifica se a lista est� vazia

  if(vazia_lista(alunos)) {

    printf("\nA lista original est� vazia.\n");

    return;

  }



  // Verifica se a lista2 j� possui elementos

  if(!vazia_lista(alunos2)) {

    printf("\nA lista destino n�o est� vazia.\n");

    return;

  }



  // Copia os elementos da lista original para a lista destino

  int i;

  for(i = 0; i < alunos->nElem; i++) {

    alunos2->A[i] = alunos->A[i];

    alunos2->nElem++;

  }



  printf("\nC�pia realizada com sucesso.\n");

}





void inverter_lista_l1_colocando_resultado_em_lista_l2(Lista *alunos, Lista *alunos2) {

    if(vazia_lista(alunos)) {

        printf("\nLista vazia");

        return;

    }



    alunos2->nElem = 0; // Zera a lista 2



    // Percorre a lista 1 de tras ate a fremte

    for(int i = alunos->nElem - 1; i >= 0; i--) {

        // Insere o aluno na lista 2

        inserir_aluno_fim_lista(alunos2, alunos->A[i]);

    }



    printf("\nLista invertida com sucesso!\n");

}



void intercalar_duas_listas_l1_e_l2_gerando_lista_l3(Lista *alunos, Lista *alunos2, Lista *alunos3) {

    int i = 0, j = 0, k = 0;



    while (i < alunos->nElem && j < alunos2->nElem) {

        if (alunos->A[i].matricula < alunos2->A[j].matricula) {

            alunos3->A[k] = alunos->A[i];

            i++;

        } else {

            alunos3->A[k] = alunos2->A[j];

            j++;

        }

        k++;

    }



    while (i < alunos->nElem) {

        alunos3->A[k] = alunos->A[i];

        i++;

        k++;

    }



    while (j < alunos2->nElem) {

        alunos3->A[k] = alunos2->A[j];

        j++;

        k++;

    }



    alunos3->nElem = k;

}



// busca sequencial

int busca_sequencial(Lista *alunos, int matricula)

{

  int i;

  for (i = 0; i < alunos->nElem; i++)

  {

    if (alunos->A[i].matricula == matricula)

      return i;

  }

  return 1;

}



// FUNCAO PARA EXIBIR TODOS OS ALUNOS DA LISTA

int exibir_todos_alunos(Lista *alunos, Aluno aluno)

{

    int i;



	// VERIFICA SE O TAMANHO DA LISTA EH IGUAL A ZERO, SE ISSO ACONTECER A LISTA ESTA? VAZIA



    if(vazia_lista(alunos)) {

        printf("\n LISTA VAZIA \n");

        return 0;

    }

	// EXIBIR NA TELA AS INFORMACOES DOS ALUNOS CADASTRADOS



    else {

        printf("\n ================================== \n");

        printf("\n INFORMACOES SOBRE OS ALUNOS \n");

        printf("\n ================================== \n");



        for( i = 0; i < alunos->nElem; i++) {

            printf("\nMatricula: %d", aluno.matricula);

            printf("\nNome: %s", aluno.nome);

            printf("\nNotas: P1: %.2f P2: %.2f P:3 %.2f\n", aluno.nota1, aluno.nota2, aluno.nota3);

        }

    }

    return 1;

}



void exibir_dados_aluno(Aluno aluno) {

  printf("\n----------------------------------------------------\n");

  printf("\nMatricula: %d", aluno.matricula);

  printf("\nNome: %s", aluno.nome);

  printf("\nNotas: P1: %.2f P2: %.2f P:3 %.2f\n", aluno.nota1, aluno.nota2, aluno.nota3);

  printf("\n----------------------------------------------------\n");

}









