#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct _tno TNo;

typedef struct _stack Stack;

Stack* Stack_create();

bool Stack_push(Stack* , int);

bool Stack_pop(Stack* , *int);

#endif 