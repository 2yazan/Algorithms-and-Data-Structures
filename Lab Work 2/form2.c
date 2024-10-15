#include "FORM2.h"

string1 CreateStr(){
    return (string1)malloc(sizeof(str));
}
void writeToStr(string1 st, char *s){
    st->max = 0;
    while (*s){
        st->s[st->max++] = *(s++);
    }
}
void writeFromStr(char *s, string1 st){
    unsigned i;
    for (i = 0; i < st->max; ++i) {
        s[i] = st->s[i];
    }
    s[++i] = '\0';
}
void inputStr(string1 s){
    unsigned len = 0;
    char c;
    while ((c = getchar()) != '\n')
        s->s[len++] = c;
    s->max = len;
}
void outputStr(string1 st){
    for (unsigned i = 0; i < st->max; i++)
        putchar(st->s[i]);
}
int comp(string1 s1, string1 s2){
    unsigned i = 0;
    while (s1->s[i] == s2->s[i]){
        if (s1->s[i] == '\0')
            return 0;
        i++;
    }
    return s1->s[i] - s2->s[i];
}
void copy(string1 s, unsigned index, unsigned count, string1 subs){
    int i;
    for (i = 0; i < count; ++i) {
        subs->s[i] = s->s[index+i];
    }
    subs->s[i] = '\0';
}
unsigned length(string1 s){
    return s->max;
}
unsigned pos(string1 subs, string1 s){
    unsigned i = 0;
    if (subs->max > s->max)
        return -1;
    while (s->s[i] != subs->s[0] && s->s[i])
        i++;
    int result = (int)i;
    for (int j = 0; j < subs->max; ++j, ++i) {
        if (subs->s[j] != s->s[i])
            return -1;
    }
    return result;
}
void delete(string1 s, unsigned index, unsigned count){
    for (int i = count + index; i < s->max; i++){
        s->s[i - count] = s->s[i];
    }
    s->max -= count;
}
void insert(string1 subs, string1 s, unsigned index){
    string1 end = CreateStr();
    writeToStr(end, &(s->s[index]));
    for (int i = 0; i < subs->max; ++i) {
        s->s[index + i] = subs->s[i];
    }
    s->max += subs->max;
    for (int i = index + subs->max, j = 0; i < s->max && j < end->max; i++, j++)
        s->s[i] = end->s[j];
}
void Concat(string1 s1, string1 s2, string1 srez){
    for (int i = 0; i<s1->max; i++){
        srez->s[i] = s1->s[i];
    }
    int i = s1->max;
    for (int j = 0; j<s2->max; j++){
        srez->s[j+i] = s2->s[j];
    }
    srez ->max = s1->max + s2->max;
    srez->s[srez->max] = '\0';
}
