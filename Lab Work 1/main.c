// Develop and debug a program that outputs a binary representation of the values ​​specified by the SD (in the lab)

#include <stdio.h>

void PrintByte(unsigned char n){
    unsigned char i = 1 << 7;
    while (i) {
        (i & n) ? printf("1") : printf("0");
        i >>= 1;
    }
}

void PrintVar(void *varPtr, size_t size){
    for (int i = size - 1; i >= 0; i--)
        PrintByte(*((unsigned char *) varPtr + i));
}

int main(){
    long int A =-8;
    float B = 10.5;
    char C[3][3]= {{0,0,0},{0,0,0},{0,0,0}};
    printf("long int A = ");
    PrintVar(&A,sizeof(long int));
    printf("\nfloat B = ");
    PrintVar(&B,sizeof(float));
    printf("\nchar[3][3] C = ");
    PrintVar(C,sizeof(C));
    return 0;
}
