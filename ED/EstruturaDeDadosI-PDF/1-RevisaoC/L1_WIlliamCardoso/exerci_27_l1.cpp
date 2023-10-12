#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
. O código de César é uma das mais simples e conhecidas técnicas de criptografia. É um
tipo de substituição na qual cada letra do texto é substituída por outra, que se apresenta
no alfabeto abaixo dela um número fixo de vezes. Por exemplo, com uma troca de três
posições, ‘A’ seria substituído por ‘D’, ‘B’ se tornaria ‘E’, e assim por diante. Implemente
um programa que faça uso desse Código de César (3 posições), entre com uma string e
*/
void converterMaiusculo(char s[100])
{
  int j = 0;
  while(s[j] != '\0')
  {
    s[j] = toupper(s[j]);
    j++;
  }
}

void criptografar(char palavra[100])
{
  int j = 0;
  char palavraCrip[100];
  while(palavra[j] != '\0') {
    if(palavra[j] < 88){
      palavraCrip[j] = palavra[j] + 5;
    }
    if(palavra[j] > 88){
      palavraCrip[j] = palavra[j] - 26 +  3;
    }
    if(palavra[j] == ' '){
      palavraCrip[j] = ' ';
    }
    j++;
  }
  printf("\ncriptografado: %s", palavraCrip);
}

main()
{
  char palavraParaCriptografar[100];
  printf("\nDigite uma palavra para ser criptografada: ");
  gets(palavraParaCriptografar);
  converterMaiusculo(palavraParaCriptografar);
  printf("\nVoce digitou: %s", palavraParaCriptografar);
  criptografar(palavraParaCriptografar);
}