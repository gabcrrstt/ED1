//Sobre matrizes, exemplos diversos
#include <stdio.h>

#define N 3

int main() {
	int i, j;
	int M[][N] = {1,2,3,4,5,6,7,8,9};
	int prod, soma;
	// Exibir elementos da diagonal principal
	
	printf("Elementos da diagonal principal: ");
	prod = 1;
	soma = 0;
	for(i=0; i<N; i++){
		printf("%d ",M[i][i]);
		prod = prod*M[i][i];
		soma = soma + M[i][i];
	}

	// Exibir elementos da diagonal principal
	printf("\nElementos da diagonal secundaria: ");
	for(i=0; i<N; i++)
		printf("%d ", M[i][N-1-i]);
		
	// Adicionar 1 na última coluna
	for(i=0; i<N; i++, M[i][N-1]++);
		//M[i][N-1] = M[i][N-1] + 1;
		//M[i][N-1]++;
		
	
		
	return 0;
}

