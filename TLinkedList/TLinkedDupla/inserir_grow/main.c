#include "TLink.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    TLink* lista = TLinkCreateList();
    int v[5] = { 1 , 4  , 3 , 2, 5 };
    
    printf("Inserindo elementos em ordem crescente:\n");
    for(int i = 0; i < 5; i++){  // Corrigido para i < 5
        if(InsertTLinkGrow(lista, v[i])){  // Alterado para usar InsertTLinkGrow
            printf("Numero %d inserido com sucesso!\n", v[i]);
        } else {
            printf("Erro ao inserir %d\n", v[i]);
        }
    }
    
    printf("\nImprimindo a lista:\n");
    TLinkPrint(lista);
    
    return 0;
}