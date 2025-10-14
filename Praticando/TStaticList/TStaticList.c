#include "TStaticList.h"
#include "stdio.h"
#include "stdlib.h"

struct _list{
        int qtd;
        int data[100];
};

bool empty(TStaticList* lista){
    return lista->qtd == 0;
}

bool full(TStaticList* lista){
    return lista->qtd == 100;
}


TStaticList* TStaticList_create(){
    TStaticList* nova = malloc(sizeof(TStaticList));
    if (nova != NULL){
        nova->qtd = 0;
    }
    return nova;
}

bool TStaticList_insert_begin(TStaticList* lista, int valor){
    if(lista != NULL && !full(lista)){
        // Desloca elementos para a direita
        for(int i = lista->qtd; i > 0; i--){
            lista->data[i] = lista->data[i-1];
        }
        lista->data[0] = valor;
        lista->qtd++;
        return true;
    }
    return false;
}

void TStaticList_Print(TStaticList* lista){
    if(lista){
        if(empty(lista)){
            printf("A Lista está Vazia!!!!");
        }else{
            for(int i = 0 ; i < lista->qtd ; i++){
                printf("Posição : [%d]\nValor : [%d]\n\n", i, lista->data[i]);
            }
        }

    }

}

TStaticList* TStaticList_merge_no_repeat(TStaticList* lista1 , TStaticList* lista2){
    if(lista1 == NULL && lista2 == NULL)
        printf("");

}