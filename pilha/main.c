#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *proximo;
    int valor;
}Celula;

typedef struct Pilha{
    int quantidade;
    Celula *topo;
}Pilha;

Celula *iniciaCelula(int valor){
    Celula *celula = malloc(sizeof(Celula));
    celula->valor= valor;
    celula->proximo = NULL;
    return celula;
}

Pilha *iniciaPilha(){
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->quantidade = 0;
    pilha->topo = NULL;
    return pilha;
}

void empilhar(Pilha *pilha, int valor){
    Celula *celula = iniciaCelula(valor);
    celula->proximo = pilha->topo;
    pilha->topo = celula;
    pilha->quantidade++;
}

int desempilhar(Pilha *pilha){
    Celula *temp = pilha->topo;
    int valor = pilha->topo->valor;
    pilha->topo = pilha->topo->proximo;
    pilha->quantidade--;
    free(temp);
    return valor;
}

void mostraPilha(Pilha *pilha){
    Celula *atual = pilha->topo;
    printf("TOPO ----->");

    while(atual->proximo != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("<----- BASE\n");
}

int main(){
    Pilha *pilha = iniciaPilha();
    int v[] = {12,14,15,564,6,87,9,86,64};

    for(int i = 0; i< 9; i++){
        empilhar(pilha,v[i]);
        mostraPilha(pilha);
    }

    for(int i = 0; i< 9; i++){
        desempilhar(pilha);
        mostraPilha(pilha);
    }

    return 0;
}