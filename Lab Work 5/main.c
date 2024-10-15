//: PLS. The array on which the PLS is implemented is located in dynamic memory
//  (the base type of the element is determined by the task). Memory for the array is allocated 
//  during PLS initialization, and the number of elements is stored in the descriptor.

// A polynomial P(x) = anx^n + an-1x^(n-1) + ... + a1x + a0 with integer coefficients can be represented 
// as a list, and if ai = 0, the corresponding element is not included in the list.
// Define a logical function EQUAL(p, q) that checks if polynomials p and q are equal.

#include <stdio.h>
#include "List7/List7.c"

void test1() {
  int a1[7] = {3, 5, 7, 1, 0, 5};
  List l1;
  InitList(&l1, 6);
  CopyFromArray(&l1, a1, 6);

  int a2[6] = {3, 5, 7, 1, 0, 5};
  List l2;
  InitList(&l2, 6);
  CopyFromArray(&l2, a2, 6);

  if (isEqual(&l1, &l2) == 1)
    printf("First test passed\n");
  else
    printf("First test failed\n");
}

void test2() {
  int a1[7] = {3, 5, 7, 1, 0, 5, 3};
  List l1;
  InitList(&l1, 7);
  CopyFromArray(&l1, a1, 7);

  int a2[6] = {3, 5, 7, 1, 0, 5};
  List l2;
  InitList(&l2, 6);
  CopyFromArray(&l2, a2, 6);

  if (isEqual(&l1, &l2) == 0)
    printf("Second test passed\n");
  else
    printf("Second test failed\n");
}

void test3() {
  int a1[6] = {3, 5, 7, 1, 1, 5};
  List l1;
  InitList(&l1, 6);
  CopyFromArray(&l1, a1, 6);

  int a2[6] = {3, 5, 7, 1, 0, 5};
  List l2;
  InitList(&l2, 6);
  CopyFromArray(&l2, a2, 6);

  if (isEqual(&l1, &l2) == 0)
    printf("Third test passed\n");
  else
    printf("Third test failed\n");
}

int main() {
  test1();
  test2();
  test3();

  return 0;
}
