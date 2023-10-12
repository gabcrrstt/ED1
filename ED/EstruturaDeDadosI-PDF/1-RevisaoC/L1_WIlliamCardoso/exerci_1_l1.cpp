#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EURO  0.1863 // essa linha afirma que 1 EURO ESTÁ CUSTANDO 0.18 REAIS(CENTAVOS REAIS)
#define USD   0.197 // 1 DOLAR ESTÁ CUSTANDO 0.19 REAIS
/*
Faça um programa de conversor de moedas: real-euro; euro-real; real-dólar; dólar-real.
(olhar em https://www.bcb.gov.br/conversao para ver a cotação do dia, quando for
fazer a atividade).
*/

float conversor(float valor, float cotacao){
    return valor * cotacao;
}

float conversor_inverso(float valor, float cotacao){
    return valor / cotacao;
}

float conversorPorFlag(float valor, int flag, char moeda1[10], char moeda2[10]){ 
  switch (flag)
  {
  case 1:
    // real-euro
    strcpy(moeda1, "Real(is)");
    strcpy(moeda2, "Euro");
    return conversor(valor, EURO);
    break;
  case 2:
    // euro-real
    strcpy(moeda1, "Euro");
    strcpy(moeda2, "Real(is)");
    return conversor_inverso(valor, EURO);
    break;
  case 3:
    // real-dolar
    strcpy(moeda1, "Real(is)");
    strcpy(moeda2, "Dolar");
    return conversor(valor, USD);
    break;
  case 4:
    // dolar-real
    strcpy(moeda1, "Dolar");
    strcpy(moeda2, "Real(is)");
    return conversor_inverso(valor, USD);
    break;
  
  default:
  return 0;
    break;
  }
}



int main() {
  int opcao;
  float valor, convertido;
  char moeda1[10] = "";
  char moeda2[10] = "";
  while (1){
    printf("\n 1- Real-Euro\n 2- Euro-Real\n 3- Real-Dolar\n 4- Dolar-Real\n 5- Sair\n");
    printf("\n Digite a opcao: ");
    scanf("%d", &opcao);
    if(opcao == 5){
      break;
    } else {
      printf("\n Digite o valor a ser convertido: ");
      scanf("%f", &valor);
      convertido = conversorPorFlag(valor, opcao, moeda1, moeda2);
      printf("\n %.2f  %s convertido para cotacao %s e %.2f", valor, moeda1 , moeda2, convertido);
    }
  }
  return 0;
}