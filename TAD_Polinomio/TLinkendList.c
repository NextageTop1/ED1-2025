#include "TLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    float info;
    int info2 ;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
};

TNo* TNo_createNfill(float info , int info2){
    TNo* novo = malloc(sizeof(TNo));
    if(novo!=NULL){
        novo->info = info;
        novo->info2 = info2;
        novo->prox = NULL;
    }
    return novo;
}

TLinkedList* TLinkedList_create(){
    TLinkedList* nova = malloc(sizeof(TLinkedList));
    if(nova!=NULL){
        nova->inicio = NULL;
    }
    return nova;
}

bool TLinkedList_insert_begin(TLinkedList* lista, float info , int info2){
    TNo* novo = TNo_createNfill(info,info2);
    printf("Inserindo o par {%f , %d }\n", novo->info , novo->info2);
    if(novo == NULL) //Nao conseguimos memoria
        return false;
    if(lista->inicio != NULL)
        novo->prox = lista->inicio;
    lista->inicio = novo;
    return true;
}


void TLinkedList_print(TLinkedList* lista){
    if(lista!=NULL){
        TNo* aux = lista->inicio;
        
            printf("%2.fx^%d",aux->info,aux->info2);
            aux = aux->prox;
            if(aux->info < 0)
                printf("%2.fx",aux->info);
            else
                printf(" +%2.fx",aux->info);

            aux = aux->prox;
            printf(" +%2.f",aux->info);
        
    }
}
