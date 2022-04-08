#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao;
    printf("------BEM VINDO-----\n");
    printf("--------------------\n\n");

    printf("Lista de programas:\n");
    printf("1 - BubbleSort\n");
    printf("2 - InsertionSort\n");
    printf("3 - SeletionSort\n");
    printf("4 - ShellSort\n");
    printf("5 - MergeSort\n");
    printf("6 - QuickSort\n");
    printf("7 - HeapSort\n");
    printf("8 - RadixSort\n");
    printf("9 - TimSort\n");
    printf("10 - BeadSort\n");
    printf("11 - CountingSort\n\n");
    printf("Escolha o programa de ordenacao que deseja usar: ");
    scanf("%d", &opcao);

    switch(opcao){
    case 1:
        printf("BubbleSort");
    break;
    case 2:
        printf("InsertionSort");
    break;
    case 3:
        printf("SeletionSort");
    break;
    case 4:
        printf("ShellSort");
    break;
    case 5:
        printf("MergeSort");
    break;
    case 6:
        printf("QuickSort");
    break;
    case 7:
        printf("HeapSort");
    break;
    case 8:
        printf("RadixSort");
    break;
    case 9:
        printf("TimSort");
    break;
    case 10:
        printf("BeadSort");
    break;
    case 11:
        printf("CountingSort");
    break;
    default:
        printf("Escolha um valor valido.");
    break;
    }
}
