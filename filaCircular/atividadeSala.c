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

int isEmpty(Queue * p){
    if(p->start == NULL) return 1;
    return 0;
}

// print queue
void print(Queue * queue) {
    if(queue->start == NULL) return;

    Node * p = queue->start;

    for(p; p != queue->end; p = p->next) {
        printf("\n %d", p->value);
    }
    printf("\n %d", queue->end->value);
}

// search an element in queue
void search(Queue * queue, int value) {
    Node * p = queue->start;
    while(p != queue->end) {
        if(p->value == value){
            printf("\n %d", p->value);
            return;
        }
        p = p->next;
    }
    if(queue->end->value == value) printf("\n %d", p->value);
}

// Enfileirar
void enQueue(Queue * queue, int value) {
    Node * novo = malloc(sizeof(Node));
    Node * p = queue->start;
    novo ->value = value;

    if(isEmpty(queue)) {
        queue->start = novo;
        queue->end = novo;
        novo->next = novo;
    } else {
        queue->end = novo; // certo 
        novo->next = queue->start; // certo
    }    
}

// Desenfileirar
int deQueue(Queue *queue) {
    Node *p = queue->start;

    if(isEmpty(queue)) {
        return 0;
    } else {

    int value = p->value;

        if(queue->end == queue->start){
            free(queue->start);
            queue->start = queue->end = NULL;
            return value;
        } else {
            free(queue->start);
            queue->start = p->next;
            queue->end = queue->start;
            return value;
        }
    }

}

int main() {
    Queue *q;

    q = create();

    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);

    search(q, 1);

    // print(q);
    
    printf("\n Desenfileirando %d", deQueue(q));
    printf("\n Desenfileirando %d", deQueue(q));
    printf("\n Desenfileirando %d", deQueue(q));
    printf("\n Desenfileirando %d", deQueue(q)); 

    return 0;
}