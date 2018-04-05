#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct Serie {
	char nome[30];
	int duracao;
	struct Serie * proximo_episodio; 	
} Serie;

Serie* start(){
	return NULL;
}

Serie* inserir(Serie* list, Serie serie) {
	Serie *novo = (Serie*) malloc (sizeof(Serie));
	strcpy(novo->nome, serie.nome);
	novo->duracao = serie.duracao;
	novo->proximo_episodio = list;
	return novo;
}

int isEmptyList(Serie * list){
	return (list == NULL);
}

void printfRecursiveList (Serie* list, int option) {
	Serie* p = list;
	if(!isEmptyList(p)){
		
		if(option == 0) {
			printf("\nEp : %s", p->nome);
			printf("\tDuracao : %d", p->duracao);
			printfRecursiveList(p->proximo_episodio, 0);	
		} else {
			printfRecursiveList(p->proximo_episodio, 1);
			printf("\nEp : %s", p->nome);
			printf("\tDuracao : %d", p->duracao);
		}
		
	}
}

void printfList (Serie* list) {
	Serie* p = list;
	if(isEmptyList(p)) {
		
	} else {
		while(p != NULL) {
			printf("\nEp : %s", p->nome);
			printf("\tDuracao : %d", p->duracao);
			p = p->proximo_episodio;
		}
	}
}

Serie* removeList(Serie* list) {
	char ep[3];
	printf("\nDigite um Ep : ");
	fflush(stdin);
	gets(ep);
	Serie* p = list;
	Serie* prior = NULL;
	int equalsEp = strcmp(p->nome, ep);
	if(strcmp(list->nome, ep) == 0){
		prior = list;
		list = list->proximo_episodio;
		free(prior);
		return list;
	}
	
	while(p != NULL && equalsEp != 0) {
		prior = p;
		p = p->proximo_episodio;
	}
	if (p == NULL) return prior;
	else prior->proximo_episodio = p->proximo_episodio;
	free(p);
	return list;
}

Serie searchEp(Serie* list) {
	char ep[3];
	printf("\nDigite o Ep a ser pesquisado : ");
	gets(ep);
	Serie* p = list;
	Serie* prior = NULL;
	Serie found;
	int equalsEp = strcmp(p->nome, ep);
	if(strcmp(list->nome, ep) == 0){
		found.duracao = list->duracao;
		strcpy(found.nome, list->nome);
		return found;
	}
	
	while(p != NULL && equalsEp != 0) {
		prior = p;
		p = p->proximo_episodio;
	}
	if (p == NULL){
		found.duracao = prior->duracao;
		strcpy(found.nome, prior->nome);
		return found;
	}
	else prior->proximo_episodio = p->proximo_episodio;
	free(p);
	found.duracao = p->duracao;
		strcpy(found.nome, p->nome);
		return found;
}

Serie searchDuracao(Serie* list) {
	int durac;
	printf("\nDigite a duracao a ser pesquisado : ");
	scanf("%d", & durac);
	Serie* p = list;
	Serie* prior = NULL;
	Serie found;
	if(durac == list->duracao){
		found.duracao = list->duracao;
		strcpy(found.nome, list->nome);
		return found;
	}
	
	while(p != NULL && durac != list->duracao) {
		prior = p;
		p = p->proximo_episodio;
	}
	if (p == NULL){
		found.duracao = prior->duracao;
		strcpy(found.nome, prior->nome);
		return found;
	}
	else prior->proximo_episodio = p->proximo_episodio;
	free(p);
	found.duracao = list->duracao;
		strcpy(found.nome, found.nome);
		return found;
}

void freeList(Serie * list){
	Serie* p = list;
	while(p != NULL){
		Serie* temp = p->proximo_episodio;
		free(p);
		p = temp;
	}
}
