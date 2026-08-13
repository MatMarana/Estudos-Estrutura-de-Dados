#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo{
	int quantidade;
	int matriz_adjacencia[4][4];
}Grafo;

Grafo *iniciarGrafo(){
	Grafo* grafo = malloc(sizeof(Grafo));
	grafo->quantidade = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			grafo->matriz_adjacencia[i][j] = 0;
		}
	}

	return grafo;
}

void imprimirMatriz(Grafo *grafo){
	printf("Matriz de Adjacência: \n");
	printf("  ");
	for(int i = 0; i < 4; i++){
		printf(" %d ", i);
	}
	printf("\n");

	for(int i = 0; i < 4; i++){
		printf("%d ", i);
		for(int j = 0; j < 4; j++){
			printf(" %d ", grafo->matriz_adjacencia[i][j]);
		}
		printf("\n");
	}
}

int main(){
	Grafo *grafo = iniciarGrafo();
	imprimirMatriz(grafo);
	return 0;
}
