#include <stdio.h>

struct Person
{
	char name[20];
	int age;
};
typedef struct Person people;

int selection = 0;
int bubble = 0;
int insertion = 0;

// BUUBLE SORT CRESCENTE
void bubbleSortCres(int n, people *v) {
    int i,j;
    people aux;
    for(i = 0; i < n; i++){
        for(j = 0; j < n-1; j++){
            if(v[j].age > v[j+1].age){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                j++;
            }
			bubble++;
        }
    }
}

// SELECTION SORT CRESCENTE
void selectionSortCres(int n, people *v){
	int i, j;
	int min;
	people aux;
    for(i=0; i<n-1; i++) {
        min = i;
        for(j=i+1; j<n; j++) {	
            if(v[j].age < v[min].age){
                min = j;
            }
            selection++;
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
	}
}

// INSERTION SORT CRESCENTE
void insertionSortCres(int n, people *v){
	int i, j;
	people aux;
    for(i=1; i<n; i++){
        aux = v[i];
        for(j = i-1; j >= 0 && v[j].age > aux.age; j--) {
            v[j+1] = v[j];
            insertion++;
        }
        v[j+1] = aux;
    }
}

// BUUBLE SORT DECRESCENTE
void bubbleSortDecr(int n, people *v) {
    int i,j;
    people aux;    
    for(i = 0; i < n; i++){
        for(j = 0; j < n-1; j++){
            if(v[j].age < v[j+1].age){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                j++;
            }  
        }
    }
}

// SELECTION SORT DECRESCENTE
void selectionSortDecr(int n, people *v){
	int i, j;
	int max, min;
	people aux;
    for(i=0; i<n-1; i++) {
        min = i;
        for(j=i+1; j<n; j++) {	
            if(v[j].age > v[min].age){
                min = j;
            }
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
	}
}

// INSERTION SORT DECRESCENTE
void insertionSortDecr(int n, people *v){
	int i, j;
	people aux;
    for(i=1; i<n; i++){
        aux = v[i];
        for(j = i-1; j >= 0 && v[j].age < aux.age; j--) {
            v[j+1] = v[j];
        }
        v[j+1] = aux;
    }
}

// Show vetor
void show(people *v)
{
	int i;
	for(i = 0; i < 7; i++)
		printf("\nNome %s    Idade %d",v[i].name, v[i].age);
}

int main()
{	
	people v[7] = {
	{"Jessica", 22},
	{"Lucas", 24},
	{"Joseff", 22},
	{"Johnny", 38},
	{"Albert", 20},
	{"Bernard", 18},
	{"Guilherme", 31}};
	
	// Show started vactor
	printf("Started vector\n");
	show(v);
	printf("\n");
	
	//order name by age using bubble sort
	bubbleSortCres(7, v);
	printf("\n\nUsando Bubble Sort\n\n");
	show(v);
	
	people vS[7] = {
	{"Jessica", 22},
	{"Lucas", 24},
	{"Joseff", 22},
	{"Johnny", 38},
	{"Albert", 20},
	{"Bernard", 18},
	{"Guilherme", 31}};
	
	//order name by age using selection sort
	selectionSortCres(7, vS);
	printf("\n\nUsando Selection Sort\n\n");
	show(vS);
	
	people vB[7] = {
	{"Jessica", 22},
	{"Lucas", 24},
	{"Joseff", 22},
	{"Johnny", 38},
	{"Albert", 20},
	{"Bernard", 18},
	{"Guilherme", 31}};
	
	//order name by age using insertion sort	
	insertionSortCres(7, vB);
	printf("\n\nUsando Insertion sort\n");
	show(vB);
	
	people vBD[7] = {
	{"Jessica", 22},
	{"Lucas", 24},
	{"Joseff", 22},
	{"Johnny", 38},
	{"Albert", 20},
	{"Bernard", 18},
	{"Guilherme", 31}};
	
	//order name by age using buuble sort	
	bubbleSortDecr(7, vBD);
	printf("\n\nUsando Bubble sort Decrescente\n");
	show(vBD);
	
	people vSD[7] = {
	{"Jessica", 22},
	{"Lucas", 24},
	{"Joseff", 22},
	{"Johnny", 38},
	{"Albert", 20},
	{"Bernard", 18},
	{"Guilherme", 31}};
	
	//order name by age using selection sort	
	selectionSortDecr(7, vSD);
	printf("\n\nUsando Selection sort Decrescente\n");
	show(vSD);
	
	people vID[7] = {
	{"Jessica", 22},
	{"Lucas", 24},
	{"Joseff", 22},
	{"Johnny", 38},
	{"Albert", 20},
	{"Bernard", 18},
	{"Guilherme", 31}};
	
	//order name by age using insertion sort	
	insertionSortDecr(7, vID);
	printf("\n\nUsando Insertion sort Decrescente\n");
	show(vID);
	
	printf("\n\n\nbubble : %d",bubble);
	printf("\nselection : %d",selection);
	printf("\ninsertion : %d",insertion);
		
	return 0;
}
