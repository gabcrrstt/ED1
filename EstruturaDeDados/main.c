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



#include <string.h>

#include <stdlib.h>

#include <stdio.h>

#include "lista.h"





int main(){

    int op=0, matricula, res, ord;

    Lista L1;

    Lista L2;

    Lista L3;

    Aluno v;

    inicializa_lista(&L1);

    inicializa_lista(&L2);

    inicializa_lista(&L3);


    while (op != 15){

      printf("\n");

      printf("1-Inserir aluno\n");

      printf("2-Remover aluno\n");

      printf("3-Alterar cadastro do aluno\n");

      printf("4-Excluir lista\n");

      printf("5-Buscar Aluno\n");

      printf("6-Exibir todos os dados de todos os alunos\n");

      printf("7-Aluno com maior nota na primeira prova\n");

      printf("8-Aluno com maior media geral\n");

      printf("9-Aluno com menor media geral\n");

      printf("10-Listar os alunos aprovados e reprovados\n");

      printf("11-Verificar ordenacao da lista.\n");

      printf("12-Fazer uma copia da lista L1 em uma outra lista L2;\n");

      printf("13-Inverter uma lista L1 colocando o resultado em L2;\n");

      printf("14-Intercalar duas listas, L1 e L2, gerando uma lista L3. Considere que L1, L2 e L3 est�o ordenadas;\n");

      printf("15-Sair\n");

      printf("Digite a opcao\n");

      scanf("%d",&op);

      switch(op){

        case 1:

          v = criar_novo_aluno();

          res = inserir_aluno(&L1,v);

          if(res) {

            printf("\nAluno inserido com sucesso!\n\n");

          }



        break;



        case 2:

          printf("Digite a matricula do aluno que deseja remover\n");

          scanf("%d",&matricula);

          if(remover_aluno(&L1,matricula)) {

            printf("\nAluno removido com sucesso!\n");

          }

        break;



        case 3:

          printf("Digite a matricula do aluno que deseja alterar\n");

          scanf("%d",&matricula);

          alterar_cadastro(&L1,matricula);

        break;



        case 4:

         // excluir_lista(&L1);

        break;



        case 5:

          printf("Digite a matricula do aluno que deseja buscar\n");

          scanf("%d",&matricula);

          buscar_dados_aluno(&L1,matricula);

        break;



        case 6:

          exibir_todos_alunos(&L1,v);

        break;



        case 7:

          encontrar_aluno_com_maior_nota_da_primeira_prova(&L1);

        break;



        case 8:

          encontrar_aluno_com_maior_media_geral(&L1);

        break;



        case 9:

          encontrar_aluno_com_menor_media_geral(&L1);

        break;



        case 10:

          listar_alunos_aprovados_e_reprovados(&L1);

          break;



        case 11:

          ord = verificar_se_lista_esta_ordenada(&L1);

          if(ord) {

            printf("\nLista esta ordenada!\n");

          }

          else {

            printf("\nLista nao esta ordenada!\n");

          }

          break;

         case 12:

          fazer_copia_lista_l1_em_lista_l2(&L1,&L2);

          printf("\nLista L2:\n");

          exibir_todos_alunos(&L2,v);

          break;

        case 13:

          inverter_lista_l1_colocando_resultado_em_lista_l2(&L1,&L2);

          break;

         case 14:

          intercalar_duas_listas_l1_e_l2_gerando_lista_l3(&L1,&L2, &L3);

          break;

        default:

        break;

      }

  }

      return 0;



}





