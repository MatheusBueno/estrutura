// Lista circular

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* next;
} Node;

int isEmptyList(Node * head){
	return (head == NULL);
}

Node * insert(Node* head, int value){
	Node *new = (Node*) malloc (sizeof(Node));
	new->value = value;
	if(isEmptyList(head)){
		head = new;
		new->next  = head;
		head->next = new;
	}
	else{
		new->next = head->next;
		head->next = new;
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

int main(){
	printf("Iniciando a cabeça com NULL.\n");
	Node * head = NULL;
	Node * searched = NULL;
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

	printf("Media dos valores : %d",average(head));

	head = removeElement(head,76);

	printf("\nImprimindo a lista apos remocao:\n");
	printList(head);

	return 0;
}