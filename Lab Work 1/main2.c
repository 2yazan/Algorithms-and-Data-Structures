// Develop and debug a program that determines the value of a variable based on its binary representation (in the lab).

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>

typedef unsigned char Byte;
typedef char Massiva[3][3];

// Convert a binary string to a byte array
Byte* GetBinary(char const *s, size_t size) {
    Byte* r = (Byte*)calloc(size, sizeof(Byte));
    for (int i = size - 1; i >= 0; i--)
        for (int j = 7; j >= 0; j--)
            r[size - i - 1] |= (s[(i << 3) + j] == '1') << (7 - j);
    return r;
}

// Print the value as a long int based on the binary string
void PrintValLongInt(char const *s) {
    size_t size = strlen(s) / 8;
    Byte *Bytes = GetBinary(s, size);
    if (size == sizeof(long int))
        printf("%d", *(long int*)Bytes);
    else
        printf("Please enter a correct type");
}

// Print the value as a float based on the binary string
void PrintValFloat(char const *s) {
    size_t size = strlen(s) / 8;
    Byte *Bytes = GetBinary(s, size);
    if (size == sizeof(float))
        printf("%.3lf", *(float *) Bytes);
    else
        printf("Please enter a correct type");
}

// Print a 3x3 matrix
void PrintMassiva(Massiva a) {
    for (size_t i = 0; i < 3; i++) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Print the value as a char matrix based on the binary string
void PrintValueMassive(char const *s) {
    size_t size = strlen(s) / 8;
    Byte *Bytes = GetBinary(s, size);
    if (size == sizeof(Massiva))
        PrintMassiva(*(Massiva*)Bytes);
    else
        printf("Please enter a correct type");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char longint[100];
    char Float[100];
    char massiva[100];

    printf("Enter the binary code to convert it to a long int:\n");
    scanf("%s", longint);
    PrintValLongInt(longint);

    printf("\nEnter the binary code to convert it to a float:\n");
    scanf("%s", Float);
    PrintValFloat(Float);

    printf("\nEnter the binary code to convert it to a char matrix:\n");
    scanf("%s", massiva);
    PrintValueMassive(massiva);

    return 0;
}
