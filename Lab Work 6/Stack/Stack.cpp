#include "Stack.h"

// Stack initialization
void InitStack(Stack *s) {
    s->ptr = 0;
}

// Check: is the stack empty?
int EmptyStack(Stack *s) {
    return s->ptr == 0;
}

void PutStack(Stack *s, int x) {
    if (s->ptr > StackSize) {
        StackError = StackOver;
        return;
    }

    s->Buf[++s->ptr] = x;
    StackError = StackOk;
}

// Extract an element from the stack
void GetStack(Stack *s, BaseType *E) {
    if (EmptyStack(s)) {
        StackError = StackUnder;
        return;
    }

    --s->ptr;
    StackError = StackOk;
}

// Read the element from the top of the stack
void ReadStack(Stack *s, BaseType *E) {
    *E = s->Buf[--(s->ptr)];
    StackError = StackOk;
}
