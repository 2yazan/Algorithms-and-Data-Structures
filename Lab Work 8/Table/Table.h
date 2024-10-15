#ifndef CODE_TABLE_H
#define CODE_TABLE_H

#include <stdbool.h>
#include "../Tree/Tree.h" // See lab work No. 7

static const short TableOk = 0;
static const short TableNotSet = 1;
static const short TableNotExistElement = 2;
static const short TableEnd = 3;
short TableError;

typedef char* T_Key;
typedef Tree Table;

// Initialize the table
void initTable(Table *T);
// Returns "true" if the table is empty, otherwise "false"
bool emptyTable(Table *T);
// Includes an element in the table, returns "true" if the element is included
// in the table, otherwise "false"
bool putTable(Table *T, BaseType Key);
// Excludes an element, returns "true" if the element with key s was
// in the table, otherwise "false"
bool getTable(Table *T, T_Key Key);
// Reads an element. Returns "true" if the element with key s is in
// the table, otherwise "false"
bool readTable(Table T, BaseType *E, T_Key Key);
// Modifies an element. Returns "true" if the element with key s
// is in the table, otherwise "false"
bool writeTable(Table *T, BaseType E, T_Key Key);
// Destroys the table
void doneTable(Table *T);

#endif // CODE_TABLE_H
