#include "Circ.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo* fim;

};

TNo* TNo_createNfill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo!=NULL){
        novo->info = info;
        novo->prox = novo;
    }
    return novo;
}

TCircList* TCircList_create(){
    TCircList* nova = malloc(sizeof(TCircList));
    if (nova != NULL)
        nova->fim = NULL;
    return nova;
}
bool TCircList_insert_end(TCircList* lista, int info){
    TNo* novo = TNo_createNfill(info);
    if  (novo == NULL)
        return false;
    if(lista->fim == NULL){
        lista->fim = novo;
        novo->prox = lista->fim;
        return true;
    };
    novo->prox = lista->fim->prox;
    lista->fim->prox = novo;
    lista->fim = novo;
    return true;
}
//TODO: Implementar esta função
bool TCircList_insert_begin(TCircList* lista, int info){
    TNo* novo = TNo_createNfill(info);
    if(novo == NULL) //Nao conseguimos memoria
        return false;
    if(lista->fim == NULL){ //Ja existem nós na lista (pelo menos 1)
    lista->fim = novo;
    novo->prox = lista->fim;
    return true;
    }
    novo->prox = lista->fim->prox;
    lista->fim->prox = novo;

    return true;
}

void TCircList_print(TCircList* lista){
    if(lista!=NULL && lista->fim != NULL){
        TNo* aux = lista->fim;
        do{
            printf("%d->", aux->info);
            aux = aux->prox;
        }while(aux!=lista->fim);
        putchar('\n');
    }
}

void EDanca(){

    TCircList* cadeiras = TCircList_create();
    TCircList* Djay = TCircList_create();

    int qtd_cadeiras = 0;
    int qtd_sec = 0;
    scanf("%d",&qtd_cadeiras);
    scanf("%d",&qtd_sec);

    for(int i = 1 ; i <= qtd_cadeiras; i++ )
        TCircList_insert_begin(cadeiras , i );
    for(int i = 1 ; i <= qtd_sec ; i++){
        int sec = 0;
        scanf("%d",&sec);
        TCircList_insert_begin(Djay , sec );
    }
    TNo* Djay_sec = Djay->fim->prox;
    while(cadeiras->fim != cadeiras->fim->prox){
        TNo* aux = cadeiras->fim->prox;
        TNo* y = cadeiras->fim;
        for(int i = 1 ; i <= Djay_sec->info ; i++ ){
            aux = aux->prox;
            y = y->prox;
        }
        
        if(aux == cadeiras->fim)
            cadeiras->fim = y;
        y->prox = aux->prox;
        Djay_sec = Djay_sec->prox;
        free(aux);
    }
    printf("sobrevicente foi %d ", cadeiras->fim->info);
}



