#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que receba a altura e o sexo de uma pessoa e calcule e mostre seu
peso ideal, utilizando as seguintes formulas (onde h corresponde à altura):
 Homens: (72.7 ∗ h) − 58
 Mulheres: (62, 1 ∗ h) − 44, 7
*/

float pesoIdeal(float h, char sexo)
{
  if (sexo == 'M')
  {
    return (72.7 * h) - 58;
  }
  else
  {
    return (62.1 * h) - 44.7;
  }
}

int converterMaiusculo(char s) {
  int i = (int) s;
  return (i <= 90 && i >= 65) ? i + 32 : i ; 
}

main()
{
  float altura, peso;
  char sexo;
  printf("Digite sua altura: ");
  scanf("%f", &altura);
  printf("Digite seu sexo: ");
  scanf(" %c", &sexo);
  peso = pesoIdeal(altura, converterMaiusculo(sexo));
  printf("Seu peso ideal e: %.2f", peso);
}