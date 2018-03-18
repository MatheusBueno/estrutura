#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// So sorry for my English  :)

int count(int* raiz, int exp, int num);

// call main
int main()
{
    // initial variables
    int raiz, a, num;
    int* exp = NULL;
    // reference exp to a
    exp = &a;

    // get value from a
    printf("Type a number:");
    scanf("%d", & num);

    // call count and save your value to whom to exp
    *exp = count(&raiz, *exp, num);

    // print values in console
    printf("\nValue of raiz: %d\n", raiz);
    printf("Value that Exp reference: %d\n", *exp);
    return 0;
}

// Calculate square root and return power of 2
int count(int* raiz, int exp, int num) {
    *raiz = sqrt(num);
    return pow(num,2);
 }
