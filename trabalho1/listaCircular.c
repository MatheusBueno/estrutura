// Lista circular

#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

int main(){
	printf("Iniciando a cabeça com NULL.\n");
	Node * head = NULL;
	printf("A lista está vazia (0,1) : %d\n", isEmptyList(head));
	printf("Inserindo elementos.\n");
	head = insert(head, 10);
	head = insert(head, 25);
	head = insert(head, 21);
	head = insert(head, 76);
	head = insert(head, 23);
	head = insert(head, 2);
	printf("Imprimindo a lista:\n");
	printList(head);

	printf("\nMedia dos valores : %d",average(head));

	head = removeElement(head,76);

	printf("\nImprimindo a lista apos remocao:\n");
	printList(head);
	
	printf("Imprimindo a lista 20 vezes:\n");
	printListLoop(head, 20);
	printf("Removendo elemento do fim.\n");
	head = removeList(head);
	printf("Removendo elemento do início.\n");
	head = removeStartList(head);

	printf("\nImprimindo a lista apos remocao:\n");
	printList(head);
	return 0;
}