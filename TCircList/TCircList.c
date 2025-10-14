#include "TCircList.h"
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
        novo->prox = novo;
    }
    return novo;
}

TCircList* TCircList_create(){
    TCircList* nova = malloc(sizeof(TCircList));
    if(nova!=NULL){
        nova->inicio = NULL;
    }
    return nova;
}

bool TCircList_insert_end(TCircList* lista, int info){
    return false;
    
    /*TNo* novo = TNo_createNfill(info);
    if(novo == NULL) //Nao conseguimos memoria
        return false;
    return true;*/
}
//TODO: Implementar esta função
bool TCircList_insert_begin(TCircList* lista, int info){
    TNo* novo = TNo_createNfill(info);
    if(novo == NULL) //Nao conseguimos memoria
        return false;
    if(lista->inicio != NULL) //Ja existem nós na lista (pelo menos 1)
    {
        //Encontrar o último nó
        TNo* aux = lista->inicio;
        while(aux->prox != lista->inicio)
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = lista->inicio;
    }
    lista->inicio = novo;
    return true;
}

void TCircList_print(TCircList* lista){
    if(lista!=NULL && lista->inicio != NULL){
        TNo* aux = lista->inicio;
        do{
            printf("%d->", aux->info);
            aux = aux->prox;
        }while(aux!=lista->inicio);
        putchar('\n');
    }
}
//TODO: Implementar esta função
bool TCircList_try_to_delete(TCircList* lista, int info){
    return false;
}
//TODO: Implementar esta função 
void TCircList_free(TCircList* lista){
    
}

void EDmundo(int numeroNo, int distancia){
    if(numeroNo <= 0 || distancia <= 0)
        return;

    TCircList* lista = TCircList_create();

    for(int i = numeroNo; i >= 1; i--){ // Inserir do maior para o menor para manter ordem
        if(!TCircList_insert_begin(lista, i))
            printf("Erro ao inserir o elemento %d \n", i);
    }

    TNo* atual = lista->inicio;
    TNo* anterior = NULL;

    while(atual != atual->prox){ // Enquanto houver mais de um nó
        // Avança até o nó a ser removido
        for(int i = 1; i < distancia; i++){
            anterior = atual;
            atual = atual->prox;
        }
        // Remove o nó atual
        printf("Removendo: %d\n", atual->info);
        anterior->prox = atual->prox;
        if(atual == lista->inicio)
            lista->inicio = atual->prox;
        free(atual);
        atual = anterior->prox;

        TCircList_print(lista);
        printf("\n");
    }
    printf("Sobrevivente: %d\n", atual->info);
    free(atual);
    free(lista);
}