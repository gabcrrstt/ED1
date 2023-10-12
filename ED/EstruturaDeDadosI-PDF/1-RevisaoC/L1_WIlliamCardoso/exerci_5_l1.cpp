#include <stdio.h>
#include <stdlib.h>
/*
Leia a nota e o número de faltas de um aluno, e escreva seu conceito. De acordo com a 
tabela abaixo, quando o aluno tem mais de 20 faltas ocorre uma redução de conceito
*/


char conceito(float nota, int faltas){
  if(faltas <= 20) {
    if(nota >= 9.0 && nota <= 10.0) {
      return 'A';
    } else if(nota >= 7.5 && nota <= 8.9) {
      return 'B';
    } else if(nota >= 5.0 && nota <= 7.4) {
      return 'C';
    } else if(nota >= 4.0 && nota <= 4.9) {
      return 'D';
    } else if(nota >= 0.0 && nota <= 3.9) {
      return 'E';
    }
  } else {
    if(nota >= 9.0 && nota <= 10.0) {
      return 'B';
    } else if(nota >= 7.5 && nota <= 8.9) {
      return 'C';
    } else if(nota >= 5.0 && nota <= 7.4) {
      return 'D';
    } else if(nota >= 4.0 && nota <= 4.9) {
      return 'E';
    } else if(nota >= 0.0 && nota <= 3.9) {
      return 'E';
    }
  }
  
}
main() {
  int faltas;
  float nota;
  printf("Digite a nota: ");
  scanf("%f", &nota);
  printf("Digite o numero de faltas: ");
  scanf("%d", &faltas);
  printf("Conceito: %c\n", conceito(nota, faltas));
  
}