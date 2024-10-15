// Develop a program simulating a computing system with a constant time step (discrete time) 
// according to the individual task variant (table 16) using the module obtained from step 2. 
// Present the program's result in the form of table 15. The first column indicates the simulation 
// time 0, 1, 2, …, N. The second column lists the names of objects for each time moment 
// (queues — F1, F2, …, FN; stacks — S1, S2, …, SM; processors — P1, P2, …, PK), 
// and the third column lists the tasks (name, time) present in the objects.

#include <iostream>
#include "Stack/Stack.h"
#include "Queue/Queue.h"

struct TInquiry
{
    char Name[10]; // request name
    unsigned Time; // service time
    char P; /* task priority: 0 — highest,
 1 — medium, 2 — lowest */
} typedef TInquiry;

void InputString(char *a, int size) {
    char c = 0;
    for (int i = 0; i < size; i++) {
        scanf("%c", &c);
        if (c == ' ') {
            a[i] = '\0';
            return;
        }
        a[i] = c;
    }
}

void CheckFreeProcessor(int *P, Fifo *f0, Fifo *f1, Fifo *f2) {
    if (!EmptyFifo(f0))
        GetFifo(f0, P);
    else if (!EmptyFifo(f1))
        GetFifo(f1, P);
    else if (!EmptyFifo(f2))
        GetFifo(f2, P);
    else {
        printf("\n\nThe work of the program is over");
        exit(1);
    }
}

void OutputStatus() {
    printf("Processors status: %d %d");
}

// The base type will be: TInquiry
int main() {
    Fifo f0, f1, f2;
    InitFifo(&f0);
    InitFifo(&f1);
    InitFifo(&f2);
    int n; // Number of input requests
    printf("Enter the number of input requests");
    scanf("%d", &n);

    // Task input
    for (int i = 0; i < n; i++) {
        TInquiry T;
        InputString(T.Name, 10);
        scanf("%d %c", &T.Time, &T.P);

        switch (T.P) {
            case 0:
                PutFifo(&f0, T);
                break;
            case 1:
                PutFifo(&f1, T);
                break;
            case 2:
                PutFifo(&f2, T);
                break;
        }
    }

    // The state of tasks is displayed when one of the processors finishes its work
    int P0 = 0, P1 = 0;
    for (int i = 0; i < n; i++) {
        if (P0 == 0) {
            CheckFreeProcessor(&P0, &f0, &f1, &f2);
        } else if (P1 == 0) {
            CheckFreeProcessor(&P1, &f0, &f1, &f2);
        }

        int timeToNextStep = std::min(P0, P1);
        P0 -= timeToNextStep;
        P1 -= timeToNextStep;
    }

    return 0;
}
