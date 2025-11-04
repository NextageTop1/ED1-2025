#include "BigInt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void BigIntPrint(TLink* lista){
    if(lista){
        Tno* aux = lista->inicio;
        while(aux != NULL){
            printf("[%d]->",aux->info);
            aux = aux->prox;
        }
        printf("[NULL]");
        printf("\n");
    }

}

void ler_numero(TLink* lista){
    char n[4096];
    printf("Digite o Numero =\n");
    scanf("%s" , n);
    for(int i = 0 ; i < strlen(n) ; i++){
        printf("%c = %d\n",n[i] , n[i]);
        printf("%c = %d\n",n[i] , n[i] - '0');

        TLink_insertEnd(lista , n[i] - '0');

    }

}

void BigInt(){
    TLink* lista1 = TLink_Createlist();
    TLink* lista2 = TLink_Createlist();
    TLink* resul = TLink_Createlist();

    ler_numero(lista1);
    ler_numero(lista2);

    BigIntPrint(lista1);
    BigIntPrint(lista2);

    Tno* aux1 = lista1->fim;
    Tno* aux2 = lista2->fim;

    int vai_um = 0;

    while(aux1 != NULL || aux2 != NULL ||vai_um > 0){
        int soma = vai_um;
        if(aux1 != NULL){
            soma += aux1->info;
            aux1 = aux1->ant;
        };
        if(aux2 != NULL){
            soma += aux2->info;
            aux2 = aux2->ant;
        };
        vai_um = soma/10;
        TLink_insertBegin(resul , soma%10);
    }
    BigIntPrint(resul);
    
}