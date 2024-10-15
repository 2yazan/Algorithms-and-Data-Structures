#ifndef UNTITLED_OLS_H
#define UNTITLED_OLS_H

#include "stdbool.h"
#include "stdio.h"

#define ListOk  0
#define ListNotMem  1
#define ListUnder  2
#define ListEnd  3
#define  SizeList 1000

typedef int BaseType;

typedef struct ListElement *ptrel;

typedef struct ListElement {
    BaseType data;
    ptrel next; /* flag=1 if the element belongs to the linked list */
    int isUsing; // flag=0 if free
} ListElement;

typedef struct List {
    ptrel Start;
    ptrel ptr;
    unsigned int N;
} List;

static ListElement MemList[SizeList];

static short ListError;

void InitList(List *L);

void PutList(List *L, BaseType E);

void GetList(List *L, BaseType *E);

void ReadList(List *L, BaseType *E);

bool IsListFull(List *L);

bool EndList(List *L);

unsigned int Count(List *L);

void BeginPtr(List *L);

void EndPtr(List *L);

void MovePtr(List *L);

void MoveTo(List *L, unsigned int n);

void DoneList(List *L);

void CopyList(List *L1, List *L2);

void InitMem(); /* assigns Flag of each element to 0 */
int EmptyMemList(); /* returns 1 if there are no free elements in the array */
unsigned NewMem(); // returns the number of the free element
void DisposeMem(unsigned n); /* makes the n-th element of the array free */

#endif //UNTITLED_OLS_H
