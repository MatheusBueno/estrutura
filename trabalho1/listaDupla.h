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
	Node *novo = (Node*) malloc (sizeof(Node));
	novo->value = value;
	novo->next  = list;
	novo->prev  = NULL;
	if(list != NULL){
		list->prev = novo;
	}
	return novo;
}

Node * insertEndList(Node* list, int value){
	Node *novo = (Node*) malloc (sizeof(Node));
	Node *p = list;
	if(isEmptyList(list)){
		printf("vali");
		novo->next = NULL;
		novo->prev = NULL;
		novo->value = value;
		return novo;
	}
	while(p->next != NULL){
		p = p->next;
	}

	novo->value = value;
	novo->next  = NULL;
	novo->prev  = p;
	p->next = novo;
	return list;
}

Node * insertOrderList(Node* list, int value){
	Node *novo = (Node*) malloc (sizeof(Node));
	Node *p = list;
	novo->value = value;
	if(isEmptyList(list)){
		novo->next = NULL;
		novo->prev = NULL;
		novo->value = value;
		return novo;
	}

	while(p->next != NULL || p->value > novo->value){
		p = p->next;
	}

	if(p->prev == NULL){
	// printf(" primeiro eleento");
	list->prev = novo;
	novo->next = list;
	novo->prev = NULL;

	}
	else if(p->next == NULL){// ultimo
	// printf(" ultimo eleento");
	p->next = novo;
	novo->next = NULL;
	novo->prev = p;
	}
	else{
		// printf(" meio eleento");
		p->prev->next = novo;
		novo->next = p;
		p->prev = novo;
		novo->prev = p->prev;
	}
	p->next = novo;
	novo->prev = p;
	novo->next = NULL;
	
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