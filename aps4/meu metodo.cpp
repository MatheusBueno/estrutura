#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Meu metodo de busca
// Utiliza um numero random para pesquisar no vetor ordenado
int randSearch(int x, int v[], int min, int max) {
	// Gera o numero aleatorio
	// Numero entre 0 e o length do vetor
	int randon = min + ( rand() %(max-min));
	// Cada chamada do metodo
	printf("min:%d  max:%d  randon:%d, value:%d\n",min,max,randon, v[randon]);
	// Caso o numero seja o valor buscado retonar o mesmo
	if(v[randon] == x)return randon;
	// Caso o numeor pesquisado seja maior que o esperado delimitar o primixo vetor de busca
	// O novo vetor sera de 0 ate o valor do randon
	else if(x < v[randon])randSearch(x, v, min, randon);
	// Caso o numero pesquisado seja menor que q o esperado delimita o proximo vetor de busca
	// O novo vetor sera do randon mais 1 (Para um maior aproveitamento) ate o length do vetor
	else randSearch(x, v , randon+1, max);
}

int main () {
	
	int v[25];
	
	for(int i =0; i <= 25; i++) {
		v[i] = i;
	}
	
	srand( (unsigned)time(NULL) );
	printf("A posicao e a : %d",randSearch(3,v, 0, 25));
	
}
