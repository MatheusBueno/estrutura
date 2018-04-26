// TAD para lista circular
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* next;
} Node;

int isEmptyList(Node * head){
	return (head == NULL);
}

// Insert in the end
Node * insert(Node* head, int value){
	Node *novo = (Node*) malloc (sizeof(Node));
	novo->value = value;
	if(isEmptyList(head)){
		head = novo;
		novo->next  = head;
		head->next = novo;
	}
	else{
		novo->next = head->next;
		head->next = novo;
	}
	return head;
}

Node* inserirOrdenado(Node *head, int value) {
	Node *novo = (Node*) malloc (sizeof(Node));
	Node *p = head->next;
	novo->value = value;
	if(isEmptyList(head)){
		head = novo;
		novo->next  = head;
		head->next = novo;
	}
	else{
		while(p ->next != head || p->value > novo->value) p = p->next;

		novo->next = p->next;
		p->next = novo;
	}
	return head;
}

Node * removeList(Node* head){
	Node * p = head->next;
	Node * nextNode = head->next;
	if(head == NULL){
		return NULL;
	}
	else{
		while(p->next != head){
			p = p->next;
		}
		p->next = nextNode;
		free(head);
	}
	return nextNode;
}

Node * removeStartList(Node* head){
	Node * p = head->next;
	Node * nextNode = head->next;
	if(head == NULL){
		return NULL;
	}
	else{
		while(p->next != head){
			p = p->next;
		}
		p->next = nextNode;
		free(head);
	}
	return nextNode;
}

void printListLoop(Node* head, int i){
	Node * p = head;
	if(isEmptyList(head)){
		printf("Essa lista está vazia!\n");
	}
	else{
		while(i > 0){
			printf("Valor: %d\n", p->value);
			p = p->next;
			i--;
		}
	}
}

void printList(Node* head){
	Node * p;
	p = head->next;
	if(isEmptyList(p)){
		printf("Essa lista está vazia!\n");
	}
	else{
		while(p != head){
			printf("Valor: %d\n", p->value);
			p = p->next;
		}
		printf("Valor: %d\n", p->value);
	}
}

Node * search(Node * head, int value){
	Node * p;
	for(p=head->next; p != head; p=p->next){
		if(p->value == value){
			return p;
		}
	}
	if(p->value == value){
		return p;
	}
	return NULL;
}

int searchBigger(Node * head){
	int maior =0;
	Node * p;
	for(p=head->next; p != head; p=p->next){
		if(p->value > maior) maior = p->value;
	}
	if(p->next->value > maior){
		maior = p->next->value;
	}
	return maior;
}

int searchSmaller(Node * head){
	int menor =0;
	Node * p;
	for(p=head->next; p != head; p=p->next){
		if(p->value < menor) menor = p->value;
	}
	if(p->next->value < menor){
		menor = p->next->value;
	}
	return menor;
}

// Remove um elemento especifico
Node * removeElement(Node * head, int value) {
	Node * p = head->next;
	Node * nextNode = head->next;
	if(head == NULL){
		return NULL;
	}
	else{
		while(p->next != head && p->next->value != value){
			p = p->next;
		}
		if(p->next == head) {
			p->next = nextNode;
			free(p->next);
		}
		p->next = p->next->next;
		free(p->next);
	}
	return nextNode;
}


// retornar a media de todos os elementos daa lista
int average(Node* head){
	Node * p = head->next;
	int values = 0;
	int count = 0;
	if(head == NULL){
		return 0;
	}
	else{
		while(p->next != head){
			values += p->value;
			count++;
			p = p->next;
		}
		values += p->next->value;
		count++;
		values = values/count;
	}
	return values;
}