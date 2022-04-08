#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void quick_sort(int *a, int left, int right);

int main(int argc, char** argv)
{
 int i, vet[MAX];

 // Lê 10 valores
 for(i = 0; i < MAX; i++)
 {
  printf("Digite %d valor: ", i+1);
  scanf("%d", &vet[i]);
 }

 //Exibe vetor desordenado
 printf("\nValores desordenados");
 for(i = 0; i < MAX; i++)
 {
  printf("\n%d", vet[i]);
 }

printf("\n\nIniciando ordenacao!!!\n\n");

system("pause");

 // Ordena os valores
 quick_sort(vet, 0, MAX - 1);

 // Imprime o vetor ordenado
 printf("\nValores ordenados");
 for(i = 0; i < MAX; i++)
 {
  printf("\n%d", vet[i]);
 }

 printf("\n\nFim do vetor ordenado, o programa finalizado!\n");
 system("pause");
 return 0;
}

// Função QuickSort
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}
