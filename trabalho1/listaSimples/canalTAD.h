#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

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
	if(list == NULL) {
		printf("\nLista vazia");
		return;
	}
	int visualizacoes = list->visualizacoes;
	char nome[50];
 	YoutCanal canalMaior;
	YoutCanal * p = list;
	while(p != NULL){
		printf("\nNome do canal: %s", p->nome);
		if( visualizacoes <p->visualizacoes){
			strcpy(nome, p->nome);
			//printf("%c",p->nome[0]);
			printf("\nNome do canal: %s", p->nome);
		    visualizacoes = p->visualizacoes;
		}
		p = p->proximo;
	}
 	printf("\n--- Canal com maior visualizacoes ---");
  	printf("\nNome do canal: %s",nome);
	printf("\nTotal de visualizacoes: %d",visualizacoes);
  	printf("\n");
}

void menorVisualizacoes(YoutCanal * list){	
	if(list == NULL) {
		printf("\nLista vazia");
		return;
	}
	int visualizacoesMenor = list->visualizacoes;
 	char nome[50];
	YoutCanal * t = list;
	while(t != NULL){
		if(visualizacoesMenor > t->visualizacoes){
      		strcpy(nome,t->nome);
			visualizacoesMenor = t->visualizacoes;
		}
		t = t->proximo;
	}
  	printf("\n--- Canal com maior visualizacoes ---");
 	printf("\nNome do canal: %s", nome);
	printf("\nTotal de visualizacoes: %d", visualizacoesMenor);
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
		if(lista->proximo == NULL) {
			return NULL;
		}
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
