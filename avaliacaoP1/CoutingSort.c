#include<stdio.h>

void CoutingSort(int *array, int n);
void Exibe_Vetor(int *vetor, int tamanho);

int main ()
{
    int n, i;

    printf("Digite o tamanho maximo do array: ");
    scanf("%i", &n);
    int array[n] ;

    for(i=0;i<n;i++){
        printf("Digite o valor da posicao %i: ",i+1);
        scanf("%i",&array[i]);
    }

    CoutingSort(array,n);
    printf("Vetor ordenado por CoutingSort: ");
    Exibe_Vetor(array, n);

    return 0;
}

void CoutingSort(int *array, int n)
{
	int i;

	// Encontrando o maior elemento do array

	int max=array[0];
	for(i = 0; i<n; i++){
		if(array[i]>max)
		max=array[i];
	}
	int VetorIndexA[max+1];

	// Inicializando o contador do array com todos os valores sendo zeros

	for(i=0;i<=max;i++)	{
		VetorIndexA[i]=0;
	}

	// Acumular a quantidade de vezes que cada número se repete no array

	for(i=0;i<n;i++){
		VetorIndexA[array[i]]++;
	}

	// Atualizar o contador do array

	for(i=1; i<=max;i++){
		VetorIndexA[i] = VetorIndexA[i]+VetorIndexA[i-1];
	}

	// Encontrando o indice de cada elemento

    int VetorIndexB[n];
	for(i=n-1; i>=0; i--){
		VetorIndexB[--VetorIndexA[array[i]]]=array[i];
	}

	// copiar os elementos do array original para o array b

	for(i=0;i<n;i++){
		array[i]=VetorIndexB[i];
	}
}

void Exibe_Vetor(int *vetor, int tamanho ){
    int seq;
    for(seq = 0; seq < tamanho; seq++){
        printf(" %i",vetor[seq]);
        if(seq < tamanho - 1) printf(", ");
        else printf("\n");
    }
}









