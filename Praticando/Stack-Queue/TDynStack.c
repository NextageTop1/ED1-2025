#include "Stack.h"
#include <stdlib.h>

struct _tno{
    int info;
    struct _tno *prox;
}

TNo* TNo_createNFill(int info){
    if(TNo* novo = malloc(sizeof(TNo))){
        novo->info = info;
        novo->prox = NULL;
        return true;
    }
    return false;
}

struct _stack{
    TNo* topo;
}

bool 

