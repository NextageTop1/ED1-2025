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
        if(!Stack_push(pilha, input[i]))
            printf("Stackoverflow: %c\n", input[i]);
    }
    int x = 0;
    for(int i = 0 ; i < strlen(input);i++){
        int temp;
        Stack_pop(pilha,&temp);
        if((char)temp == '(')
            x += 1 ;
        if((char)temp == ')')
            x -= 1;     
    }
    puts((x == 0)? "Esta certa!!" : "Esta Errada" );

    putchar('\n');
    Stack_destroy(pilha);
    return 0;
}