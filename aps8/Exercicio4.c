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

void change(Node *listA, Node *listB)
{	
    if(listA->prev == listB){
        listA->prev = listB->prev;
        listB->next = listA->next;
        listA->next = listB;
        listB->prev = listA;
    }
    else{
        Node *aux = listA->next;
        listA->next = listB->next;
        listB->next = aux;

        aux = listA->prev;
        listA->prev = listB->prev;
        listB->prev = aux;
        
        if(listA->next)
            listA->next->prev = listA;
        if(listB->prev)
            listB->prev->next = listB;
    }
    
    if(listA->prev)
        listA->prev->next = listA;
    if(listB->next)
        listB->next->prev = listB;
}

Node *orderList(Node *list) {
  Node *p = list;
	Node *end = list;
	Node *aux;

	for ( p; p->next != NULL; p = p->next) {
    for (end; end->next != NULL; end = end->next) {

			if( p->value > p->next->value ) {
				aux->next = p->next;
				aux->prev = p->prev;
				
				end->next = end->next->next;
				end->prev = end->next->prev;
				end->next->next = end;
				end->next->prev = end->prev;
			}

		if(p->value > p->next->value){
			p = p->next;
			if(p->prev == NULL)	list->next = p->next;
				change(p->next,p);

			} else {
				p = p->next;
				if(p->next == NULL)	end = p;
			end = end->prev;
			}
		}

	}
}

int main() {
	Node* list;
	list = start();
	list = insert(list, 2);
	list = insert(list, 4);
	list = insert(list, 1);
	list = insert(list, 5);
	list = insert(list, 6);
	printList(list);

  orderList(list);

	printList(list);
	return 0;
}