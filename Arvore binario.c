#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice {
    int valor;
    struct Vertice* esq;
    struct Vertice* dir;
    struct Vertice* pai;
} Vertice;

typedef struct Arvore {
    Vertice* raiz;
    int qtde;
} Arvore;

void in_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        in_ordem(raiz->dir);
    }
}

void pre_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

Vertice *cria_vertice(int valor) {
    Vertice* novo = (Vertice*)malloc(sizeof(Vertice));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;
    novo->valor = valor;
    return novo;
}

Arvore *cria_arvore() {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    arvore->qtde = 0;
    return arvore;
}

void inserir(Arvore* arvore, int valor) {
    Vertice *vertice = cria_vertice(valor);
    if (arvore->raiz != NULL) {
        Vertice *atual = arvore->raiz;
        Vertice *pai = NULL;
        while (atual != NULL) {
            pai = atual;
            if (valor < atual->valor) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }
        vertice->pai = pai;
        if (valor < pai->valor) {
            pai->esq = vertice;
        } else {
            pai->dir = vertice;
        }
    } else {
        arvore->raiz = vertice;
    }
    arvore->qtde++;
}

int remover_vertice(Arvore* arvore, Vertice* vertice) {
    if (vertice == NULL) return 0;

    Vertice *outro = NULL;
    if (vertice->esq == NULL || vertice->dir == NULL) {
        outro = vertice->esq ? vertice->esq : vertice->dir;
        if (outro != NULL) {
            outro->pai = vertice->pai;
        }
        if (vertice->pai == NULL) {
            arvore->raiz = outro;
        } else if (vertice == vertice->pai->esq) {
            vertice->pai->esq = outro;
        } else {
            vertice->pai->dir = outro;
        }
    } else {
        Vertice *pos = vertice->dir;
        while (pos->esq != NULL) {
            pos = pos->esq;
        }
        vertice->valor = pos->valor;
        return remover_vertice(arvore, pos);
    }

    free(vertice);
    arvore->qtde--;
    return 1;
}

Vertice *buscar_valor(Arvore* arvore, int valor) {
    Vertice* atual = arvore->raiz;
    while (atual != NULL) {
        if (valor < atual->valor) {
            atual = atual->esq;
        } else if (valor > atual->valor) {
            atual = atual->dir;
        } else {
            return atual;
        }
    }
    return NULL;
}

void liberar_arvore(Vertice* vertice) {
    if (vertice != NULL) {
        liberar_arvore(vertice->esq);
        liberar_arvore(vertice->dir);
        free(vertice);
    }
}

int main(void) {
    int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
    Arvore *arvore = cria_arvore();

    for (int i = 0; i < 10; i++) {
        inserir(arvore, dados[i]);
        printf("Inseriu %d mostra em ordem -> ", dados[i]);
        in_ordem(arvore->raiz);
        printf("\n");
        printf("Inseriu %d mostra em pré-ordem -> ", dados[i]);
        pre_ordem(arvore->raiz);
        printf("\n");
        printf("Inseriu %d mostra em pós-ordem -> ", dados[i]);
        pos_ordem(arvore->raiz);
        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        Vertice *vertice = buscar_valor(arvore, dados[i]);
        if (vertice != NULL) {
            remover_vertice(arvore, vertice);
        }
        printf("Removeu %d mostra em ordem -> ", dados[i]);
        in_ordem(arvore->raiz);
        printf("\n");
        printf("Removeu %d mostra em pré-ordem -> ", dados[i]);
        pre_ordem(arvore->raiz);
        printf("\n");
        printf("Removeu %d mostra em pós-ordem -> ", dados[i]);
        pos_ordem(arvore->raiz);
        printf("\n");
    }

    liberar_arvore(arvore->raiz);
    free(arvore);
    return 0;
}
