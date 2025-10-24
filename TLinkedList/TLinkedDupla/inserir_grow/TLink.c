#include "TLink.h"
#include <stdio.h>
#include <stdlib.h>

struct _no{
    int info;
    struct _no *prox;
    struct _no *ant;
};

struct _list{
    TNo* inicio;
    TNo* fim;
};

TNo* createFill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo != NULL){
        novo->prox = NULL;
        novo->ant = NULL;
        novo->info = info;
    }
    return novo;
}

TLink* TLinkCreateList(){
    TLink* nova = malloc(sizeof(TLink));
    if(nova != NULL){
        nova->inicio = NULL;
        nova->fim = NULL;
    }
    return nova;
}

bool TLinkInsertEnd(TLink* lista,int info){
    TNo* novo = createFill(info);
    if(novo == NULL)
        return false;
    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
        return true;
    }
    lista->fim->prox = novo;
    novo->ant = lista->fim;
    lista->fim = novo;
    return true;

}

bool TLinkInsertBegin(TLink* lista, int info){
    TNo* novo = createFill(info);
    if(novo == NULL)
        return false;
    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
        return true;
    }
    lista->inicio->ant = novo;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    return true;
}

void TLinkPrint(TLink* lista){
    int op;
    printf("Inicio para o fim == [1]\nFim para o Inicio == [2]\n\n");
    scanf("%d",&op);

    if(op == 1){
        TNo* aux = lista->inicio;
        while(aux != NULL){  // Mudança na condição do loop
            printf("Anterior: [%p]\nNO: [%p]\nInfo: [%d]\nProx: [%p]\n\n", aux->ant, aux, aux->info, aux->prox);
            aux = aux->prox;
        }
        return ;
    }
    TNo* aux = lista->fim;
        while(aux != NULL){  // Mudança na condição do loop
            printf("Anterior: [%p]\nNO: [%p]\nInfo: [%d]\nProx: [%p]\n\n", aux->ant, aux, aux->info, aux->prox);
            aux = aux->ant;
        }
    return;
}

bool InsertTLinkGrow(TLink* lista, int info){
    TNo* novo = createFill(info);
    if(novo == NULL)
        return false;

    if(lista->inicio == NULL){  // Lista vazia
        lista->inicio = novo;
        lista->fim = novo;
        return true;
    }

    TNo* aux = lista->inicio;

    if(novo->info < aux->info) {
        novo->prox = aux;
        aux->ant = novo;
        lista->inicio = novo;
        return true;
    }

    while(aux->prox != NULL && aux->prox->info < novo->info) {
        aux = aux->prox;
    }

    if(aux->prox == NULL) {
        aux->prox = novo;
        novo->ant = aux;
        lista->fim = novo;  
    } else {  
        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox->ant = novo;
        aux->prox = novo;
    }

    return true;
}