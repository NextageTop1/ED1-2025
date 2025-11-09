#include "TStack.h"
#include <stdio.h>
#include <string.h>

int main(){
    Stack* pilha = Stack_create();
    //Ler a string 
    char input[1024];
    // fgets(input, 1024, stdin);
    scanf("%s",input);

    printf("%s\n", input);


    for(int i=0; i<strlen(input);i++){
        // if(input[i] == ' ' || input[i]== '.'){
        //     // int temp;
        //     // while(Stack_pop(pilha, &temp))
        //     //     printf("%c", temp);
        //     // putchar(' ');
        // }
        // else
            if(!Stack_push(pilha, input[i]))
                printf("Stackoverflow: %c\n", input[i]);
    }
    for(int i = 0 ; i < strlen(input); i++){
        
        int temp;
        Stack_pop(pilha , &temp);
        printf("[%c] [%d]\n", input[i] , input[i]);
        printf("[%c] [%d]\n", temp , temp);
        if((char)temp != input[i]){
            printf("\nA palavra não e igual!!!");
            putchar('\n');
            Stack_destroy(pilha);
            return 0;
        }

    }
    printf("E palindromo");
    putchar('\n');
    Stack_destroy(pilha);
    return 0;
}