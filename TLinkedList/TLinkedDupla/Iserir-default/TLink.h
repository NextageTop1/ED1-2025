#ifndef TLink_H
#define TLink_H
#include <stdbool.h>

typedef struct _no Tno;
typedef struct _list TLink;


Tno* TLink_Createfill(int);

TLink* TLink_Createlist();

bool TLink_insertEnd(TLink*, int );

bool TLink_insertBegin(TLink*, int);

void TLink_Print(TLink*);

void TLink_Print_Reverse(TLink*);




#endif