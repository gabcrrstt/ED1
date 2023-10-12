#include <stdlib.h>
#include <stdio.h>

/*
Em Matemática, o número harmônico designado por H(n) define-se como sendo a soma 
da série harmônica:
h(n) = 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + ... + 1/n
Faça um programa que leia um valor n inteiro e positivo e apresente o valor de H(n).

*/
main() {
  int n;
  float h;
  printf("Digite um valor n inteiro e positivo: ");
  scanf("%d", &n);
  h = 0;
  for (int i = 1; i <= n; i++) {
    h += 1.0 / i;
  }
  printf("H(%d) = %.2f\n", n, h);

}