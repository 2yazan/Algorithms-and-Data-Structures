#ifndef CODE_LIST7_H
#define CODE_LIST7_H
#define capacity 1000

#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

/// error variables
// successful completion of the operation
static const short LIST_OK = 0;
// insufficient memory
static const short LIST_NOT_MEM = 1;
// pointer at the end of the list
static const short ListUnder = 2;
static const short ListEnd = 3;
static short ListError;

typedef int BaseType;
typedef unsigned ptrel;

struct List {
  int *PMemList;
  ptrel ptr;
  unsigned int N; // length of the list
  unsigned int SizeMem; // size of the array
} typedef List;

void InitList(List *L, unsigned SizeMem);

void PutList(List *L, BaseType x);

void GetList(List *L, BaseType *x);

void ReadList(List *L, BaseType *x);

bool FullList(List *L);

bool EndList(List *L);

unsigned int Count(List *L);

void BeginPtr(List *L);

void EndPtr(List *L);

void MovePtr(List *L);

void MoveTo(List *L, unsigned int n);

void CopyList(List *L1,List *L2);

void DoneList(List *L);

bool isEqual(List *L1,List *L2);

void CopyFromArray(List *L, const int *a, int n);

#endif //CODE_LIST7_H
