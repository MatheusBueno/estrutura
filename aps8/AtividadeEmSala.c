/**
* Professor Diogo Cezar Teixeira Batista
* <diogo@diogocezar.com>
* <diogoc@utfpr.edu.br>
* Exemplo de uma Lista Duplamente Encadeada
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* next;
	struct Node* prev;
} Node;

Node* start(){
	return NULL;
}

Node * insert(Node* list, int value){
	Node *new = (Node*) malloc (sizeof(Node));
	new->value = value;
	new->next  = list;
	new->prev  = NULL;
	if(list != NULL){
		list->prev = new;
	}
	return new;
}

Node * insertEndList(Node* list, int value){
	Node *new = (Node*) malloc (sizeof(Node));
	Node *p = list;
	if(isEmptyList(list)){
		printf("vali");
		new->next = NULL;
		new->prev = NULL;
		new->value = value;
		return new;
	}
	while(p->next != NULL){
		p = p->next;
	}

	new->value = value;
	new->next  = NULL;
	new->prev  = p;
	p->next = new;
	return list;
}

Node * insertOrderList(Node* list, int value){
	Node *new = (Node*) malloc (sizeof(Node));
	Node *p = list;
	new->value = value;
	if(isEmptyList(list)){
		new->next = NULL;
		new->prev = NULL;
		new->value = value;
		return new;
	}

	while(p->next != NULL || p->value > new->value){
		p = p->next;
	}

	if(p->prev == NULL){
	// printf(" primeiro eleento");
	list->prev = new;
	new->next = list;
	new->prev = NULL;

	}
	else if(p->next == NULL){// ultimo
	// printf(" ultimo eleento");
	p->next = new;
	new->next = NULL;
	new->prev = p;
	}
	else{
		// printf(" meio eleento");
		p->prev->next = new;
		new->next = p;
		p->prev = new;
		new->prev = p->prev;
	}
	p->next = new;
	new->prev = p;
	new->next = NULL;
	
	return list;
}

int isEmptyList(Node * list){
	return (list == NULL);
}

void printList(Node * list){
	Node * p = list;
	if(isEmptyList(p)){
		printf("Essa lista está vazia!\n");
	}
	else{
		while(p != NULL){
			printf("\nValor: %d", p->value);
			p = p->next;
		}
	}
}

Node * search(Node * list, int value){
	Node * p;
	for(p=list; p!=NULL; p=p->next){
		if(p->value == value){
			return p;
		}
	}
	return NULL;
}

int searchSmaller(Node * list) {
  if( list->next == NULL) {
    return list->value;
  }
  int smaller = list->value;
	Node * p;
	for(p=list; p!=NULL; p=p->next){
		if(p->value < smaller){
      smaller = p->value;
		}
	}
	return smaller;
}

int searchBigger(Node * list) {
  if( list->next == NULL) {
    return list->value;
  }
  int bigger = list->value;
	Node * p;
	for(p=list; p!=NULL; p=p->next){
		if(p->value > bigger){
      bigger = p->value;
		}
	}
	return bigger;
}

void freeList(Node * list){
	Node * p = list;
	while(p != NULL){
		printf("Liberando o elemento: %d\n", p->value);
		Node * temp = p->next;
		free(p);
		p = temp;
	}
}

Node * removeList(Node * list, int value){
	Node * p = search(list, value);
	if(p==NULL)
		return list;
	if(list == p){
		list = p->next;
	}
	else{
		p->prev->next = p->next;
	}
	if(p->next != NULL){
		p->next->prev = p->prev;
	}
	free(p);
	return list;
}

Node *removeLastList(Node * list){
	Node *p = list;
	while(p->next !=NULL){
		p = p->next;
	}
	printf("Removendo %d valor",p->value);
	p->prev->next = NULL;
	
	free(p);
	return list;
}

Node * removeFisrtList(Node * list){
	Node * p = list;
	printf("Removendo %d valor",p->value);
	p = list->next;
	free(list);
	return p;
}

void printRecursive(Node * list){
	Node * p = list;
	if(!isEmptyList(p)){
		printf("\nValor: %d", p->value);
		printRecursive(p->next);
	}
}

void printRecursiveInverted(Node * list){
	Node * p = list;
	if(!isEmptyList(p)){
		printRecursiveInverted(p->next);
		printf("\nValor: %d", p->value);
	}
}

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