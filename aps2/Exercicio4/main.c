#include <stdio.h>
#include <stdlib.h>

int sum(int vet[], int qtn, int value);

int main()
{
    // size of vector
    int qtn =9;
    // Create a vector
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    printf("The sum is: %d", sum(array, qtn, 0));
    return 0;
}

// Sum vector's elements
int sum(int vet[], int qtn,int value) {
    // Return the sum of vector elements
    if(qtn < 0) return value;
    // Sum the current element vector
    else return sum(vet, qtn-1, value +=vet[qtn]);
}
