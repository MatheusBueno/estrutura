#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int insert = 0;

typedef struct CustomerCard {
    char name[50];
    char street[50];
    int number;
    char state[50];
    char city[50];
    char cep[9];
} CustomerCard;

int manyCustomers();
void addCustomer(CustomerCard *customers);
void printCustomer(CustomerCard* customers);
void start();

int main()
{
    start();
    printf("Finish him !!\n\n");
    Sleep(400);
    printf("Fatality !");
    return 0;
}

void start() {

    int question;
    int qtnCustomers = manyCustomers();
    CustomerCard* customers = (CustomerCard*) malloc(qtnCustomers * sizeof(CustomerCard));

    do {
    system("cls");
    printf("Hi !!\n\n");
    printf("Type: \n 1- insert a new customer\n 2- List all registered customers\n 3- Exit\n");
    scanf("%d", &question);

    if (question == 1) addCustomer(customers);
    else if(question == 2) printCustomer(customers);
    } while (question != 3);

    free(customers);
}

int manyCustomers(){
    int qtnCustomer;
    printf("How many customers do you want to register : ");
    scanf("%d", &qtnCustomer);
    return qtnCustomer;
}

void addCustomer(CustomerCard *customers){

    printf("--Customer %d Data--\n\n", insert);
    fflush(stdin);
    printf("Write customer's name: ");
    scanf("%s", customers[insert].name);
    fflush(stdin);
    printf("Write the customer's street: ");
    scanf("%s", customers[insert].street);
    fflush(stdin);
    printf("Write the customer's number: ");
    scanf("%d", &customers[insert].number);
    fflush(stdin);
    printf("Write the customer's city: ");
    scanf("%s", customers[insert].city);
    fflush(stdin);
    printf("Write the customer's state ");
    scanf("%s", customers[insert].state);
    fflush(stdin);
    printf("Write the customer's cep: ");
    scanf("%s", customers[insert].cep);
    fflush(stdin);
    insert++;
}

void printCustomer(CustomerCard *customers){
    for ( int i =0; i < insert; i++){
    printf("--Customer %d Data--\n\n", i);
    printf("Name: %s \n", customers[i].name);
    printf("Street: %s \n", customers[i].street);
    printf("Number: %d \n", customers[i].number);
    printf("City: %s \n", customers[i].city);
    printf("State: %s \n", customers[i].state);
    printf("CEP: %s\n\n", customers[i].cep);
    }
    system("pause");
}
