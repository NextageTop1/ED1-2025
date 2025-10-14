#ifndef TSTATICLIST_H
#define TSTATICLIST_H
#include <stdbool.h>

typedef struct _list TStaticList;

TStaticList* TStaticList_create();

bool empty(TStaticList*);


bool full(TStaticList*);


bool TStaticList_insert_begin(TStaticList*, int);


void TStaticList_Print(TStaticList*);


#endif