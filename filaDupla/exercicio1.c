#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node * next;
	struct Node * prev;
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

void insertEnd(Queue * q, int value){
	Node * new = (Node*) malloc(sizeof(Node));
	new->value = value;
	new->next = NULL;
	if(q->end != NULL){
		q->end->next = new;
		new->prev = q->end;
	}
	else{
		q->start = new;
		new->prev = NULL;
	}
	q->end = new;
}

void insertStart(Queue * q, int value){
	Node * new = (Node*) malloc(sizeof(Node));
	new->value = value;
	new->prev = NULL;
	if(q->end != NULL){
		q->start->prev = new;
		new->next = q->start;
	}
	else{
		q->end = new;
		new->next = NULL;
	}
	q->start = new;
}

int isEmptyQueue(Queue * q){
	return (q->start == NULL);
}

void printQueue(Queue * q){
	Node * p;
	p = q->start;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
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

int removeStartQueue(Queue * q){
	Node * t;
	int v;
	if(isEmptyQueue(q)){
		printf("\nFila já vazia!\n");
		return 0;
	}
	t = q->start;
	v = t->value;
	q->start = t->next;
	if(t->next == NULL)
		q->end = NULL;
	else
		t->next->prev = NULL;
	free(t);
	return v;
}

int removeEndQueue(Queue * q){
	Node * t;
	int v;
	if(isEmptyQueue(q)){
		printf("\nFila já vazia!\n");
		return 0;
	}
	t = q->end;
	v = t->value;
	q->end = t->prev;
	if(t->prev == NULL)
		q->start = NULL;
	else
		t->prev->next = NULL;
	free(t);
	return v;
}

// verify if is order
int isOrder(Queue *q) {
  Node * p;
	p = q->start;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
	}
	else{
		while(p->next != NULL){
      if (p->value < p->next->value) return 0;
			p = p->next;
		}
    printf("Ordenada");
	}
  return 1;
}

// encontra o valor par mais proximo do inicio da fila
void parStart(Queue *q) {
  Node * p;
	p = q->start;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
	}
	else{
		while(p != NULL){
      if (p->value % 2 == 0){ 
        printf("\n O valor par mais proximo do inicio e : %d\n",p->value);
        return;
      } else p = p->next;
		}
	}
  printf("\nValor nao encontrado !!\n");
}

void parEnd(Queue *q) {
  Node * p;
	p = q->end;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
	}
	else{
		while(p != NULL){
      if (p->value % 2 == 0){ 
        printf("\n O valor par mais proximo do final e : %d\n",p->value);
        return;
      } else p = p->prev;
		}
	}
  printf("\nValor nao encontrado !!\n");
}

void recursive(Queue *a, Queue *b) {

	if(isEmptyQueue(a) && isEmptyQueue(b)) {
		printf("\nListas vazias\n");
		return;
	}
  
  Node *n1 = a->start;
  Node *n2 = b->start;

  if(n1->value == n2->value) {

    if(n1->next == NULL && n2->next == NULL) {
      printf("As filas sao iguais\n\n");
      return;
    }
    a->start = n1->next;
    b->start = n2->next;
    recursive(a,b);
  } else {
    printf("\nAs Filas nao sao iguais!!\n");
  }

}

int main(){
	Queue * q;
	q = create();
	
	Queue * p;
	p = create();

	insertEnd(q,1);
	insertEnd(q,2);
	insertEnd(q,3);

	insertEnd(p,1);
	insertEnd(p,2);
	insertEnd(p,3);

  recursive(q,p);

	printf("Imprimindo a fila:\n");
	printQueue(q);
  parStart(q);
  parEnd(q);

  printf("Ordenado ? %d \n",isOrder(q));
	printf("Liberando a fila.\n");
	freeQueue(q);
	freeQueue(p);
	return 0;
}