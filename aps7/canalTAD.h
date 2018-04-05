#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "inscritoTAD.h"


typedef struct YoutInscrito {
  char nomeInsc[50];
  int idade;
  struct YoutInscrito* proximoInsc;
} YoutInscrito;

YoutInscrito* startInscritoYout();
int isEmptyInscList(YoutInscrito * list);

YoutInscrito* startInscritoYout(){
  return NULL;
}

int isEmptyInscList(YoutInscrito * list){
	return (list == NULL);
}

YoutInscrito* criarInscrito(YoutInscrito* inscritoList) {
  	YoutInscrito* novo = (YoutInscrito*) malloc(sizeof(YoutInscrito));

  	printf("\nDigite o nome do inscrito: ");
  	fflush(stdin);
 	scanf(" %s", &novo->nomeInsc);
	printf("\nIdade do inscrito: ");
	scanf("%d",&novo->idade);
  	novo->proximoInsc = inscritoList;
  	return novo;
}

void printInscList(YoutInscrito* list){
	YoutInscrito* p = list;
	if(isEmptyInscList(p)){
		printf("\nCanal sem inscritos");
	}
	else{
		while(p != NULL){
      		printf("\n  Nome do inscrito: %s", p->nomeInsc);
      		printf("\n  Idade do inscrito: %d", p->idade);
			p = p->proximoInsc;
		}
	}
}

int countInscList(YoutInscrito* list){
	YoutInscrito* p = list;
  	int count =0;
	if(isEmptyInscList(p)){
		return count;
	}
	else{
		while(p != NULL){
      count++;
			p = p->proximoInsc;
		}
	}
  return count;
}


YoutInscrito* startInscritoYout();
int isEmptyInscList(YoutInscrito * list);
typedef struct YoutCanal {
  char nome[50];
  struct YoutInscrito* inscritos;
  int visualizacoes;
  int videos;
  struct YoutCanal* proximo;
} YoutCanal;

YoutCanal* startCanalYout() {
  return NULL;
}

int isEmptyCanalList(YoutCanal * list){
	return (list == NULL);
}

YoutCanal* criarCanal(YoutCanal *lista) {
  YoutCanal* novo = (YoutCanal*) malloc(sizeof(YoutCanal));
  YoutInscrito* inscritosList;
  int qtdInscritos = 0;
  
  inscritosList = startInscritoYout();
  printf("\nDigite o nome do canal: ");
  fflush(stdin);
  scanf(" %s", &novo->nome);
  printf("\nTotal de visualizacoes: ");
  scanf("%d", &novo->visualizacoes);
  printf("\nQuantidade de videos: ");
  scanf("%d", &novo->videos);
  printf("\nQuantos inscritos tem o canal? ");
  scanf("%d",&qtdInscritos);

  while( qtdInscritos > 0) {
    inscritosList = criarInscrito(inscritosList);
    qtdInscritos--;
  }
  novo->inscritos = inscritosList;
  novo->proximo = lista;
  system("cls");
  return novo;
}

void printCanalList(YoutCanal* list){
	YoutCanal* p = list;
	if(isEmptyCanalList(p)){
		printf("\nEssa lista esta vazia!\n");
	}
	else{
		while(p != NULL){
			printf("\nNome do canal: %s", p->nome);
			printf("\nTotal de visualizacoes: %d", p->visualizacoes);
			printf("\nQuantidade de videos: %d", p->videos);
			printf("\nListando Inscritos :");
			printInscList(p->inscritos);
     		printf("\n");
			p = p->proximo;
		}
	}
	printf("\n");
	system("pause");
	system("cls");
}

void maiorVisualizacoes(YoutCanal * list){
	int visualizacoes = list->visualizacoes;
 	YoutCanal canalMaior;
	YoutCanal * p = list;
	while(p != NULL){
		if(p->visualizacoes > visualizacoes){
      	strcpy(canalMaior.nome,p->nome);
     		canalMaior.visualizacoes = p->visualizacoes;
     		canalMaior.videos = p->videos;
		    visualizacoes = p->visualizacoes;
		}
		p = p->proximo;
	}
 	printf("\n--- Canal com maior visualizacoes ---");
  	printf("\nNome do canal: %s", canalMaior.nome);
	printf("\nTotal de visualizacoes: %d",canalMaior.visualizacoes);
	printf("\nQuantidade de videos: %d",canalMaior.videos);
  	printf("\n");
}

void menorVisualizacoes(YoutCanal * list){
	int visualizacoesMenor = list->visualizacoes;
 	YoutCanal canalMenor;
	YoutCanal * t = list;
	while(t != NULL){
		if(visualizacoesMenor > t->visualizacoes){
      		strcpy(canalMenor.nome,t->nome);
      		canalMenor.visualizacoes = t->visualizacoes;
      		canalMenor.videos = t->videos;
			visualizacoesMenor = t->visualizacoes;
		}
		t = t->proximo;
	}
  	printf("\n--- Canal com maior visualizacoes ---");
 	printf("\nNome do canal: %s", canalMenor.nome);
	printf("\nTotal de visualizacoes: %d",canalMenor.visualizacoes);
	printf("\nQuantidade de videos: %d",canalMenor.videos);
 	printf("\n");
}

YoutCanal* removerInicioCanal(YoutCanal * list){
	if(isEmptyCanalList(list)){
		return NULL;
	}
	else{
		YoutCanal * aux = list;
		list = aux->proximo;
		free(aux);
		return list;
	}
}

YoutCanal* removerFimCanal(YoutCanal* lista){
	if(isEmptyCanalList(lista)){
		return NULL;
	}
	else{
		YoutCanal* ultimo = lista->proximo;
		YoutCanal* penultimate = lista;
		while(ultimo->proximo != NULL){
			penultimate = ultimo;
			ultimo = ultimo->proximo;
		}
		penultimate->proximo = NULL;
		free(ultimo);
		return lista;
	}
}

void printQtdInscList(YoutCanal* list){
	YoutCanal* p = list;
	if(isEmptyCanalList(p)){
		printf("\nEssa lista esta vazia!\n");
	}
	else{
		while(p != NULL){
			printf("\n");
			printf("\nNome do canal: %s", p->nome);
			printf("\nTotal de visualizacoes: %d", p->visualizacoes);
			printf("\nQuantidade de videos: %d", p->videos);
			printf("\nQuantidade de inscritos: %d", countInscList(p->inscritos));
      		printf("\n");
			p = p->proximo;
		}
	}
}
