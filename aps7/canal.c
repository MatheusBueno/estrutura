#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "canalTAD.h"
#include "inscritoTAD.h"

void loading(){
  int i;
  system("cls");
  printf("Carregando\t");
  for (i = 0; i < 4; i++)  {
    printf(".");
    Sleep(300);
  }
}

int menu(){
	int op;
	printf("\n--- Menu ---");
	printf("\n1- Adicionar Canal");
	printf("\n2- Listar todos os Canais");
	printf("\n3- Canal com maior quantidade de visualizacoes");
	printf("\n4- Canal com menor quantidade de visualizacoes");
	printf("\n5- Remover o ultimo Canal da lista");
	printf("\n6- Remover o primeiro Canal da lista");
	printf("\n7- Mostrar quantidade de inscritos");
	printf("\n0- Sair\n");
	printf("\nEscolha sua opcao : ");
	scanf("%d", &op);
	if(op != 0){
	  loading();
	}
	
	return op;
}

int main(){
  int opcao;
  YoutCanal* listaCanais;
  listaCanais = startCanalYout();

  do{
    opcao = menu();
    switch(opcao) {
      case 1:
      listaCanais = criarCanal(listaCanais);
      break;
      case 2:
      printCanalList(listaCanais);
      break;
      case 3:
      maiorVisualizacoes(listaCanais);
      break;
      case 4:
      menorVisualizacoes(listaCanais);
      break;
      case 5:
      listaCanais = removerInicioCanal(listaCanais);
      break;
      case 6:
      listaCanais = removerFimCanal(listaCanais);
      break;
      case 7:
      printQtdInscList(listaCanais);
      break;
    }
  } while(opcao != 0);
  
  return 0;
}

