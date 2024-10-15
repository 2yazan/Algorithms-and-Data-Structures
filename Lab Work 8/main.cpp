//The text file contains text in the Russian language. The text may contain numbers written in word form.
//  Convert the file by replacing the word representation of numbers with their numerical representation.

#include <stdio.h>
#include <windows.h>
#include "Table/Table.h"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  // Saving elements for the table from a file
  element arrayOfElements[256];
  unsigned amountElementsForTable = 0;
  char filename[] = "Keys_and_values_for_Table.txt";
  FILE *f = fopen(filename, "r"); // Opening the file
  // Writing from the file to the array of elements
  while (fscanf(f, "%s %u",
                arrayOfElements[amountElementsForTable].data.key,
                &arrayOfElements[amountElementsForTable].data.s) != EOF) {
    amountElementsForTable++;
  }
  fclose(f);
  // Initializing the table
  Table table;
  initTable(&table);
  // Filling the table with elements
  for (int i = 0; i < amountElementsForTable; i++) {
    putTable(&table, &arrayOfElements[i]);
  }
  // Processing the text for the assignment
  char exerciseFile[] = "Text_for_exercise_ASD.txt";
  FILE *exercise = fopen(exerciseFile, "r");
  char s[256];
  BaseType convertNumbersArray[30];
  unsigned i = 0;
  unsigned counter = 0;
  // Loop until the end of the file
  while (!feof(exercise)) {
    // Reading one word at a time
    fscanf(exercise, "%s", s);
    // If a number is found, get it from the table by key
    if (readTable(table, &convertNumbersArray[i], s)) {
      // Sum the found numbers into one total
      counter += convertNumbersArray[i]->data.s; // Sum and remember
      i++;
    } else { // If the word is not a number
      if (counter != 0) { // If something was counted
        printf("%d ", counter); // Output the sum of the found numbers in numeric equivalent
        counter = 0;
      }
      printf("%s ", s); // Output the word
    }
  }
  return 0;
}
