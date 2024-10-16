#include "List7.h"

void InitList(List *L, unsigned SizeMem) {
  L->PMemList = malloc(sizeof(BaseType) * SizeMem);
  L->SizeMem = SizeMem;
  L->N = 0;
  L->ptr = 0;
}

void PutList(List *L, BaseType x) {
  if (FullList(L)) {
    ListError = LIST_NOT_MEM;
    return;
  }
  L->PMemList[++(L->ptr)] = x;
  L->N++;
  ListError = LIST_OK;
}

void GetList(List *L, BaseType *x) {
  bool isFind = false;
  for (int i = 0; i < L->SizeMem; i++) {
    if (isFind) {
      L->PMemList[i - 1] = L->PMemList[i];
    } else if (L->PMemList[i] == *x) {
      isFind = true;
      (L->N)--;
    }
  }
}

bool FullList(List *L) {
  return L->N == capacity;
}

bool EndList(List *L) {
  return L->N == capacity - 1;
}

unsigned int Count(List *L) {
  return L->N;
}

void BeginPtr(List *L) {
  L->ptr = 0;
}

void EndPtr(List *L) {
  L->ptr = L->N;
}

void MovePtr(List *L) {
  (L->ptr)++;
}

void MoveTo(List *L, unsigned int n) {
  L->ptr = n;
}

void DoneList(List *L) {
  free(L->PMemList);
  L->SizeMem = 0;
  L->N = 0;
  L->ptr = 0;
}

void CopyList(List *L1, List *L2) {
  L2->PMemList = L1->PMemList;
  L2->SizeMem = L1->SizeMem;
  L2->N = L1->N;
  L2->ptr = L1->ptr;
}

// Returns true if the list L1 is equal to L2, false otherwise.
bool isEqual(List *L1, List *L2) {
  if (L1->N != L2->N)
    return false;

  for (int i = 0; i < L1->N; i++) {
    if (L1->PMemList[i] != L2->PMemList[i])
      return false;
  }
  return true;
}

// Copies values from array 'a' of size 'n' into list L
void CopyFromArray(List *L, int const *a, int const n) {
  for (int i = 0; i < n; i++)
    L->PMemList[i] = a[i];
  L->N = n;
}
