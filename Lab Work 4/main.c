// Develop and programmatically implement a tool for conducting experiments to determine the time characteristics of search algorithms.

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <aclapi.h>

// Linear search
int linearSearch(const int *a, size_t len, int value) {
    int result = -1;
    for (size_t i = 0; i < len; ++i) {
        if (value == a[i]) {
            result = i;
            break;
        }
    }
    return result;
}
// Fast linear search
int fastLinearSearch(int *a, size_t len, int value) {
    a[len] = value; // I hope this doesn’t break anything
    int i = 0;
    while (value != a[i]) {
        i++;
    }
    return i == len ? -1 : i;
}
// Binary search
int binarySearch(const int *a, size_t len, int value) {
    int leftBorder = 0, rightBorder = len - 1;
    while (leftBorder <= rightBorder) {
        int currentI = (rightBorder + leftBorder) / 2;
        if (value > a[currentI])
            leftBorder = currentI + 1;
        else if (value < a[currentI])
            rightBorder = currentI - 1;
        else
            return currentI;
    }
    return -1;
}
int blockSearch(const int *a, size_t len, int value) {
    int blockLen = (int) sqrt(len);
    // Block traversal
    int currentBlock = 0;
    for (int i = blockLen; i < len - blockLen; i += blockLen) {
        if (value < a[i]) {
            currentBlock = i;
            break;
        }
    }
    // Checking the last block separately
    if (currentBlock == 0 && value <= a[len-1])
        currentBlock = len-1;
    // If a block with the element was found
    if (currentBlock) {
        // Linear search within the block
        for (int i = currentBlock - blockLen; i < currentBlock; ++i) {
            if (a[i] == value)
                return i;
        }
    } else
        return -1;
}
void printArr(int *a, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%d ", a[i]);
    } }
int main() {
    SetConsoleOutputCP(CP_UTF8);
    printf("Enter the number of elements in the array:");
    size_t len;
    scanf("%d", &len);
    int *a = (int *) malloc(len * sizeof(int));
    printf("Choose the type of array\n");
    printf("1) Ordered\n");
    printf("2) Unordered\n");
    printf("Array type:");
    size_t arrTypeCode;
    scanf("%d", &arrTypeCode);
    if (arrTypeCode == 1) {
        for (size_t i = 0; i < len; ++i) {
            a[i] = i;
        }
    } else if (arrTypeCode == 2) {
        for (size_t i = 0; i < len; ++i) {
            a[i] = rand();
        }
    } else {
        printf("Invalid array type code!");
        return 1;
    }
    printf("Choose a search algorithm:\n");
    if (arrTypeCode == 1) {
        printf("1) Fast linear search\n");
        printf("2) Binary search\n");
        printf("3) Block search\n");
    } else {
        printf("1) Linear search\n");
        printf("2) Fast linear search\n");
    }
    printf("Search algorithm number:");
    size_t searchTypeCode;
    scanf("%d", &searchTypeCode);
    char outputFlag;
    printf("Display the array (t/f)?:");
    scanf(" %c", &outputFlag);
    if (outputFlag == 't') {
        printf("Array:\n");
        printArr(a, len);
        printf("\n");
    }
    printf("Enter the element to search for:");
    int value, position;
    scanf("%d", &value);
    clock_t start;
    if (arrTypeCode == 1) {
        switch (searchTypeCode) {
            case 1:
                start = clock();
                position = fastLinearSearch(a, len, value);
                break;
            case 2:
                start = clock();
                position = binarySearch(a, len, value);
                break;
            case 3:
                start = clock();
                position = blockSearch(a, len, value);
                break;
            default:
                printf("Invalid search algorithm code!");
                return 2;
        }
    } else {
        switch (searchTypeCode) {
            case 1:
                start = clock();
                position = linearSearch(a, len, value);
                break;
            case 2:
                start = clock();
                position = fastLinearSearch(a, len, value);
                break;
            default:
                printf("Invalid search algorithm code!");
                return 2;
        }
    }
    double time = (double) (clock() - start) / CLOCKS_PER_SEC;
    if (position != -1)
        printf("Element %d found at position %d.\n", value, position);
    else
        printf("Element %d not found.\n", value);
    printf("Search time - %lf\n", time);
    free(a);
}
