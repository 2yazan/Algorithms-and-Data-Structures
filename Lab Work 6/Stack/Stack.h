#ifndef CODE_STACK_H
#define CODE_STACK_H

#include <malloc.h>

const int StackSize = 1000;
const int StackOk = 0; // All OK
const int StackOver = 1; // Stack overflow
const int StackUnder = 2; // Stack is empty
int StackError; // Error variable

typedef int BaseType; // Define the type of stack element
struct Stack {
    int Buf[StackSize];
    unsigned ptr; // Points to the element that is the top of the stack
} typedef Stack;

void InitStack(Stack *s); // Stack initialization
int EmptyStack(Stack *s); // Check: is the stack empty?
void PutStack(Stack *s, BaseType E); // Place an element on the stack
void GetStack(Stack *s, BaseType *E); // Extract an element from the stack
void ReadStack(Stack *s, BaseType *E); // Read the element from the top of the stack

#endif //CODE_STACK_H
