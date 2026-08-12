#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
	int valor;
	struct Celula *proximo;
}Celula;

typedef struct Lista{
	int quantidade;
	Celula *inicio;
}Lista;

Lista *iniciarLista(){
	Lista *lista = malloc(sizeof(Lista));
	lista->quantidade = 0;
	lista->inicio = NULL;
	return lista;
}

Celula *criarCelula(int valor){
	Celula *celula = malloc(sizeof(Celula));
	celula->valor = valor;
	celula->proximo = NULL;
	return celula;
}

void imprimirLista(Lista *lista){
	Celula *atual = lista->inicio; 
	while(atual != NULL){
		printf("%d ", atual->valor);
		atual = atual->proximo; 
	}
	printf("\n");
	printf("%d ", lista->quantidade);
}

void inserir(Lista* lista, Celula* celula){
	if(lista->inicio == NULL){
		lista->inicio = celula;
		lista->quantidade++;
		return;
	}

	Celula* atual = lista->inicio;
	while(atual->proximo != NULL){
		atual = atual->proximo;
	}
	atual->proximo = celula;
	lista->quantidade++;


}

int main(){
	Lista* lista = iniciarLista();
	Celula* celula = criarCelula(5);

	inserir(lista, celula);
	imprimirLista(lista);
	return 0;
}
