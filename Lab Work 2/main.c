// Output string s to the monitor screen.

#include "FORM2.c"
#include <windows.h>

void words(string1 s) {
    unsigned i = 0, words = 0, count = 0;
    // Skip leading spaces
    while (s->s[i] == ' ' && s->s[i] != '\0')
        i++;
    words = 0;
    // Count the words in the string
    while (s->s[i] != '\0') {
        if (s->s[i] != ' ' && words == 0) {
            words = 1;
            count++;
        }
        else if (s->s[i] == ' ')
            words = 0;
        i++;
    }
    printf("There are %d words in the string", count);
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    printf("Enter a string:");
    string1 s = CreateStr();
    inputStr(s);
    words(s);
    free(s);
}
