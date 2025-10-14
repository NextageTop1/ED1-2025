#include "TLink.h"
#include <stdio.h>
#include <stdlib.h>

struct _no{
    int info;
    struct _no *prox;
};

struct _list{
    Tno* inicio;
};


Tno* TLink_Createfill(int valor){
    Tno* novo = malloc(sizeof(Tno));

    if(novo != NULL){
        novo->info = valor;
        novo->prox = NULL; 
    }
    return novo;

}

TLink* TLink_Createlist(){
    TLink* nova = malloc(sizeof(TLink));

    if(nova!=NULL){
        nova->inicio = NULL;
    };

    return nova;

}

bool TLink_insertEnd(TLink* lista, int valor){    
    Tno* novo = TLink_Createfill(valor);
    if(novo == NULL)
        return false;
    if (lista->inicio == NULL){

        lista->inicio = novo;

    }else{
        Tno* aux = lista->inicio;
        while(aux->prox != NULL)
                aux = aux->prox;

            aux->prox = novo;
        }
    return true;
}

bool TLink_insertBegin(TLink* lista , int valor){
    Tno* novo = TLink_Createfill(valor);
    if(novo == NULL)
        return false;
    
    if(lista->inicio != NULL)
        novo->prox = lista->inicio;
    lista->inicio = novo;
    return true;
}

void TLink_Print(TLink* lista){
    if(lista){
        Tno* aux = lista->inicio;
        while(aux != NULL){
            printf("TNo:[%p]\nInfo: [%d]\nProx:[%p]\n\n",aux , aux ->info , aux->prox);
            aux = aux->prox;
        }
    }
}