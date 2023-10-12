#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que some os números ímpares contidos em um intervalo definido 
pelo usuário. O usuário define o valor inicial do intervalo e o valor final deste intervalo
e o programa deve somar todos os números ímpares contidos neste intervalo. Caso o 
usuário digite um intervalo inválido (começando por um valor maior que o valor final) 
deve ser escrito uma mensagem de erro na tela, “Intervalo de valores inválido” e o 
programa termina. Exemplo de tela de saída: 
Digite o valor inicial e valor final: 5 
10 
Soma dos ímpares neste intervalo: 21.
*/

void calcularIntervalo(int valor1, int valor2) {
  if(valor1 > valor2) {
    printf("intervalor invalido");
  } else  for(int i = valor2; i >=valor1; i--) if(i % 2) printf(" %d ", i );

}

main() {
  int valor1, valor2;
  printf("Digite o valor inicial e valor final: ");
  scanf("%d %d", &valor1, &valor2);
  calcularIntervalo(valor1, valor2);
}