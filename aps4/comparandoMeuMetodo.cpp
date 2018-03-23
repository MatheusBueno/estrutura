#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int r = 0;
int b = 0;
int s = 0;

/**
  * Exemplos de Buscas em Vetores Ordenados
  * Diogo Cezar <diogo@diogocezar.com>
  */

/**
  * Uma busca sequencial, nada performática!
  */
int sequentialSearch(int x, int n, int v[]){
    int j;
    for(j = 0; j<n ; j++){
		s+= 1;
	}
    return j;
}

/**
  * Uma busca binária, bem mais performática!
  */
int binarySearch(int x, int n, int v[]){
    int e = -1;
    int d = n;
    while(e < d-1){
    	b++;
        int m = (e + d)/2;
        if(v[m] < x)
            e = m;
        else
            d = m;
    }
    return d;
}

/**
  * Uma busca binária, recursiva!
  */
int recursiveBinarySearch(int x, int e, int d, int v[]){
    if(e == d-1) return d;
    else{
        int m = (e + d)/2;
        if(v[m] < x)
            return recursiveBinarySearch(x, m, d, v);
        else
            return recursiveBinarySearch(x, e, m, v);
    }
}


// Meu metodo de busca
// Utiliza um numero random para pesquisar no vetor ordenado
int randSearch(int x, int v[], int min, int max) {
	// Soma qunatas vezes a funcao foi chamada para comparacao com os outro metodos
	r++;
	// Gera o numero aleatorio
	// Numero entre 0 e o length do vetor
	int randon = min + ( rand() %(max-min));
	// Caso o numero seja o valor buscado retonar o mesmo
	if(v[randon] == x)return randon;
	// Caso o numeor pesquisado seja maior que o esperado delimitar o primixo vetor de busca
	// O novo vetor sera de 0 ate o valor do randon
	else if(x < v[randon])randSearch(x, v, min, randon);
	// Caso o numero pesquisado seja menor que q o esperado delimita o proximo vetor de busca
	// O novo vetor sera do randon mais 1 (Para um maior aproveitamento) ate o length do vetor
	else randSearch(x, v , randon+1, max);
}

int main(){
	int a =0;
	int t =0;
	int v[25];
	
	for(int i =0; i <= 25; i++) {
		v[i] = i;
	}
	
	srand( (unsigned)time(NULL) );
	do {
    t = sequentialSearch(2, 25, v);
    t = binarySearch(2, 25, v);
    t = randSearch(2,v, 0, 25);
    
    // Cada rounde serve para ter varias comparacoes entre os metodos
    // Somando se os resultados e no final tendo qual metodo foi o melhor aproveitado
    printf("--Round %d-- \n\nsequencial foi chamado: %d  vezes\nbinario foi chamado : %d vezes\nMeu metodo foi chamado: %d vezes\n\n",a , s, b ,r);
     a++;
	} while(a <= 10);
    
}
