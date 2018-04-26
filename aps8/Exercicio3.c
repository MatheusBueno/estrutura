#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
  int RA;
  char nome[30];
  float P1, P2, T, APS;
  struct Aluno *prev;
  struct Aluno *next;
} Aluno;

// Exercicio 3-a
Aluno *inserEnd(Aluno *list, int RA, char nome[], float P1, float P2, float T, float APS) {
  Aluno *new = (Aluno *)malloc(sizeof(Aluno));
  Aluno *p = list;
  int count = 0;
  new->P1 = P1;
  new->P2 = P2;
  new->APS = APS;
  new->RA = RA;
  new->T = T;
  strcpy(new->nome, nome);
  while(p->next != NULL){
    p = p->next;
  }

  p->next = new;
  new->next = NULL;
  new->prev = p;

  return list;
}

// Exercicio 3-b
Aluno *insertList(Aluno *list, int RA, int posicao, char nome[], float P1, float P2, float T, float APS) {
  Aluno *new = (Aluno *)malloc(sizeof(Aluno));
  Aluno *p = list;
  int count = 0;
  new->P1 = P1;
  new->P2 = P2;
  new->APS = APS;
  new->RA = RA;
  new->T = T;
  strcpy(new->nome, nome);

  while (count != posicao || p->next != NULL) {
    p = p->next;
    count++;
  }
  
  if(p->prev == NULL){
		printf(" primeiro elemento");
	  p->prev = new;
    new->next = p;
    new->prev = NULL;
	}
	else if(p->next == NULL){
		printf(" ultimo elemento");
    p->next = new;
    new->prev = p;
    new->next = NULL;
	  p->prev->next = p->next;
	}
	else{
		printf(" meio elemento");
    new->prev = p->prev;
    new->next = p;
    p->prev->next = new;
    p->prev = new;
	}

  return list;
}

// Exercicio 3-c
Aluno *removeList(Aluno *list, int posicao) {
  Aluno *p = list;
  int count = 0;

  if (posicao == 0) {
    p = list->next;
    p->prev = NULL;
    free(list);
    return p;
  }

  while (count != posicao || p->next != NULL) {
    p = p->next;
    count++;
  }

  if(p->prev == NULL){
		printf(" primeiro elemento");
	  list = p->next;
	}
	else if(p->next == NULL){
		printf(" ultimo elemento");
	  p->prev->next = p->next;
	}
	else{
		printf(" meio elemento");
    p->prev->next = p->next;
    p->next->prev = p->prev;
	}
  
  free(p);
  return list;
}
