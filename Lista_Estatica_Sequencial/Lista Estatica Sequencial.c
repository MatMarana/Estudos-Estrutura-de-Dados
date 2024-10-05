#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10 

typedef struct ListaEstatica{ // Cria a struct
    int quantidade; // Inicia a variavel quantidade na struct
    int valores[TAMANHO]; // inicia o vetor de valores de tamanho 10
}Lista;

Lista *criaLista(){ // função que cria a lista
    Lista *lista;
    lista = malloc(sizeof(Lista)); // aloca espaço na memória para utilizar a lista
    lista->quantidade = 0; // quantidade = 0
    return lista;
}

int estaCheia(Lista *lista){
    if(lista->quantidade == TAMANHO){
        return 1;
    }
    return 0;
}

int estaVazia(Lista *lista){
    if(lista->quantidade == 0){
        return 1;
    }
    return 0;
}

void deslocarDireita(Lista *lista, int indice){
    for(int i = lista->quantidade; i>indice ;i--){
        lista->valores[i] = lista->valores[i-1];
    }
}

void deslocarEsquerda(Lista *lista, int indice){
    for(int i = indice; i<lista->quantidade-1;i++){
        lista->valores[i] = lista->valores[i+1];
    }
}

int procuraValor(Lista *lista, int valor){
    for(int i=0;i<lista->quantidade;i++){
        if(lista->valores[i] == valor){
            return i;
        }
    }
    return -1;
}

void insere(Lista *lista, int valor){
    int i;
    if(estaVazia(lista) == 1){
        lista->valores[0] = valor;
        lista->quantidade++;
    } else if(estaCheia(lista) == 1){
        return;
    } else {
        for(i=0;i<lista->quantidade;i++){
            if(valor <= lista->valores[i]){
                deslocarDireita(lista,i);
                lista->valores[i] = valor;
                break;
            }
        } 
        if(i == lista->quantidade){
            lista->valores[i] = valor;
        }
        lista->quantidade++;
    }
}

void removeValor(Lista *lista, int valor){
    if(estaVazia(lista) == 1){
        return;
    } else {
        if(procuraValor(lista,valor) == 0){
            return;
        } else {
            int indice = procuraValor(lista,valor);
            deslocarEsquerda(lista,indice);
            lista->quantidade--;
        }
    }
}

void mostraLista(Lista *lista){
    for(int i=0;i<lista->quantidade;i++){
        printf("%d ", lista->valores[i]);
    }
    printf("\n");

}

int main(){
    Lista *lista = criaLista();
    int valores[] = {21,14,13,10,87,35,27,56,85,29};
    for(int i=0;i<TAMANHO;i++){
        insere(lista,valores[i]);
        mostraLista(lista);
    }
    for(int i=0;i<lista->quantidade;i++){
        printf("O valor %d esta na posicao %d ", valores[i], procuraValor(lista,valores[i]));
        printf("\n");
    }
    for(int i=0;i<TAMANHO;i++){
        removeValor(lista,valores[i]);
        mostraLista(lista);
    }
    return 0;
}
