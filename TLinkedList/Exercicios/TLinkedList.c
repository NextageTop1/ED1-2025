#include "TLinkedList.h"


typedef struct _no {
    int info;
    int info2;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
    int size; // Qtd de Nós 
};

TNo* TNo_createNfill(int info, int info2){
    TNo* novo = malloc(sizeof(TNo));
    if(novo!=NULL){
        novo->info = info;
        novo->info2 = info2;
        novo->prox = NULL;
    }
    return novo;
}

TLinkedList* TLinkedList_create(){
    TLinkedList* nova = malloc(sizeof(TLinkedList));
    if(nova!=NULL){
        nova->inicio = NULL;
        nova->size = 0;
    }
    return nova;
}

bool TLinkedList_insert_end(TLinkedList* lista, int info){
    TNo* novo = TNo_createNfill(info,0);
    if(novo == NULL) //Nao conseguimos memoria
        return false;
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        TNo* aux = lista->inicio;
        while(aux->prox != NULL)
            aux = aux->prox;
        //Aux agora eh o ultimo no da lista
        aux->prox = novo;
    }
    return true;
}
bool TLinkedList_insert_begin(TLinkedList* lista, int info){
    TNo* novo = TNo_createNfill(info,0);
    if(novo == NULL) //Nao conseguimos memoria
        return false;
    if(lista->inicio != NULL)
        novo->prox = lista->inicio;
    lista->inicio = novo;
    return true;
}

void TLinkedList_print(TLinkedList* lista){
    if(lista!=NULL){
        TNo* aux = lista->inicio;
        while(aux!=NULL){
            printf("%p:[info: %d, prox: %p]->\n", aux, aux->info, aux->prox);
            aux = aux->prox;
        }
    }
}
//Implementação dos Exercícios

/**
 * Exercício 1: Concatentar duas listas sem usar funções já existentes.
 * @param TLinkedList* Ponteiro para a primeira lista
 * @param TLinkedList* Ponteiro para a segunda lista a ser concatenada
 * @return TLinkedList* Ponteiro para a lista resultante.
 */
TLinkedList* TLinkedList_concatenate_pure(TLinkedList* L1, TLinkedList* L2){
    //Criar a lista de retorno
    TLinkedList* L3 = calloc(1, sizeof(TLinkedList));

    //Navegar pela lista 1, inserindo os elementos na lista resultante
    TNo* aux = L1->inicio;
    while(aux){
        TNo* novo = calloc(1, sizeof(TNo));
        if(novo == NULL) 
            break;
        novo->info = aux->info;
        //Inserir o novo no na lista L1
        if(L3->inicio == NULL){
           L3->inicio = novo;
        }else{
            TNo* aux2 = L3->inicio;
            while(aux2->prox != NULL)
                aux2 = aux2->prox;
            //Aux agora eh o ultimo no da lista
            aux2->prox = novo;
        }
        aux = aux->prox;
    }
    //Navegar pela lista 2, inserindo os elementos na lista resultante
    aux = L2->inicio;
    while(aux){
        TNo* novo = calloc(1, sizeof(TNo));
        if(novo == NULL) 
            break;
        novo->info = aux->info;
        //Inserir o novo no na lista L1
        if(L3->inicio == NULL){
           L3->inicio = novo;
        }else{
            TNo* aux2 = L3->inicio;
            while(aux2->prox != NULL)
                aux2 = aux2->prox;
            //Aux agora eh o ultimo no da lista
            aux2->prox = novo;
        }
        aux = aux->prox;
    }
    return L3;
}

TLinkedList* TLinkedList_concatenate(TLinkedList* L1, TLinkedList* L2){
    //Criar a lista de retorno
    TLinkedList* L3 = TLinkedList_create();

    //Navegar pela lista 1, inserindo os elementos na lista resultante
    TNo* aux = L1->inicio;
    while(aux){
        //Inserir o novo no na lista L3
        if(!TLinkedList_insert_end(L3, aux->info))
            break;
        aux = aux->prox;
    }
    //Navegar pela lista 2, inserindo os elementos na lista resultante
    aux = L2->inicio;
    while(aux){
        //Inserir o novo no na lista L3
        if(!TLinkedList_insert_end(L3, aux->info))
            break;
        aux = aux->prox;
    }
    return L3;
}

TLinkedList* TLinkedList_encode(char *bin){
    int len = strlen(bin);
    TLinkedList* lista = TLinkedList_create();

    int cont = 1 ; 
    for(int i = 1 ; i <= len ; i++){
        if(i < len && bin[i] == bin[i-1]){
            cont ++;
        }else{
            TNo* novo = TNo_createNfill(cont, bin[i-1] - '0');
            if(lista -> inicio == NULL){
                lista->inicio = novo;
            }else{
                TNo* aux = lista->inicio;
                while(aux->prox != NULL)
                    aux = aux->prox;
                aux->prox = novo;
            }
            lista->size++;
            cont = 1;
        }

    }
    return lista;
}

void TLinkedList_decode() {
    int n;
    scanf("%d", &n);

    TLinkedList* lista5 = TLinkedList_create();

    for(int i = 0 ; i < n; i++) {
        int qtd, bit;
        scanf("%d %d", &qtd, &bit);
        TNo* novo = TNo_createNfill(qtd, bit);
        if(lista5->inicio == NULL) {
            lista5->inicio = novo;
        } else {
            TNo* aux = lista5->inicio;
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
        lista5->size++;
    }

    for(TNo* aux = lista5->inicio; aux != NULL; aux = aux->prox) {
        for(int i = 0; i < aux->info; i++)
            printf("%d", aux->info2);
    }
    printf("\n");
}
