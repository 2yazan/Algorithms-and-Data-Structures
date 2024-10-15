#ifndef CODE_QUEUE_H
#define CODE_QUEUE_H

#include "../OLS/OLS.h" // See lab work #5

const int FifoOk = ListOk;
const int FifoUnder = ListUnder;
const int FifoOver = ListNotMem;
int FifoError; // Error variable

typedef List Fifo;

void InitFifo(Fifo *f); // Initialize the queue
void PutFifo(Fifo *f, BaseType E); /* Put an element in the queue */
void GetFifo(Fifo *f, BaseType *E); /* Extract an element from the queue */
void ReadFifo(Fifo *f, BaseType *E); // Read an element
int EmptyFifo(Fifo *f); // Check if the queue is empty?
void DoneFifo(Fifo *f); // Destroy the queue

#endif //CODE_QUEUE_H
