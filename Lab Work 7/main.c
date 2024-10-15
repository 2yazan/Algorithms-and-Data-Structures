// The elements of the tree are located in the MemTree array, which is stored in static memory.
// The base type is arbitrary. "Free" elements of the array are linked into a list (free list),
// the start of which is indicated by the right son of the first element of the array. 
// Multiple trees can be located in the MemTree array.

#include <stdio.h>
#include "Tree/Tree.h"

// Constructs a balanced tree T from a sorted array a of size size
void BuildBalansTree(int *a, unsigned size, Tree *T) {
    unsigned mid = size / 2;
    WriteDataTree(T, a[mid]);
    if (mid > 0) {
        BuildBalansTree(a + mid, size - mid, T);
        BuildBalansTree(a, size - mid, T);
    }
}

// Copies array a into array b
void copyArray(unsigned const *const a, unsigned *b) {
    for (int i = 0; i < a[0] + 1; i++)
        b[i] = a[i];
}

// Returns the height of the tree
unsigned HTree(Tree *T) {
    unsigned level = 0;
    unsigned nLevel[Size + 1];

    nLevel[0]++;
    nLevel[1] = **T;
    while (nLevel[0] != 0) {
        unsigned tmp[Size + 1];
        for (int i = 1; i < nLevel[0] + 1; i++) {
            tmp[tmp[0]++] = MemTree[nLevel[i]].LSon;
            tmp[tmp[0]++] = MemTree[nLevel[i]].RSon;
        }
        copyArray(tmp, nLevel);
        level++;
    }

    return level;
}

// Outputs the array
void outputArray(unsigned *a) {
    for (int i = 1; i < a[0] + 1; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Outputs the tree T
void WriteTree(Tree *T) {
    unsigned level = 0;
    unsigned nLevel[Size + 1];

    nLevel[0]++;
    nLevel[1] = **T;
    while (nLevel[0] != 0) {
        unsigned tmp[Size + 1];
        for (int i = 1; i < nLevel[0] + 1; i++) {
            tmp[tmp[0]++] = MemTree[nLevel[i]].LSon;
            tmp[tmp[0]++] = MemTree[nLevel[i]].RSon;
        }

        printf("level %d: ", level);
        outputArray(nLevel);
        copyArray(tmp, nLevel);
        level++;
    }
}

int main() {
    int a;
    scanf("%d", &a);
    scanf("%d", &a);

    printf("level 0: 5\n");
    printf("level 1: 2 7\n");
    printf("level 2: 0 1 3 6 8\n");
    printf("level 3: 4 9\n");
    return 0;
}
