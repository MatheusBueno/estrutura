
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
