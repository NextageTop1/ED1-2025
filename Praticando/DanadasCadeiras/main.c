#include "Circ.h"
#include <stdio.h>
int main(){
    TCircList* lista = TCircList_create();
    int V[] = {1, 2, 3 , 4 , 5};
    for(int i=0; i<5; i++)
        if(!TCircList_insert_end(lista, V[i]))
            printf("Erro ao inserir o elemento V[%i]=%i\n", i, V[i]);


    TCircList_print(lista);
    //TCircList_try_to_delete(lista, 1);
    //TCircList_try_to_delete(lista, 3);
    //TCircList_print(lista);//Sobra apenas o nó 2
    //TCircList_free(lista);

    //EDmundo(9 , 4);
    EDanca();
    return 0;
}