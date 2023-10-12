#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Escrever um programa que leia o código do produto escolhido do cardápio de uma 
lanchonete e a quantidade. O programa deve calcular o valor a ser pago por aquele 
lanche. Considere que a cada execução somente será calculado um pedido. O cardápio 
da lanchonete segue o padrão abaixo:
*/
float cardapio(int codigo, int quantidade, char nomeDoProduto[]) {
  switch (codigo)
  {
  case 100:
    strcpy(nomeDoProduto, "Cachorro Quente");
    return quantidade * 1.20;
    break;
  case 101:
    strcpy(nomeDoProduto, "Bauru Simples");
    return quantidade * 1.30;
    break;
  case 102:
    strcpy(nomeDoProduto, "Bauru com Ovo");
    return quantidade * 1.50;
    break;
  case 103:
    strcpy(nomeDoProduto, "Hamburguer");
    return quantidade * 1.20;
    break;
  case 104:
    strcpy(nomeDoProduto, "Cheeseburguer");
    return quantidade * 1.70;
    break;
  case 105:
    strcpy(nomeDoProduto, "Suco");
    return quantidade * 2.20;
    break;
  case 106:
    strcpy(nomeDoProduto, "Refrigerante(Lata)");
    return quantidade * 1;
    break;
  default:
    break;
  }
}
main() {
  int codigo, quantidade;
  char nomeDoProduto[20];
  float valor;
  printf("Digite o codigo do produto: ");
  scanf("%d", &codigo);
  printf("Digite a quantidade: ");
  scanf("%d", &quantidade);
  valor = cardapio(codigo, quantidade, nomeDoProduto);
  printf("O valor a ser pago por \"%s\" e: R$%.2f\n", nomeDoProduto, valor);
}