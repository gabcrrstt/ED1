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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void inicializa_lista(Lista *alunos)
{// inicializa a lista
  alunos->nElem = 0;
}

int vazia_lista(Lista *alunos)
{ // verifica se a lista esta vazia
  return alunos->nElem == 0;
}

int cheia(Lista *alunos)
{ // verifica se a lista esta cheia
  return alunos->nElem == MAX;
}
// exclui a lista
void excluir_lista(Lista* lista) {
    lista->nElem = 0;
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

int inserir_aluno(Lista *alunos, Aluno novo_aluno) {
    //inserir no inicio
    if (cheia(alunos)) { // Verifica se a lista est· cheia
        printf("\nLista cheia, impossÌvel inserir novo aluno."); // Mensagem de erro caso a lista esteja cheia
        return 0; // Retorna 0 para indicar falha na inserÁ„o
    } else {
        alunos->A[alunos->nElem] = novo_aluno; // Insere o novo aluno na prÛxima posiÁ„o disponÌvel da lista
        alunos->nElem++; // Incrementa o n˙mero de elementos na lista
        printf("\nAluno inserido com sucesso!"); // Mensagem de sucesso na inserÁ„o
        return 1; // Retorna 1 para indicar sucesso na inserÁ„o
    }
}


void inserir_aluno_fim_lista(Lista *alunos, Aluno aluno) { // inserir no final
    // Verifica se a lista est· cheia
    if (cheia(alunos)) {
        printf("\nLista cheia. ImpossÌvel inserir."); // Mensagem de erro caso a lista esteja cheia
        return;
    }
    
    // Insere o aluno no final da lista
    alunos->A[alunos->nElem] = aluno; // Insere o aluno na posiÁ„o nElem
    alunos->nElem++; // Incrementa o n˙mero de elementos na lista
}

int remover_aluno(Lista *alunos, int matricula) { // remover pela matricula
    int i;
        
    // Verifica se a lista est· vazia
    if (vazia_lista(alunos)) {
        return 0; // Retorna 0 para indicar que a remoÁ„o n„o foi realizada (lista vazia)
    } else {
        // Busca a posiÁ„o do aluno com a matrÌcula fornecida
        int posicao = busca_sequencial(alunos, matricula);
 
        if (posicao == -1) {
            return 0; // Retorna 0 para indicar que a remoÁ„o n„o foi realizada (aluno n„o encontrado)
        } else {
            // Desloca os elementos seguintes para preencher o espaÁo do aluno a ser removido
            for (i = posicao; i < alunos->nElem - 1; i++) {
                alunos->A[i] = alunos->A[i + 1];
            }
         
            alunos->nElem--; // Atualiza o n˙mero de elementos na lista
            return 1; // Retorna 1 para indicar que a remoÁ„o foi realizada com sucesso
        }
    }
}
void alterar_cadastro(Lista *alunos, int matricula)
{
    /* Altera o cadastro de um aluno da lista pelo n˙mero da matrÌcula */
    int posicao = busca_sequencial(alunos, matricula);

    if (posicao == -1)
    {
        printf("Aluno n„o encontrado\n");
        return;
    }

    // Obtem um ponteiro para o aluno encontrado na lista
    Aluno *aluno = &alunos->A[posicao];

    int opcao, opNotas;
    printf("1 - Alterar nome\n");
    printf("2 - Alterar nota\n");
    printf("3 - Alterar matrÌcula\n");
    printf("4 - Sair\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
        case 1:
            printf("Digite o novo nome: ");
            scanf("%s", aluno->nome);
            break;
        case 2:
            printf("\nQual nota vocÍ deseja alterar?\n");
            printf("1 - Primeira nota\n");
            printf("2 - Segunda nota\n");
            printf("3 - Terceira nota\n");
            scanf("%d", &opNotas);

            switch (opNotas)
            {
                case 1:
                    printf("Digite a nova nota: ");
                    scanf("%f", &aluno->nota1);
                    break;
                case 2:
                    printf("Digite a nova nota: ");
                    scanf("%f", &aluno->nota2);
                    break;
                case 3:
                    printf("Digite a nova nota: ");
                    scanf("%f", &aluno->nota3);
                    break;
                default:
                    printf("OpÁ„o inv·lida\n");
                    break;
            }
            break;
        case 3:
            printf("Digite a nova matrÌcula: ");
            scanf("%d", &aluno->matricula);
            break;
        case 4:
            break;
        default:
            printf("OpÁ„o inv·lida\n");
            break;
    }

    // Exibe os dados do aluno apos a alteraÁ„o
    exibir_dados_aluno(*aluno);
}
int buscar_dados_aluno(Lista *alunos, int matricula)
{
    // Verifica se a lista est· vazia
    if (vazia_lista(alunos))
    {
        printf("\nN„o h· alunos cadastrados.\n");
        return 0;
    }
    
    int i;
    
    // Percorre a lista de alunos
    for (i = 0; i < alunos->nElem; i++)
    {
        // Verifica se a matrÌcula do aluno È igual ‡ matrÌcula buscada
        if (alunos->A[i].matricula == matricula)
        {
            // Exibe os dados do aluno encontrado
            exibir_dados_aluno(alunos->A[i]);
            return i; // Retorna o Ìndice do aluno encontrado na lista
        }
    }
    
    printf("\nAluno n„o encontrado.\n");
    return -1; // Retorna -1 se o aluno n„o for encontrado na lista
}

void encontrar_aluno_com_maior_nota_da_primeira_prova(Lista *alunos) {
    // Verifica se a lista est· vazia
    if (vazia_lista(alunos)) {
        printf("\nN„o h· alunos cadastrados.\n");
        return;
    }
    
    float maior = 0.0;
    int i, indice_maiorN1 = -1;
    
    // Percorre a lista de alunos buscando o aluno com a maior nota da primeira prova (nota1)
    for (i = 0; i < alunos->nElem; i++) {
        if (alunos->A[i].nota1 > maior) {
            maior = alunos->A[i].nota1;
            indice_maiorN1 = i; // Armazena o Ìndice do aluno com a maior nota da primeira prova
        }
    }
    
    // Verifica se encontrou algum aluno com a nota da primeira prova
    if (indice_maiorN1 == -1) {
        printf("\nNenhum aluno encontrado.\n");
        return;
    }
    
    printf("\nAluno com maior nota na primeira prova: ");
    exibir_dados_aluno(alunos->A[indice_maiorN1]); // Exibe os dados do aluno com a maior nota da primeira prova
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

void encontrar_aluno_com_menor_media_geral(Lista *alunos) {
    // Verifica se a lista est· vazia
    if (vazia_lista(alunos)) {
        printf("\nN„o h· alunos cadastrados.\n");
        return;
    }
    
    // Inicializa a vari·vel menor com a mÈdia do primeiro aluno da lista
    float menor = (alunos->A[0].nota1 + alunos->A[0].nota2 + alunos->A[0].nota3) / 3;
    
    int indice_aluno_menor = 0;
    
    // Percorre a lista de alunos a partir do segundo aluno
    for (int i = 1; i < alunos->nElem; i++) {
        // Calcula a mÈdia do aluno atual
        float media = (alunos->A[i].nota1 + alunos->A[i].nota2 + alunos->A[i].nota3) / 3;
        
        // Verifica se a mÈdia do aluno atual È menor do que a menor mÈdia encontrada atÈ o momento
        if (media < menor) {
            menor = media;
            indice_aluno_menor = i; // Armazena o Ìndice do aluno com a menor mÈdia geral
        }
    }
    
    printf("\nAluno com menor mÈdia geral: ");
    exibir_dados_aluno(alunos->A[indice_aluno_menor]); // Exibe os dados do aluno com a menor mÈdia geral
    printf("\n---> MÈdia geral: %.2f\n", menor);
}

void listar_alunos_aprovados_e_reprovados(Lista *alunos) {
    // Verifica se a lista est· vazia
    if (vazia_lista(alunos)) {
        printf("\nLista vazia!\n");
        return;
    }
    
    int i;
    
    printf("\nAlunos aprovados:\n");
    for (i = 0; i < alunos->nElem; i++) {
        Aluno aluno = alunos->A[i];
        float media = (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;
        
        // Verifica se a media do aluno È maior ou igual a 6
        if (media >= 6) {
            exibir_dados_aluno(aluno); // Exibe os dados do aluno aprovado
        }
    }
    
    printf("\nAlunos reprovados:\n");
    for (i = 0; i < alunos->nElem; i++) {
        Aluno aluno = alunos->A[i];
        float media = (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;
        
        // Verifica se a media do aluno È menor do que 6
        if (media < 6) {
            exibir_dados_aluno(aluno); // Exibe os dados do aluno reprovado
        }
    }
}


// VERIFICA SE ESTA ORDENADO OU NAO
int verificar_se_lista_esta_ordenada(Lista *alunos) {
    if (alunos->nElem <= 1) {
        // Se a lista estiver vazia ou tiver apenas um elemento, ela est· sempre ordenada
        return 1;
    }
    
    int i;
    for (i = 1; i < alunos->nElem; i++) {
        // Compara a matrÌcula do aluno atual com a matrÌcula do aluno anterior
        if (alunos->A[i].matricula < alunos->A[i - 1].matricula) {
            return 0; // A lista n„o est· ordenada
        }
    }
    
    return 1; // A lista est· ordenada
}

void fazer_copia_lista_l1_em_lista_l2(Lista *alunos, Lista *alunos2) {
    // Verifica se a lista original est· vazia
    if (vazia_lista(alunos)) {
        printf("\nA lista original est· vazia.\n");
        return;
    }

    // Verifica se a lista destino j· possui elementos
    if (!vazia_lista(alunos2)) {
        printf("\nA lista destino n„o est· vazia.\n");
        return;
    }

    // Copia os elementos da lista original para a lista destino
    int i;
    for (i = 0; i < alunos->nElem; i++) {
        alunos2->A[i] = alunos->A[i];
        alunos2->nElem++;
    }

    printf("\nCÛpia realizada com sucesso.\n");
}

    
void inverter_lista_l1_colocando_resultado_em_lista_l2(Lista *alunos, Lista *alunos2) {
    if(vazia_lista(alunos)) {
        printf("\nLista vazia");
        return;
    }

    alunos2->nElem = 0; // Zera a lista 2
    // Percorre a lista 1 de tr·s para frente
        for(int i = alunos->nElem - 1; i >= 0; i--) {
            // Insere o aluno na lista 2
            inserir_aluno_fim_lista(alunos2, alunos->A[i]);
        }

        printf("\nLista invertida com sucesso!\n");

        // Exibe a lista invertida
        printf("\nLista invertida: ");
        for(int i = 0; i < alunos2->nElem; i++) {
            exibir_dados_aluno(alunos2->A[i]);
        }
    }

void intercalar_duas_listas_l1_e_l2_gerando_lista_l3(Lista *alunos, Lista *alunos2, Lista *alunos3) {
    /*
     intercalar os elementos de alunos e alunos2 em ordem crescente de matrÌcula gerando uma nova lista alunos3.
     */
    int i = 0, j = 0, k = 0;

    // Verifica se as listas n„o s„o vazias
    if (alunos->nElem == 0 && alunos2->nElem == 0) {
        alunos3->nElem = 0;
        return;
    }

    // Verifica se a lista alunos È vazia
    if (alunos->nElem == 0) {
        for (j = 0; j < alunos2->nElem; j++) {
            alunos3->A[j] = alunos2->A[j];
        }
        alunos3->nElem = j;
        return;
    }

    // Verifica se a lista alunos2 È vazia
    if (alunos2->nElem == 0) {
        for (i = 0; i < alunos->nElem; i++) {
            alunos3->A[i] = alunos->A[i];
        }
        alunos3->nElem = i;
        return;
    }

    // Intercala as listas
    while (i < alunos->nElem && j < alunos2->nElem) {
        if (alunos->A[i].matricula < alunos2->A[j].matricula) {
            alunos3->A[k] = alunos->A[i];
            i++;
        } else if (alunos2->A[j].matricula < alunos->A[i].matricula) {
            alunos3->A[k] = alunos2->A[j];
            j++;
        } else { // Se as matrÌculas forem iguais, adiciona o aluno de uma lista e incrementa ambas as listas
            alunos3->A[k] = alunos->A[i];
            i++;
            j++;
        }
        k++;
    }

    // Adiciona os elementos restantes da lista alunos
    while (i < alunos->nElem) {
        alunos3->A[k] = alunos->A[i];
        i++;
        k++;
    }

    // Adiciona os elementos restantes da lista alunos2
    while (j < alunos2->nElem) {
        alunos3->A[k] = alunos2->A[j];
        j++;
        k++;
    }

    // Atualiza o n˙mero de elementos em alunos3
    alunos3->nElem = k;
    
     printf("\nLista 3:\n");
        for (i = 0; i < alunos3->nElem; i++) {
        exibir_dados_aluno(alunos3->A[i]);
}
}


// busca sequencial
int busca_sequencial(Lista *alunos, int matricula)
{
  int i;
  for (i = 0; i < alunos->nElem; i++)
  {
    if (alunos->A[i].matricula == matricula)
      return i; // Retorna a posiÁ„o do aluno na lista caso a matrÌcula seja encontrada
  }
  return -1; // Retorna -1 caso a matrÌcula n„o seja encontrada na lista
}

void atualizar_arquivo(Lista *alunos) {
  // Abre o arquivo para leitura e escrita
  FILE *  fp= fopen("/Users/gabriellycristine/Documents/Xcode_estrutura/EstruturaDeDadosTrabalho/alunos.txt","r+");
  if (fp == NULL) {
    printf("Erro na abertura do arquivo");
    return;
  }
  
  int i;
  for (i = 0; i < alunos->nElem; i++) {
    // Grava as informações do aluno no arquivo no formato: matricula;nome;nota1;nota2;nota3
    fprintf(fp, "%d;%s;%f;%f;%f\n", alunos->A[i].matricula, alunos->A[i].nome, alunos->A[i].nota1, alunos->A[i].nota2, alunos->A[i].nota3);
  }
  
  // Fecha o arquivo
  fclose(fp);
}


// FUNCAO PARA EXIBIR TODOS OS ALUNOS DA LISTA
int exibir_todos_alunos(Lista *alunos, Aluno aluno)
{
    int i;
        
    // VERIFICA SE O TAMANHO DA LISTA EH IGUAL A ZERO, SE ISSO ACONTECER A LISTA ESTA  VAZIA

    if(vazia_lista(alunos)) {
        printf("\n LISTA VAZIA \n");
        return 0;
    }
    // EXIBIR NA TELA AS INFORMACOES DOS ALUNOS CADASTRADOS

    else {
        printf("\n ================================== \n");
        printf("\n INFORMACOES SOBRE OS ALUNOS \n");
        printf("\n ================================== \n");
        for(i = 0; i < alunos->nElem; i++) { //percorre a lista para exibir as informacoes
          
           printf("\nMatricula: %d\n", alunos->A[i].matricula);
            printf("Nome: %s\n", alunos->A[i].nome);
            printf("Notas: P1: %.2f P2: %.2f P3: %.2f\n", alunos->A[i].nota1, alunos->A[i].nota2, alunos->A[i].nota3);
            printf("Media: %.2f\n\n", alunos->A[i].media);
        }

    }
    return 1;
}

// exibir os dados de algum aluno
void exibir_dados_aluno(Aluno aluno){
  printf("\n----------------------------------------------------\n");
  printf("\nMatricula: %d", aluno.matricula);
  printf("\nNome: %s", aluno.nome);
  printf("\nNotas: P1: %.2f P2: %.2f P:3 %.2f\n", aluno.nota1, aluno.nota2, aluno.nota3);
  printf("\nMedia: %.2f", aluno.media);
  printf("\n----------------------------------------------------\n");
}





