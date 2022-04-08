/*Grupo 5 - HeapSort:

    GU301505X - Alexandre José Tavares Junior	(alexandre.t@aluno.ifsp.edu.br)
    GU3015131 - Ana Paula Oliveira Castro	(castro.ana@aluno.ifsp.edu.br)
    GU3018067 - Amanda Aparecida Lopes de Souza (aparecida.amanda@aluno.ifsp.edu.br)
    GU3017141 - Everton Rodrigues Dos Santos	(everton.r@aluno.ifsp.edu.br)
*/

#include <stdio.h>
#include <stdlib.h>

void menu();
void heapfy1(int *vet,int n, int i);
void heapfy2(int *vet,int n, int i);
void create_heap(int *vet, int n, int opc);
void heapsort(int *vet, int n, int opc);
void imprimeVetor(int *vet);
void opcaoCrescente(int opc);
void opcaoDecrescente(int opc);


int main()
{
    menu();
}

// MENU DO PROGRAMA

void menu()
{
    int opc;
    do
    {
        printf("\n========================================== PROGRAMA ORDENA VETOR ==========================================");
        printf("\n\n\n   Ordeno o vetor de forma:\n\n    1 - Crescente (Heap Sort Maximo)\n\n    2 - Decrescente (Heap Sort Minimo)\n\n    3 - Sair do programa");
        printf("\n\n=========================================================================================================\n");
        printf("\n\n  Opcao: ");
        scanf("%d", &opc);
        system("cls");
        switch(opc)// switch case das opcoes do vetor
        {
        case 1:
            opcaoCrescente(opc);
            system("pause");
            system("cls");
            break;
        case 2:
            opcaoDecrescente(opc);
            system("pause");
            system("cls");
            break;

        case 3:
            printf("\n\n=========================================================================================================\n");
            printf("\n\n                    ENCERRANDO O PROGRAMA, AGUARDE...\n");
            printf("\n\n=========================================================================================================\n\n\n");
            break;

        default:
            printf("\n\n Insira uma opcao valida!!\n\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(opc!=3);
}

// HEAPFY
void heapfy1(int *vet,int n, int i)// heapfy1 corresponde ao heapfy da opcao 1(Heap Maior/Crescente)
{
    int esq =2*i+1;
    int dir =2*i+2;
    int maior,aux;

    //escolhe maior valor entre os filhos (esq e dir)
    maior = i;
    if((esq < n) && (vet[esq] > vet[maior]))
        maior = esq;
    if((dir < n) && (vet[dir] > vet[maior]))
        maior = dir;

    //se um dos filhos for maior que o pai, troca.
    if(maior != i)
    {
        aux = vet[i];
        vet[i] = vet[maior];
        vet[maior]=aux;

        //continua descida até o local adequado, o elemento trocado
        //é comparado com seus filhos, para o maior elemento ser o pai
        //isso é feito para que o pai sempre seja maior que os filhos.
        heapfy1(vet, n, maior);
    }
}

void heapfy2( int *vet, int n, int i)// heapfy2 corresponde ao heapfy da opcao 2(Heap Menor/Decrescente)
{
    int esq =2*i+1;
    int dir =2*i+2;
    int menor, aux;

    //escolhe menor valor entre os filhos (esq e dir)
    menor = i;
    if((esq < n) && (vet[esq] < vet[menor]))
        menor = esq;
    if((dir < n) && (vet[dir] < vet[menor]))
        menor = dir;

    //se um dos filhos for menor que o pai, troca.
    if(menor != i)
    {
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor]=aux;

        //continua descida até o local adequado, o elemento trocado
        //é comparado com seus filhos, para o menor elemento ser o pai
        //isso é feito para que o pai sempre seja menor que os filhos.
        heapfy2(vet, n, menor);
    }
}

//CRIA HEAP

void create_heap(int *vet, int n, int opc)
{
    int i;
    //For que irá olhar só para os nós pais
    for(i=n/2-1; i>=0; i--)
    {
        //O if sera responsavel por indicar qual Heapfy devera ser feito de acordo com a opcao escolhida
        if(opc == 1)
        {
            heapfy1(vet,n,i);//organiza o heap maximo
        }
        if(opc == 2)
        {
            heapfy2(vet,n,i);//organiza o heap minimo
        }

    }
}

void heapsort(int *vet, int n, int opc)
{
    int aux,i;
    //O create_heap faz a primeira organização para uma heap
    create_heap(vet,n, opc);
    imprimeVetor(vet);//imprime o primeiro heap
    for(i=n-1; i>0; i--)
    {
        //Troca maior(opcao 1)/menor(opcao 2) elemento(primeiro elemento do vetor) com o ultimo
        aux=vet[0];
        vet[0]=vet[i];
        vet[i]=aux;
        n--; //diminuindo o tamanho do vetor, pois o ultimo elemento do vetor já é o maior(opcao 1)/menor(opcao 2)

        //O if sera responsavel por indicar qual Heapfy devera ser feito de acordo com a opcao escolhida
        if(opc == 1)
        {
            heapfy1(vet,n,0);//Chama o heapfy para organizar a heap maximo
        }
        if(opc == 2)
        {
            heapfy2(vet,n,0);//Chama o heapfy para organizar a heap minimo
        }
    }
}

// IMPRESSAO

void opcaoDecrescente(int opc)
{
    int vet[10] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};
    printf("\n\n========================================== HEAP SORT MINIMO =============================================\n");
    printf("\n Vetor desordenado:   ");
    imprimeVetor(vet);
    printf("\n\n================================= COLOCANDO O VETOR EM ORDEM DECRESCENTE =================================\n");
    printf("\n\n Primeiro Heap minimo: ");
    heapsort(vet, 10, opc);
    printf("\n\n\n Vetor ja ordenado pelo Heap Sort minimo:   ");
    imprimeVetor(vet);
    printf("\n\n\n==========================================================================================================\n");
}

void opcaoCrescente(int opc)
{
    int vet[10] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};
    printf("\n\n========================================== HEAP SORT MAXIMO =============================================\n");
    printf("\n Vetor desordenado:   ");
    imprimeVetor(vet);
    printf("\n\n================================== COLOCANDO O VETOR EM ORDEM CRESCENTE ==================================\n");
    printf("\n\n Primeiro Heap maximo: ");
    heapsort(vet, 10, opc);
    printf("\n\n\n Vetor ja ordenado pelo Heap Sort maximo:   ");
    imprimeVetor(vet);
    printf("\n\n\n==========================================================================================================\n");
}

void imprimeVetor(int *vet)// funcao de impressao do vetor
{
    int i;
    for(i = 0; i < 10; i++)
    {
        printf("  %d  ", vet[i]);
    }
    printf("\n");
}


