#include "TStack.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//TODO: Implementar as funções usando um vetor estático

struct _stack{
    int data[MAX];
    int topo;
};

Stack* Stack_create(){
    Stack* pilha = malloc(sizeof(Stack));
    if(pilha != NULL)
        pilha->topo = -1;
    return pilha;

}

bool Stack_push(Stack* pilha , int valor){
    if(pilha == NULL || Stack_is_full(pilha))
        return false;

    pilha->data[pilha->topo + 1] = valor;
    pilha->topo += 1 ; 
    return true;
}

bool Stack_pop(Stack* pilha , int* valor){
    if(pilha == NULL || Stack_is_empty(pilha))
        return false;
    *valor = pilha->data[pilha->topo];
    pilha->topo -= 1;
    return true;
}

bool Stack_is_empty(Stack* pilha){
    if(pilha->topo == -1){
        return true;
    }
    return true;
}

bool Stack_is_full(Stack* pilha){
    if(pilha->topo == MAX - 1){
        return true;
    }
    return false;
}
