#ifndef lab2_FORM2_H
#define lab2_FORM2_H
#include <stdio.h>
#include <malloc.h>

typedef struct {
    char *s;
    unsigned max;
} str;
typedef str *string1;
// Creates a string and returns a pointer to the string
string1 CreateStr();
// Allocates dynamic memory for the string st, containing from 0 to n characters.
void InitStr(string1 st, unsigned n);
/* Writes data to the string st from the string s.
 The string s ends with a null character '\0' */
void writeToStr(string1 st, char *s);
/* Writes data to the string s from the string st.
 The string s ends with a null character '\0' */
void writeFromStr(char *s, string1 st);
// Input the string s from the keyboard
void inputStr(string1 s);
// Outputs the string st to the monitor screen
void outputStr(string1 st);
/* Compares the strings s1 and s2. Returns 0 if s1 = s2, 1 if s1 > s2,
 and -1 if s1 < s2. */
int comp(string1 s1, string1 s2);
// Deletes count characters from the string s, starting at position index
void delete(string1 s, unsigned index, unsigned count);
// Inserts the substring subs into the string s starting from position index
void insert(string1 subs, string1 s, unsigned index);
// Performs concatenation of strings s1 and s2. The result is placed in srez.
void Concat(string1 s1, string1 s2, string1 srez);
// Writes count characters to the string subs from the string s, starting from position index
void copy(string1 s, unsigned index, unsigned count, string1 subs);
// Returns the current length of the string s
unsigned length(string1 s);
// Returns the position from which the substring subs is located in the string s,
// or -1 if s does not contain subs
unsigned pos(string1 subs, string1 s);
#endif //lab2_FORM2_H
