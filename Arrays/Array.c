#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int vetor[], int tamanho){
	for(int i = 0; i < tamanho; i++){
		printf("%d ",vetor[i]);
	}
	printf("\n");
}

int buscar(int vetor[], int tamanho, int valor){
	for(int i = 0; i < tamanho; i++){
		if(vetor[i] == valor){
			printf("O valor %d existe na lista\n", valor);
			return i;
		}
	}
	return -1;
}
void inserir_no_final(int vetor[], int *quantidade, const int *capacidade, int valor){
	if(*quantidade == *capacidade){
		printf("O Array está na sua capacidade máxima");
		return;
	} 
	vetor[*quantidade] = valor;
	(*quantidade)++;
}

void main(){
	const int TAMANHO = 10;
	int vetor[TAMANHO]; 
	int valor;
	int quantidade = 0;

	for(int i = 0; i < 8; i++){
		vetor[i] = 0;
		quantidade++;
	}

	imprime_vetor(vetor,quantidade);

	inserir_no_final(vetor,&quantidade,&TAMANHO,3);

	imprime_vetor(vetor,quantidade);
	
	printf("Digite o valor que gostaria de encontrar: ");
	scanf("%d", &valor);
	
	int posicao = buscar(vetor,quantidade,valor);
	if(posicao == -1){
		printf("O valor não existe no vetor\n");
	} else {
		printf("O valor esta na posição ");
		printf("%d ", posicao);
		printf("\n");
	}
}
