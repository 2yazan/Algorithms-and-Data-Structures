#include "Tree.h"

// Links all elements of the array into a list of free elements
void InitMem(Tree *T) {
    for (int i = 0; i < Size; i++)
        MemTree[i].RSon = i + 1;
}

// Initializes the database
void InitTree(Tree *T, unsigned size) {
    MemTree[0].RSon = 1;
    Size = size;
    InitMem(T);
}

// Returns 1 if there are no free elements in the array,
// 0 otherwise
int EmptyMem(Tree *T) {
    return MemTree[0].RSon == Size;
}

// Returns the index of a free element and excludes it from the free list
unsigned int NewMem(Tree *T) {
    if (EmptyMem(T)) {
        TreeError = TreeNotMem;
        exit(TreeNotMem);
    }

    unsigned freeElementIndex = MemTree[0].RSon;
    MemTree[0].RSon = MemTree[freeElementIndex].RSon;
    return freeElementIndex;
}

// Creates the root of tree T with value x
void CreateRoot(Tree *T, BaseType x) {
    unsigned index = NewMem(T);
    element el = MemTree[index];
    el.data = x;
    el.RSon = 0;
    el.LSon = 0;
}

// Returns 1 if the element at index has a left son.
// 0 otherwise
int IsLSon(Tree *T, unsigned index) {
    return MemTree[index].LSon != 0;
}

// Returns 1 if the element at index has a right son.
// 0 otherwise
int IsRSon(Tree *T, unsigned index) {
    return MemTree[index].RSon != 0;
}

// Returns 1 if the database is empty. 0 otherwise
int IsEmptyTree(Tree *T) {
    return MemTree[0].RSon == 1;
}

// Writes element x to the tree Tree
void WriteDataTree(Tree *T, BaseType x) {
    if (IsEmptyTree(T)) {
        CreateRoot(T, x);
    } else if (MemTree[1].data < x) {
        if (IsLSon(T, 1)) {
            WriteDataTree_(T, x, MemTree[1].LSon);
        } else {
            MemTree[1].LSon = MemTree[0].RSon;
            CreateRoot(T, x);
        }
    } else {
        if (IsRSon(T, 1)) {
            WriteDataTree_(T, x, MemTree[1].RSon);
        } else {
            MemTree[1].RSon = MemTree[0].RSon;
            CreateRoot(T, x);
        }
    }
}

// Recursively descends to write element x
void WriteDataTree_(Tree *T, BaseType x, unsigned index) {
    if (MemTree[index].data < x) {
        if (IsLSon(T, index)) {
            WriteDataTree_(T, x, MemTree[index].LSon);
        } else {
            MemTree[index].LSon = MemTree[0].RSon;
            CreateRoot(T, x);
            return;
        }
    } else {
        if (IsRSon(T, index)) {
            WriteDataTree_(T, x, MemTree[index].RSon);
        } else {
            MemTree[index].RSon = MemTree[0].RSon;
            CreateRoot(T, x);
            return;
        }
    }
}

// Move to the left son, where T is the address of the cell containing the address of the current
// vertex, TS is the address of the cell containing the address of the root of the left
// subtree (left son)
void MoveToLSon(Tree *T, Tree *TS) {
    **TS = MemTree[**T].LSon;
}

// Deletes the tree
void DelTree(Tree *T) {
    Size = 0;
}

// Makes the n-th element of the array free and includes it in the free list
void DisposeMem(unsigned n) {
    MemTree[n].RSon = MemTree[0].RSon;
    MemTree[0].RSon = n;
}
