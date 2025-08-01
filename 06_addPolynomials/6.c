#include <stdio.h>
#define MAX 100

void combinePolynomials(int P1[], int len1, int P2[], int len2, int result[]) {
    int size = (len1 > len2) ? len1 : len2;

    for (int i = 0; i < size; i++) {
        result[i] = (i < len1) ? P1[i] : 0;
    }

    for (int i = 0; i < len2; i++) {
        result[i] += P2[i];
    }
}

void displayPolynomial(int poly[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", poly[i]);
        if (i != 0) {
            printf("x^%d", i);
        }
        if (i != length - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int P1[] = {3, 7, 2, 5};      
    int P2[] = {6, 1, 8};    
    int result[MAX];

    int len1 = sizeof(P1) / sizeof(P1[0]);
    int len2 = sizeof(P2) / sizeof(P2[0]);
    int finalLen = (len1 > len2) ? len1 : len2;

    printf("Polynomial A:\n");
    displayPolynomial(P1, len1);

    printf("Polynomial B:\n");
    displayPolynomial(P2, len2);

    combinePolynomials(P1, len1, P2, len2, result);

    printf("Resultant Polynomial:\n");
    displayPolynomial(result, finalLen);

    return 0;
}