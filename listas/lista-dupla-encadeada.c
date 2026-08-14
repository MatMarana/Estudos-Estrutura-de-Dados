#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
	int valor;
	struct Celula *anterior;
	struct Celula *proximo;
}Celula;

typedef struct Lista_Dupla{
	int quantidade;
	Celula *inicio;
}Lista;

int main(){
	return 0;
}
