#ifndef TLink_H
#define TLink_H
#include <stdbool.h>

typedef struct _list TLink;
typedef struct _no TNo;

TNo* createFill(int);

TLink* TLinkCreateList();

bool TLinkInsertEnd(TLink*,int );

bool TLinkInsertBegin(TLink* , int );

bool InsertTLinkGrow(TLink*  ,int );

void TLinkPrint(TLink*);





#endif