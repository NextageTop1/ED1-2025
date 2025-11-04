#ifndef BIGINT_H
#define BIGINT_H
#include <stdbool.h>

typedef struct _no Tno;
typedef struct _list TLink;


Tno* TLink_Createfill(int);

TLink* TLink_Createlist();

bool TLink_insertEnd(TLink*, int );

bool TLink_insertBegin(TLink*, int);

void TLink_Print(TLink*);

void ler_numero(TLink*);

void BigInt(void);



#endif