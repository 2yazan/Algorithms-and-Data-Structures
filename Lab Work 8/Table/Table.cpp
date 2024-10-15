#include "Table.h"
#include <cstdio>
#include <cstdlib>

void initTable(Table *T) {
  initTree(T);
}

// Returns "true" if the table is empty, otherwise "false"
bool emptyTable(Table *T) {
  return T == NULL;
}

// Writing data
void _putTable(Table *T, BaseType E) {
  // Check if there are elements
  if (*T == NULL) {
    *T = createRoot(E);
    TableError = TreeError;
  } else { // If there were elements, need to reassign pointers
    if (strcmp_((*T)->data.key, E->data.key) > 0) {
      _putTable(&(*T)->leftSon, E);
    } else if (strcmp_((*T)->data.key, E->data.key) < 0) {
      _putTable(&(*T)->rightSon, E);
    } else { // If an identical element is found, set the corresponding error variable
      TableError = TableNotSet;
    }
  }
}

// Includes an element in the table, returns "true" if the element is included in the table, otherwise "false"
bool putTable(Table *T, BaseType E) {
  if (emptyTable(*T)) { // If the table is empty, need to create the root of the tree first
    *T = createRoot(E);
    TableError = TreeError;
  } else { // Otherwise, use the function to write to the tree
    _putTable(T, E); // Inside this function, universality is checked
  }
  return TableError == TableOk;
}

// Removes an element with key Key from the tree
void _getTable(Tree *T, T_Key Key) {
  if (*T == NULL) {
    TreeError = TreeEnd;
  }
  if (strcmp_(Key, (*T)->data.key) < 0) { // If the element to be deleted is less than the current one
    _getTable(&(*T)->leftSon, Key);
  } else if (strcmp_(Key, (*T)->data.key) > 0) { // If the element to be deleted is greater than the current one
    _getTable(&(*T)->rightSon, Key);
  } else if (strcmp_(Key, (*T)->data.key) == 0) { // If the element to be deleted is the current one
    if ((*T)->leftSon == NULL) { // If there is no left child
      Tree tmp = *T;
      *T = (*T)->rightSon;
      free(tmp);
    } else if ((*T)->rightSon == NULL) { // If there is no right child
      Tree tmp = *T;
      *T = (*T)->leftSon;
      free(tmp);
    } else { // If both children exist
      Tree tmp = (*T)->rightSon;
      Tree prev = (*T);
      while (tmp->leftSon) {
        prev = tmp;
        tmp = tmp->leftSon;
      }
      (*T)->data = tmp->data;
      if (prev != *T) {
        prev->leftSon = NULL;
      } else {
        prev->rightSon = tmp->rightSon;
      }
      TableError = TableOk;
      free(tmp);
    }
  } else { // If such an element does not exist
    TableError = TableNotExistElement;
  }
}

// Excludes an element, returns "true" if the element with key s was in the table, otherwise "false"
bool getTable(Table *T, T_Key Key) {
  _getTable(T, Key);
  return TableError == TableOk;
}

// Reads data of the element with key s
Tree _readDataTable(Tree T, T_Key Key) {
  if (T == NULL) {
    TableError = TableNotExistElement;
    return T;
  } else if (strcmp_(Key, (*T).data.key) == 0) {
    TableError = TableOk;
    return T;
  }
  if (strcmp_(Key, (*T).data.key) < 0) {
    // If the element is less than the current one, go to the left subtree
    return _readDataTable(T->leftSon, Key);
  } else if (strcmp_(Key, (*T).data.key) > 0) { // Otherwise, go to the right subtree
    return _readDataTable(T->rightSon, Key);
  } else { // There is no such element at all
    TableError = TableNotExistElement;
    return NULL;
  }
}

// Reads an element. Returns "true" if the element with key s is in the table, otherwise "false"
bool readTable(Table T, BaseType *E, T_Key Key) {
  *E = _readDataTable(T, Key);
  return TableError == TableOk;
}

// Modifies an element. Returns "true" if the element with key s is in the table, otherwise "false"
bool writeTable(Table *T, BaseType E, T_Key Key) {
  BaseType tmp;
  if (readTable(T, &tmp, Key)) { // If the element exists
    tmp = E; // Overwrite the necessary value in the found element
    TableError = TableOk;
  } else {
    TableError = TableNotExistElement;
  }
  return TableError == TableOk;
}

// Destroys the table
void doneTable(Table *T) {
  delTree(*T);
}
