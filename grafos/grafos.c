#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo{
	int quantidade_vertices;
	int matriz_adjacencia[4][4];
}Grafo;

Grafo *iniciarGrafo(){
	Grafo* grafo = malloc(sizeof(Grafo));
	grafo->quantidade_vertices = 0;
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
	for(int i = 0; i < grafo->quantidade_vertices; i++){
		printf(" %d ", i + 1);
	}
	printf("\n");

	for(int i = 0; i < grafo->quantidade_vertices; i++){
		printf("%d ", i + 1);
		for(int j = 0; j < grafo->quantidade_vertices; j++){
			printf(" %d ", grafo->matriz_adjacencia[i][j]);
		}
		printf("\n");
	}
}

int inserirVertice(Grafo *grafo){
	if(grafo->quantidade_vertices >= 4){
		return -1;
	}
	grafo->quantidade_vertices++;
	return 1;
}

int verificaVertice(int vertice, int quantidade_vertices){
	(vertice < 0 || vertice > quantidade_vertices) ? -1 : 1;
}

void insereAresta(Grafo* grafo, int vertice_1, int vertice_2){
	if(!verificaVertice(vertice_1, grafo->quantidade_vertices) 
			|| !verificaVertice(vertice_2, grafo->quantidade_vertices)){
		return;
	}

	grafo->matriz_adjacencia[vertice_1 - 1][vertice_2 - 1] = 1;
	grafo->matriz_adjacencia[vertice_2 - 1][vertice_1 - 1] = 1;
}

void removerAresta(Grafo* grafo, int vertice_1, int vertice_2){
	if(!verificaVertice(vertice_1, grafo->quantidade_vertices) 
			|| !verificaVertice(vertice_2, grafo->quantidade_vertices)){
		return;
	}

	grafo->matriz_adjacencia[vertice_1 - 1][vertice_2 - 1] = 0;
	grafo->matriz_adjacencia[vertice_2 - 1][vertice_1 - 1] = 0;
}

int main(){
	Grafo *grafo = iniciarGrafo();
	inserirVertice(grafo);
	inserirVertice(grafo);
	inserirVertice(grafo);
	inserirVertice(grafo);
	imprimirMatriz(grafo);
	insereAresta(grafo,1,2);
	insereAresta(grafo,2,4);
	insereAresta(grafo,2,3);
	insereAresta(grafo,1,4);
	imprimirMatriz(grafo);
	removerAresta(grafo,2,3);
	imprimirMatriz(grafo);
	return 0;
}
