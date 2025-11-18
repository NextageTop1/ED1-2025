#include "Queue.h"
#include <stdlib.h>
#define MAX 5

struct _no{
    int info;
    struct _no *prox;
};

struct _queue {
    unsigned int qty;
    TNo* head;
    TNo* tail;

};

TNo* TNo_createNfill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo != NULL){
        novo->info = info;
        novo->prox = NULL;
    };
    return novo;
}

/**
 * Cria instâncias da fila;
 * @return Queue* Ponteiro para uma fila válida 
 * ou NULL caso não consiga memória para alocação
 */
Queue* Queue_create(){
    Queue* nova = malloc(sizeof(Queue));
    if(nova){
        nova->qty = 0 ;
        nova->head = NULL;
        nova->tail = NULL;
    }
    return nova;
}
/**
 * Tenta realizar a inserção de um elemento na Fila.
 * @param Queue* ponteiro para a fila
 * @param int variável inteira cujo valor será armazenado na Fila
 * @return bool informando se a operação pode ser realizada.
 */
bool Queue_enqueue(Queue* fila, int info){
    if(fila == NULL || Queue_is_full(fila))
        return false;

    TNo* novo = TNo_createNfill(info);
    if(fila->head == NULL){
        fila->head = novo;
        fila->tail = novo;
        fila->qty++;
        return true;
    }
    
    fila->tail->prox = novo;
    fila->tail = novo;
    fila->qty++;
    return true;

}
/**
 * Tenta realizar a remoção de um elemento na Fila.
 * @param Queue* ponteiro para a fila
 * @param int* ponteiro para variável inteira que receberá o valor removido da fila
 * @return bool informando se a operação pode ser realizada.
 * 
 * Uso: int temp;
 * if(Queue_dequeue(instanceOfQueue, &temp))
 *  printf("Deu certo remover da fila. Valor do elemento: %d", temp);
 * else
 *  printf("Nao foi possivel remover da fila (provavelmente está vazia)");
 */
bool Queue_dequeue(Queue* fila, int* pinfo){
    if(fila == NULL || Queue_is_empty(fila) ){
        return false;
    }
    TNo* aux = fila->head;
    *pinfo = aux->info;
    fila->head = fila->head->prox;
    if(fila->qty == 1)
        fila->tail = NULL;
    fila->qty--;
    free(aux);
    return true;

}

/**
 * Checa se a fila está cheia;
 * @param Queue* instância da fila
 * @return bool informando se está cheia.
 */
bool Queue_is_full(Queue*);
/**
 * Checa se a fila está vazia;
 * @param Queue* instância da fila
 * @return bool informando se está vazia.
 */
bool Queue_is_empty(Queue*);
/**
 * Retorna a quantidade de elementos atualmente na fila
 * @param Queue* instância da fila
 * @return unsigned int : Quantidade de elementos presentes na fila.
 */
unsigned int Queue_get_qty(Queue*);