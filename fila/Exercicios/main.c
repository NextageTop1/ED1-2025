#include <stdio.h>
#include "Queue.h"
#include "TStack.h"
// 01 - Reverse
void reverse(Queue* fila){
    Stack* pilha = Stack_create(); 
    int temp;
    while(Queue_dequeue(fila, &temp)){
        if(!Stack_push(pilha, temp))
            break;
    }
    while(Stack_pop(pilha, &temp))
        if(!Queue_enqueue(fila, temp))
            break;

}
// 02
void tirar_negativo(Queue* fila){
    Queue* aux = Queue_create();
    int temp;
    while(Queue_dequeue(fila, &temp)){
        printf("%d,",temp);
        if(temp >= 0)
            Queue_enqueue(aux, temp);
    }
    while(Queue_dequeue(aux, &temp)){

        Queue_enqueue(fila, temp);
    }
}

// 03
void fusao_em_ordem_cres(Queue* f1,Queue* f2,Queue *result){
    int temp1 , temp2;
    bool t1 = Queue_dequeue(f1, &temp1);
    bool t2 = Queue_dequeue(f2, &temp2);

    while( t1 && t2 ){
        if(temp1 <= temp2){
            Queue_enqueue(result, temp1); 
            t1 = Queue_dequeue(f1, &temp1);
        }else{
            Queue_enqueue(result, temp2);
            t2 = Queue_dequeue(f2, &temp2);
        }
            
    }

    while(t1){
        Queue_enqueue(result, temp1);
        t1 = Queue_dequeue(f1, &temp1);
    }

    while(t2){
        Queue_enqueue(result, temp2);  
        t2 = Queue_dequeue(f2, &temp2);
    }
                
}
    
//04
void print_queue(Queue* fila){
    Queue* aux = Queue_create();
    int temp;
    while(Queue_dequeue(fila, &temp)){
        printf("%d,",temp);

        Queue_enqueue(aux, temp);
    }
    while(Queue_dequeue(aux, &temp)){

        Queue_enqueue(fila, temp);
    }

}
// 05 - Concatenado
Queue* Concatenado(Queue* f1, Queue* f2){
    Queue* result = Queue_create();
    int temp;
    while(Queue_dequeue(f1, &temp)){
        if(!Queue_enqueue(result, temp));
            printf("Man deu errado ak 1 [%d]",temp);
    }

    while(Queue_dequeue(f2, &temp)){
        if(!Queue_enqueue(result, temp));
            printf("Man deu wrong ak 2 [%d]", temp);
    }
    
    return result;
}

int main(){
    Queue* fila1 = Queue_create();
    Queue* fila2 = Queue_create();
    if(fila1 == NULL){
        printf("Erro ao instanciar a fila.\n");
        return 1;
    }
    int V[6] = {1, 2, 3, 4, 5, 6};
    for(int i=0; i<6; i++){
        if(!Queue_enqueue((i%2) ? fila1:fila2, V[i]))
            printf("Erro ao inserir o elemento V[%i]=%i\n", i, V[i]);
    }
    //Ex 04
    // print_queue(fila1);
    // //Ex 02
    // tirar_negativo(fila1);
    // //Ex 01
    // reverse(fila1);

    //Para ex 03
    // Queue* result = Queue_create();
    // fusao_em_ordem_cres(fila1, fila2, result);
    // print_queue(result);
    Queue* concataneda = Concatenado(fila1 , fila2);
    print_queue(concataneda);

    int temp;
    while(Queue_dequeue(fila1, &temp)){
        printf("Elemento removido da Fila: %d\n", temp);
    }
   
    return 0;
}