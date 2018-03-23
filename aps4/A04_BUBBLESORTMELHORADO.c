#include <stdio.h>

int vezes =0;

/**
  * Exemplo de Implementação do Método de Ordenação BubbleSort
  * Diogo Cezar <diogo@diogocezar.com>
  */


 /* 
  Verifica se o vetor ja esta ordenado
  Caso esteja retornara 1
  Se nao estiver ordenado retornara 0
  */

int verificaOrdenacao(int n, int v[]) {
	int i;
	for(i = 0; i < n; i++) 
		if( v[i] > v[i+1]) return 0;

  return 1;  
}

/**
  * Ordenação pelo método BubbleSort
  */  
void bubbleSort(int n, int v[]){
    int i, j;
    int tam = n;
    int aux;
    for(i=0; i<tam; i++){
        // Chama uma funcao que verifica se o vetor ja esta ordenado
        // Caso ja esteja ordenado finaliza a funcao
        if(verificaOrdenacao(n, v) == 1) return;
        for(j=0; j< n-1; j++){
        	// Imprime os valores que estao sendo comparados
        	printf("%d < %d  |  ", v[j], v[j+1]);
        	vezes++;
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
        printf("\n\nMaior valor: %d\n\n",v[j]);     
		// Remove 1 de n pois o ultimo elemento ja esta ordenado e nao precisa ser verificado novamente
		n--;
    printf("\nProximo valor\n\n");
    }
}

/**
  * Impressão de um vetor
  */
void printVet(int n, int v[]){
    int j;
    for(j = 0; j<n ; j++){
        printf("[%d] ", v[j]);
    }
    printf("\n\n");
}

/**
  * Função Principal
  */
int main(){
    int v[7] = {24,1,11,514,16,20,33};
    printf("Vetor original:\n");
    printVet(7, v);
    bubbleSort(7, v);
    printf("\n\nVetor ordenado:\n");
    printVet(7, v);
    printf("\n\nQuantidade de vezes : %d", vezes);
}
