#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
	int valor;
	struct Celula *anterior;
	struct Celula *proximo;
}Celula;

typedef struct Lista{
	int quantidade;
	Celula *inicio;
}Lista;

Celula *iniciar_celula(int valor){
	Celula *celula = malloc(sizeof(Celula));
	celula->valor = valor;
	celula->anterior = NULL;
	celula->proximo = NULL;
	return celula;
}

Lista *iniciar_lista(){
	Lista *lista = malloc(sizeof(Lista));
	lista->quantidade = 0;
	lista->inicio = NULL;
	return lista;
}

void imprimir_lista(Lista *lista){
	Celula *atual = lista->inicio;
	while(atual != NULL){
		printf("Valor: %d", atual->valor);
		printf("\n");
		atual = atual->proximo;
	}
}

void inserir_no_inicio(Lista *lista, int valor){
	Celula *celula = iniciar_celula(valor);
	
	if(lista->quantidade == 0){
		lista->inicio = celula;
		lista->quantidade++;
		return;
	}

	Celula *atual = lista->inicio;

	celula->proximo = atual;
	atual->anterior = celula;
	lista->inicio = celula;
	
	lista->quantidade++;

}

void inserir_no_final(Lista *lista, int valor){
	Celula *celula = iniciar_celula(valor);

	if(lista->quantidade == 0){
		lista->inicio = celula;
		lista->quantidade++;
		return;
	}
	
	Celula *atual = lista->inicio;

	while(atual->proximo != NULL){	
		atual = atual->proximo;
	}

	atual->proximo = celula;
	celula->anterior = atual;
	lista->quantidade++;
}

int main(){
	Lista *lista = iniciar_lista();
	inserir_no_inicio(lista, 5);
	inserir_no_inicio(lista, 4);
	inserir_no_final(lista,7);
	inserir_no_final(lista,9);
	imprimir_lista(lista);
	return 0;
}
