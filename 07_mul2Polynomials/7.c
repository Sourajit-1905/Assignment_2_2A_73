#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define M_PI 3.14

void fft(complex double *a, int n, int invert) {
    if (n == 1) return;

    complex double *a_even = malloc(n / 2 * sizeof(complex double));
    complex double *a_odd = malloc(n / 2 * sizeof(complex double));

    for (int i = 0; i < n / 2; i++) {
        a_even[i] = a[2 * i];
        a_odd[i] = a[2 * i + 1];
    }

    fft(a_even, n / 2, invert);
    fft(a_odd, n / 2, invert);

    double ang = 2 * M_PI / n * (invert ? -1 : 1);
    complex double w = 1;
    complex double wn = cos(ang) + sin(ang) * I;

    for (int i = 0; i < n / 2; i++) {
        complex double t = w * a_odd[i];
        a[i] = a_even[i] + t;
        a[i + n / 2] = a_even[i] - t;
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }

    free(a_even);
    free(a_odd);
}

void multiply(int *A, int *B, int n, int m) {
    int size = 1;
    while (size < n + m) size <<= 1;

    complex double *FA = calloc(size, sizeof(complex double));
    complex double *FB = calloc(size, sizeof(complex double));

    for (int i = 0; i < n; i++) FA[i] = A[i];
    for (int i = 0; i < m; i++) FB[i] = B[i];

    fft(FA, size, 0);
    fft(FB, size, 0);

    for (int i = 0; i < size; i++) FA[i] *= FB[i];

    fft(FA, size, 1);

    for (int i = 0; i < n + m - 1; i++) {
        printf("%d ", (int)(creal(FA[i]) + 0.5));
    }
    printf("\n");

    free(FA);
    free(FB);
}

int main() {
    int A[] = {2, 3, 5, 1};
    int B[] = {4, 0, 1};

    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    multiply(A, B, n, m);

    return 0;
}