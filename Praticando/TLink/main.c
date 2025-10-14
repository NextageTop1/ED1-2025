#include "TLink.h"
#include <stdio.h>



int main(){
    TLink* lista = TLink_Createlist();

    TLink_insertBegin(lista , 20);
    TLink_insertEnd(lista, 50);

    TLink_insertBegin(lista , 60);

    TLink_Print(lista);

    return 0;
}
