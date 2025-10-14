#include "TLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
};

TNo* TNo_createNfill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo!=NULL){
        novo->info = info;
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

bool TLinkedList_insert_end(TLinkedList* lista, int info){
    TNo* novo = TNo_createNfill(info);
    if(novo == NULL) //Nao conseguimos memoria
        return false;
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        TNo* aux = lista->inicio;
        while(aux->prox != NULL)
            aux = aux->prox;
        //Aux agora eh o ultimo no da lista
        aux->prox = novo;
    }
    return true;
}
bool TLinkedList_insert_begin(TLinkedList* lista, int info){
    TNo* novo = TNo_createNfill(info);
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
        while(aux!=NULL){
            printf("%p:[info: %d, prox: %p]->\n", aux, aux->info, aux->prox);
            aux = aux->prox;
        }
    }
}

bool try_to_delete(TLinkedList* lista , int info){
    if (lista == NULL)
        return false;
    if(lista->inicio != NULL){
        // Quem eu quero deletar é o inicio?
        if(lista->inicio->info == info){
            TNo* x = lista->inicio;
            lista->inicio = x->prox;
            free(x);
            return true;
        } else {
            TNo* y = lista->inicio;
            TNo* x = y->prox;
            while(x != NULL){
                if(x->info == info){
                    y->prox = x->prox;
                    free(x);
                    return true;
                }
                y = x;
                x = x->prox;
            }
        }
    }
    return false;
}

bool delete_list(TLinkedList* lista){
    if (lista == NULL)
        return false;
    TNo* aux = lista->inicio;
    while(aux != NULL){
        TNo* temp = aux;
        aux = aux->prox;
        free(temp);
    }
    lista->inicio = NULL;
    return true;
}