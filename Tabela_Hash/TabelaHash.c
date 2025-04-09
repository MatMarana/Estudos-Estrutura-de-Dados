#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 11//s,epre o primo mais proximo do tamanho desejado
#define FATOR_DE_CARGA 0.54 // Quantidade de dados do conjuto / Tamanho do conjunto;
// Utilizado para ver qual porcentagem da tabela está sendo ocupada (Entre 0 e 1)
//Quanto mais perto de 1 mais cheio

void inicializarTabela(int t[]){
    for(int i = 0; i < TAMANHO; i++){
        t[i] = 0;
    }
}

int funcaoHash(int chave, int tamanho){
    return chave % tamanho;
}

int buca(int tabela[], int chave, int tamanho){
    int valorHash = funcaoHash(chave, tamanho);
    while(tabela[valorHash] != 0){
        if(tabela[valorHash] == chave){
            return tabela[valorHash];
        } else {
            valorHash = funcaoHash(valorHash % 1, tamanho);
        }
    }
    return 0;
}

void inserir(int tabela[], int chave, int tamanho){
    int valorHash = funcaoHash(chave, tamanho);
    if(tabela[valorHash] == 0){
        tabela[valorHash] = chave;
    } else {
        while(tabela[valorHash] != 0){
            valorHash = funcaoHash(valorHash % 1, tamanho);
        }
        tabela[valorHash] = chave;
    }
}

void printTabela(int tabela[]){
    for(int i = 0; i < TAMANHO; i++){
        printf("%d = %d",i, tabela[i]);
    }
}

int main(){
    int opcao,valor, retorno;
    int tabela[TAMANHO];
    inicializarTabela(tabela);

    do{
        printf("1-Inserir \n 2-buscar \n 3-Imprimi \n 0-Sair \n");
        scanf("%d", opcao);
        switch(opcao){
            case 1:
                printf("Digite o valor que deseja buscar");
                scanf("%d", valor);
                inserir(tabela,valor,TAMANHO);
                break;
            case 2:
                printf("Digite o valor que deseja buscar");
                scanf("%d", valor);
                retorno = buscar(tabela, valor, TAMANHO);
                if(retorno == 0){
                    printf("Valor não encontrado");
                }else{
                    printf("%d", retorno);
                };
                break;
            case 3:
                printTabela(tabela);
                break;
        }
    }while(opcao != 0);

    return 0;
}