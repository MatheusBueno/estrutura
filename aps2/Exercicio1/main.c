#include <stdio.h>
#include <stdlib.h>

typedef struct CustomerCard {
    char name[50];
    char street[50];
    int number;
    char state[50];
    char city[50];
    char cep[9];
} CustomerCard;

void addClient(CustomerCard *client);
void printClient(CustomerCard *client);

int main()
{
    CustomerCard client;
    addClient(&client);
    printClient(&client);

    return 0;
}

void addClient(CustomerCard * client){
    printf("Write client's name: ");
    scanf("%s", client->name);

    printf("Write the client's street: ");
    scanf("%s", client->street);

    printf("Write the client's number: ");
    scanf("%d", &client->number);

    printf("Write the client's city: ");
    scanf("%s", client->city);

    printf("Write the client's state ");
    scanf("%s", client->state);

    printf("Write the client's cep: ");
    scanf("%s", client->cep);
    printf("\n\n");
}

void printClient(CustomerCard * client){
    printf("--Client Data--\n\n");

    printf("Name: %s \n", client->name);
    printf("Street: %s \n", client->street);
    printf("Number: %d \n", client->number);
    printf("City: %s \n", client->city);
    printf("State: %s \n", client->state);
    printf("CEP: %s", client->cep);
}
