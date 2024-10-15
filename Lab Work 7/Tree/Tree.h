#ifndef CODE_TREE_H
#define CODE_TREE_H

#include "stdio.h"
#include "stdlib.h"

#define capacity 1000

typedef int BaseType;

static const int TreeOk = 0;
static const int TreeNotMem = 1;
static const int TreeUnder = 2;
static int TreeError;

typedef unsigned int PtrEl;

struct element {
    BaseType data;
    PtrEl LSon;
    PtrEl RSon;
} typedef element;

typedef PtrEl *Tree;
static unsigned Size;
static element MemTree[capacity];

// Initializes the tree
void InitTree(Tree *T, unsigned size);

// Creates the root
void CreateRoot(Tree *T, BaseType x);

// Returns 1 if the element at index has a left son.
// 0 otherwise
int IsLSon(Tree *T, unsigned index);

// Returns 1 if the element at index has a right son.
// 0 otherwise
int IsRSon(Tree *T, unsigned index);

// Returns 1 if the database is empty. 0 otherwise
int IsEmptyTree(Tree *T);

// Returns 1 if there are no free elements in the array,
// 0 otherwise
int EmptyMem(Tree *T);

// Returns the index of a free element and excludes it from the free list
unsigned int NewMem(Tree *T);

// Writes data
void WriteDataTree(Tree *T, BaseType x);

void WriteDataTree_(Tree *T, BaseType x, unsigned index);

// Reading
void ReadDataTree(Tree *T, BaseType *E);

// Move to the left son, where T is the address of the cell containing the address of the current
// vertex, TS is the address of the cell containing the address of the root of the left
// subtree (left son)
void MoveToLSon(Tree *T, Tree *TS);

// Move to the right son
void MoveToRSon(Tree *T, Tree *TS);

// Links all elements of the array into a list of free elements
void InitMem(Tree *T);

// Deletes the leaf
void DelTree(Tree *T);

// Makes the n-th element of the array free and includes it in the free list
void DisposeMem(unsigned n);

#endif //CODE_TREE_H
