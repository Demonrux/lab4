#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define ONE 1
#define ZERO 0

typedef enum {
    CORRECT_INPUT,
    INCORRECT_INPUT,
} StatusInput;

StatusInput inputArrSize(int* n) ;
int inputMas(double* arr, int n);
int findMinIndex(const double* arr, const int n);
void calculationProduct(const double* arr, const int n);

int main() {
    int n;
    StatusInput statusInput = inputArrSize(&n);
    if (statusInput == INCORRECT_INPUT) {
        printf("Incorrect Input");
    }
    else {
        double *arr = (double*)calloc(n, sizeof(double));
        if (inputMas(arr, n)) {
            calculationProduct(arr, n);
        }
        else if(inputMas(arr, n) != ONE) {
            statusInput = INCORRECT_INPUT;
            printf("Incorrect Input");
        }
        free(arr);
    }
    return statusInput;
}

int inputMas(double* arr, int n) {
    int readValues = 0;
    for (int i = 0; i < n; i++)
        readValues += scanf("%lf", arr + i);
    return n == readValues;
}

int findMinIndex(const double* arr, const int n) {
    int indexMin = 0;
    double startMin = arr[ZERO];
    for (int i = 0; i < n; i++) {
        if (arr[i] <= startMin) {
            indexMin = i;
            startMin = arr[i];
        }
    }
    return indexMin;
}

void calculationProduct(const double* arr, const int n) {
    int product = ONE;
    int countProduct = ZERO;
    int indexMin = findMinIndex(arr, n);
    for (int i = 0; i < indexMin; i++) {
        if (arr[i] < (2 * arr[indexMin])) {
            product *= arr[i];
            countProduct++;
        }
    }
    if (countProduct != ZERO)
        printf("%d", product);
    else
        printf("%d", countProduct);
}

StatusInput inputArrSize(int* n) {
    StatusInput statusInput;
    if (scanf("%d", n) != ONE || (*n == ZERO)) {
        statusInput = INCORRECT_INPUT;
    }
    else {
        statusInput = CORRECT_INPUT;
    }
    return statusInput;
}
