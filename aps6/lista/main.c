#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funcLista.h"


int main() {
	Serie* lista;
	Serie novoEp;
	
	// Start list
	lista = start();
	//Create a Epsode 
	strcpy(novoEp.nome, "Ep1");
	novoEp.duracao = 44;
	// Add Ep
	lista = inserir(lista, novoEp);	
	
	//Create a Epsode 
	strcpy(novoEp.nome, "Ep2");
	novoEp.duracao = 46;	
	// Add Ep
	lista = inserir(lista, novoEp);
	
	//Create a Epsode 
	strcpy(novoEp.nome, "Ep3");
	novoEp.duracao = 50;
	// Add Ep
	lista = inserir(lista, novoEp);
	
	// Show list
	printf("\nList:");
	printfList(lista);
	
	// Show recursive list
	printf("\n\nRecursive List:");
	printfRecursiveList(lista, 0);
	
	// Show invert recursive list
	printf("\n\nRecursive List invert:");
	printfRecursiveList(lista, 1);
	
	// Search Ep
	printf("\n\nSearching Ep:");
	Serie epsode = searchEp(lista);
	printf("\nEp: %s Duracao: %d",epsode.nome, epsode.duracao);
	
	// Search Ep
	printf("\n\nSearching Duracao:");
	Serie duraction = searchDuracao(lista);
	printf("\nEp: %s Duracao: %d",duraction.nome, duraction.duracao);
	
	// Remove ep of list
	printf("\n\nRemove List invert:");
	lista = removeList(lista);
	printfList(lista);
	
	// Free list
	printf("\n\Free List");
	freeList(lista);
		
	return 0;
}
