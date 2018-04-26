#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node * next;
} Node;

typedef struct Queue{
	Node * start;
	Node * end;
} Queue;

Queue * create(){
	Queue * q = (Queue*) malloc(sizeof(Queue));
	q->start = NULL;
	q->end = NULL;
	return q;
}

void insert(Queue * q, int value){
  // new node
	Node * new = (Node*) malloc(sizeof(Node));
	new->value = value;
	new->next = NULL;
	
	if(q->end != NULL) {
      // count
  int count = 0;
    // usage for verify if is smaller that 10
    Node * p;
    p = q->start;
    while(p != NULL){
			p = p->next;
      count++;
		}
    if( count == 10) {
      printf("\nLista ja contem os 10 valaores.");}
    else {
      q->end->next = new;
      q->end = new;
    }
	}
	else{
    q->end = new;
    q->start = new;
	}
}

int isEmptyQueue(Queue * q){
	return (q->start == NULL);
}

void printQueue(Queue * q){
	Node * p;
	p = q->start;
	if(isEmptyQueue(q)){
		printf("Essa fila esta vazia!\n");
	}
	else{
		while(p != NULL){
			printf("Valor: %d\n", p->value);
			p = p->next;
		}
	}
}

Node * search(Queue * q, int value){
	Node * p;
	for(p=q->start; p != NULL; p=p->next){
		if(p->value == value){
			return p;
		}
	}
	return NULL;
}

void freeQueue(Queue * q){
	Node * p = q->start;
	while(p != NULL){
		Node * t = p->next;
		free(p);
		p = t;
	}
	free(q);
}

int removeQueue(Queue * q){
	Node * t;
	int v;
	if(isEmptyQueue(q)){
		printf("\nFila ja vazia!\n");
		return 0;
	}
	t = q->start;
	v = t->value;
	q->start = t->next;
	if(q->start == NULL)
		q->end = NULL;
	free(t);
	return v;
}

// Function that insert the value in the start of Queue
void furaFila(Queue *q, int value) {
  Node * new = (Node*) malloc(sizeof(Node));
	new->value = value;
	new->next = NULL;
  new->next = q->start;
  q->start = new;
}

int main(){
	Queue * q;
	q = create();
	Node * searched = NULL;
	int removed;
	printf("Inserindo elementos.\n");
	insert(q, 1);
	insert(q, 2);
	insert(q, 3);
	insert(q, 4);
	insert(q, 5);
	insert(q, 6);
	insert(q, 7);
	insert(q, 8);
	insert(q, 9);
	insert(q, 10);
	insert(q, 11);
	insert(q, 12);
	printf("Imprimindo a fila.\n");
	printQueue(q);

	printf("Liberando a fila.\n");
	freeQueue(q);
	return 0;
}