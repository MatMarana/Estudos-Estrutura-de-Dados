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

void inserir_na_posicao(int vetor[], int *quantidade, const int *capacidade, int posicao, int valor){
	if(posicao < 0 || posicao >= *capacidade){
		return;
	}
	if(posicao > *quantidade){
		printf("Posição inválida\n");
		return;
	}
	for(int i = *quantidade; i > posicao; i--){
		vetor[i] = vetor[i-1];
	}
	vetor[posicao] = valor;
	(*quantidade)++;
}

void remover_na_posicao(int vetor[], int *quantidade, const int *capacidade, int posicao){
	if(posicao < 0 || posicao >= *capacidade){
		return;
	}
	
	if(posicao > *quantidade){
		printf("Posição inválida");
		return;
	}

	for(int i = posicao; i < *quantidade; i++){
		vetor[i]=vetor[i+1];
	}	

	(*quantidade)--;
}

void remover_valor(int vetor[], int *quantidade, int valor){
	int posicao = buscar(vetor,*quantidade,valor);
	if(posicao==-1){
		printf("O valor não exite na lista");
		return;
	}	
	for(int i = posicao; i < *quantidade; i++){
		vetor[i] = vetor[i+1];
	}
	(*quantidade)--;
}

int main(){
	const int TAMANHO = 10;
	int vetor[TAMANHO]; 
	int valor;
	int quantidade = 0;

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
	inserir_na_posicao(vetor,&quantidade,&TAMANHO,0,4);
	imprime_vetor(vetor,quantidade);
	inserir_na_posicao(vetor,&quantidade,&TAMANHO,1,5);
	imprime_vetor(vetor,quantidade);
	inserir_na_posicao(vetor,&quantidade,&TAMANHO,0,1);
	imprime_vetor(vetor,quantidade);
	remover_na_posicao(vetor,&quantidade,&TAMANHO,0);
	imprime_vetor(vetor,quantidade);
	remover_valor(vetor,&quantidade,5);
	imprime_vetor(vetor,quantidade);
	return 0;
}
