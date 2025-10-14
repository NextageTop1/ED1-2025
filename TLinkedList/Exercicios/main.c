#include "TLinkedList.h"
#include <stdio.h>

int main(){
    TLinkedList* lista1 = TLinkedList_create();
    TLinkedList* lista2 = TLinkedList_create();

    int V[] = {1, 2, 3, 40, 50, 60};
    for(int i=0; i<6; i++)
        if(!TLinkedList_insert_end((i<3)?lista1:lista2, V[i]))
            printf("Erro ao inserir o elemento V[%i]=%i\n", i, V[i]);
    TLinkedList_print(lista1);
    TLinkedList_print(lista2);
    //Teste do Exercício 1
    TLinkedList *lista3 = TLinkedList_concatenate(lista1, lista2);
    TLinkedList_print(lista3);

    char mode = 'c' ;
    if (mode == 'c'){
        char bin[1000];
        scanf("%s",bin);
        TLinkedList* lista5 = TLinkedList_encode(bin);
        printf("%d\n", lista5->size);
        for(TNo* aux = lista5->inicio; aux != NULL; aux = aux->prox){
            printf("%d %d\n", aux->info, aux->info2);
        }

    }else if(mode == 'd'){
        TLinkedList_decode();
        
        }

        return 0;
}
