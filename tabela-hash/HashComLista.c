#include <stdlib.h>
#include <stdio.h>

#define TAMANHO 11

typedef struct Celula{
    int valor;
    struct Celula* proximo;
}Celula;

typedef struct Lista{
    Celula *inicio;
    int quantidade;
}Lista;

Celula* iniciaCelula(int valor){
    Celula *celula = malloc(sizeof(Celula));
    if(celula){
        celula->valor = valor;
        celula->proximo = NULL;
    } else {
        printf("\nErro ao alocar memoria\n");
    }
    return celula;
}

Lista* iniciaLista(Lista *lista){
    lista->inicio = NULL;
    lista->quantidade = 0;
    return lista;
}

void inserirNaLista(Lista *lista, int valor){
    Celula* novo = iniciaCelula(valor);
    if(lista->quantidade == 0){
        lista->inicio = novo;
    } else {
        Celula* atual = lista->inicio;
        while(atual != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    lista->quantidade++;
}

int buscarNaLista(Lista *lista, int valor){
    Celula* atual = lista->inicio;
    while(atual != NULL && atual->valor != valor){
        atual = atual->proximo;
    }
    if(atual){
        return atual->valor;
    }
    return 0;
}

void imprimirLista(Lista* lista){
    Celula* atual = lista->inicio;
    while(atual != NULL){
        printf("%d\n", atual->valor);
        atual = atual->proximo;        
    }
}

void incializaTabela(Lista t[]){
    for(int i = 0; i < TAMANHO; i++){
        iniciaLista(&t[i]);
    }
}

int funcaoHash(int chave){
    return chave % TAMANHO;
}

void inserirNaHash(Lista t[], int valor){
    int chave = funcaoHash(valor);
    inserirNaLista(&t[chave], valor);
}

int buscarnaHash(Lista t[], int valor){
    int chave = funcaoHash(valor);
    return buscarNaLista(&t[chave], valor);
}

void imprimirHash(Lista t[]){
    for(int i = 0; i< TAMANHO; i++){
        printf("%2d", i);
        imprimirLista(&t[i]);
        printf("\n");
    }
}

int main(){
    int opcao,valor, retorno;
    Lista tabela[TAMANHO];
    inicializarTabela(tabela);

    do{
        printf("1-Inserir \n 2-buscar \n 3-Imprimi \n 0-Sair \n");
        scanf("%d", opcao);
        switch(opcao){
            case 1:
                printf("Digite o valor que deseja buscar");
                scanf("%d", valor);
                inserirNaHash(tabela,valor);
                break;
            case 2:
                printf("Digite o valor que deseja buscar");
                scanf("%d", valor);
                retorno = buscarnaHash(tabela, valor);
                if(retorno == 0){
                    printf("Valor não encontrado");
                }else{
                    printf("%d", retorno);
                };
                break;
            case 3:
                imprimirHash(tabela);
                break;
        }
    }while(opcao != 0);

    return 0;
}
