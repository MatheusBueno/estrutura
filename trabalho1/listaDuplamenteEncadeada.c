// Exemplo de uma Lista Duplamente Encadeada

#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

int main(){
	Node* list;
	list = start();

	list = insert(list, 2);
	list = insert(list, 4);
	list = insertEndList(list, 1);
	list = insert(list, 5);
	list = insert(list, 6);
	list = insert(list, 7);
	list = insertOrderList(list, 3);

	// printf("\nA lista esta vazia : %d\n", isEmptyList(list));
	
	printf("\nInserindo na ultima posicao\n");
	list = insertEndList(list, 5);

	printf("\nImpressao normal:\n");
	printList(list);
	if((search(list, 3)) != NULL){
		printf("\nBuscando pelo no de valor 3. Valor encontrado: %d\n", (search(list, 3))->value);
	}
	if((search(list, 9)) != NULL){
		printf("\nBuscando pelo no de valor 9. Valor encontrado: %d\n", (search(list, 9))->value);
	}
	printf("\n\nRemovendo o elemento 3:\n");
	list = removeList(list, 3);
	printf("\n\nImpressao recursiva:\n");
	printRecursive(list);
	printf("\n\nImpressao recursiva invertida:\n");
	printRecursiveInverted(list);
	printf("\n");
	printf("\n\nEncontrando o maior elemento: %d", searchBigger(list));
	printf("\n\nEncontrando o menor elemento: %d", searchSmaller(list));

	printf("\n\nRemovendo o ultimo elemento\n");
	list = removeLastList(list);

	printf("\n\nRemovendo o primeiro elemento \n");
	list = removeFisrtList(list);

	printf("\n\nLiberando a Lista.\n");
	freeList(list);
	return 0;
}