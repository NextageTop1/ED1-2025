#include "TLinkedList.h"
#include <stdio.h>

int main(){

    TLinkedList* lista = TLinkedList_create();
    
    for(int i = 0 ; i < 3 ; i++){
        float a;
        int b;
        printf("Insira o valor de A%d: ",i);
        scanf("%f", &a); 
        if (i == 2 ){    
            printf("Insira o grau: ");
            scanf("%d", &b); 
        }else{
            b = 1;
        }
        TLinkedList_insert_begin(lista,a,b);
    }
    TLinkedList_print(lista);
    return 0;
}