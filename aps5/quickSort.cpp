#include <stdio.h>

// So sorry for my English :)

// Show vector in console
void showVector(int *vector, int n) {
  int i;
  for (i = 0; i < n; i++) printf("%d ", vector[i]);
}

// QuickSort iterative
void quickSortIterativo(int *vector, int pivotal, int elements) {
  int rigth, aux, left, i =0;
  int v1[11], v2[11];
  v2[0] = elements;

 do {
    rigth = v2[i] - 1;
    left = v1[i];
    if (left < rigth) {
      pivotal = vector[left];

      while (left < rigth) {
        while (left < rigth && vector[rigth] >= pivotal) rigth--;
        if (left < rigth) vector[left++] = vector[rigth];
        while ( left < rigth && vector[left] <= pivotal)left++;
        if (left < rigth) vector[rigth--] = vector[left];
      }

      v1[i + 1] = left + 1;
      v2[i + 1] = v2[i];
      v2[i++] = left;
      vector[left] = pivotal;

      if (v2[i] - v1[i] > v2[i - 1] - v1[i - 1]) {
        aux = v1[i];
        v1[i] = v1[i - 1];
        v1[i - 1] = aux;

        aux = v2[i];
        v2[i] = v2[i - 1];
        v2[i - 1] = aux;
      }
    } else i--;
  } while (i >= 0);
}

int main() {
  int pivotal;
  int vector[11] = {1, 105, 34, 302, 201, 100, 65, 505, 12, 4, 5};

  printf("Type a pivotal : ");
  scanf("%d", &pivotal);

  quickSortIterativo(vector, pivotal, 11);
  printf("\nOrder by QuickSort:\n");
  showVector(vector, 11);
}
