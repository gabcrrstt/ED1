#include <stdlib.h>
#include <stdio.h>

/*
1- Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e exiba o
maior endereço
*/
main()
{
  int a = 10, b = 30;
  if (&a > &b)
  {
    printf("O endereco a: %x e maior que b:%x", &a, &b);
  }
  else
  {
    printf("O endereco b: %x e maior que a: %x", &b, &a);
  }
}