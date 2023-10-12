#include <stdlib.h>
#include <stdio.h>

typedef struct  {
  int matricula;
  char sobrenome[50];
  char anoNascimento[15];
}aluno;

/*
7- Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
 Deverão ser armazenados, para cada aluno: matrícula, sobrenome (apenas um) e ano do
nascimento.
 Ao início do programa, o usuário deverá informar o número de alunos que serão
armazenados.
 O programa deverá alocar dinamicamente a quantidade necessária de memória para
armazenar os registros dos alunos.
 O programa deverá pedir ao usuário que entre com as informações dos alunos.
 Ao final, mostrar os dados armazenados e liberar a memória alocada.
*/

main() {
  int nAlunos;
   aluno *alunos;

  printf("Digite o numero de alunos: ");
  scanf("%d", &nAlunos);

  alunos = ( aluno *) malloc(nAlunos * sizeof(aluno));

  for (int i = 0; i < nAlunos; i++) {
    printf("Digite a matricula do aluno %d: ", i + 1);
    scanf("%d", &alunos[i].matricula);
    printf("Digite o sobrenome do aluno %d: ", i + 1);
    scanf("%s", alunos[i].sobrenome);
    printf("Digite o ano de nascimento do aluno %d: ", i + 1);
    scanf("%s", alunos[i].anoNascimento);
  }

  for (int i = 0; i < nAlunos; i++) {
    printf("\nAluno %d: ", i + 1);
    printf("Matricula: %d\n", alunos[i].matricula);
    printf("Sobrenome: %s\n", alunos[i].sobrenome);
    printf("Ano de nascimento: %s\n", alunos[i].anoNascimento);
  }

  free(alunos);
}