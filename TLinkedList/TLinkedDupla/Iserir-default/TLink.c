#include "TLink.h"
#include <stdio.h>
#include <stdlib.h>

struct _no{
    int info;
    struct _no *prox;
    struct _no *ant;
};

struct _list{
    Tno* inicio;
    Tno* fim;
};


Tno* TLink_Createfill(int valor){
    Tno* novo = malloc(sizeof(Tno));

    if(novo != NULL){
        novo->info = valor;
        novo->prox = NULL; 
        novo->ant = NULL;
    }
    return novo;

}

TLink* TLink_Createlist(){
    TLink* nova = malloc(sizeof(TLink));

    if(nova!=NULL){
        nova->inicio = NULL;
        nova->fim = NULL;
    };

    return nova;

}

bool TLink_insertEnd(TLink* lista, int valor){    
    Tno* novo = TLink_Createfill(valor);
    if(lista == NULL)
        return false;
    if(lista->fim == NULL){
        lista->inicio = novo;
        lista->fim = novo;
        return true;
    };
    lista->fim->prox = novo;
    novo->ant = lista->fim;
    lista->fim = novo;
    return true;
}

bool TLink_insertBegin(TLink* lista , int valor){
    Tno* novo = TLink_Createfill(valor);
    if(lista == NULL)
        return false;
    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
        return true;
    }
    novo->prox = lista->inicio;
    lista->inicio->ant = novo;
    lista->inicio = novo;
    return true;
}

void TLink_Print(TLink* lista){
    if(lista){
        Tno* aux = lista->inicio;
        while(aux != NULL){
            printf("TNo:[%p]\nInfo: [%d]\nProx:[%p]\nAnt[%p]\n\n",aux , aux ->info , aux->prox, aux->ant);
            aux = aux->prox;
        }
    }
}
void TLink_Print_Reverse(TLink* lista){
    if(lista){
        Tno* aux = lista->fim;
        while(aux != NULL){
            printf("TNo:[%p]\nInfo: [%d]\nProx:[%p]\nAnt[%p]\n\n",aux , aux ->info , aux->prox, aux->ant);
            aux = aux->ant;
        }
    }
}