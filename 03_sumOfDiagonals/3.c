
#include<stdio.h>

#define N 3

int sumDiagonal(int n, int M[][N]) {
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += M[i][i];
    }
    
    return sum;
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = sumDiagonal(N, matrix);
    printf("Sum of main diagonal: %d\n", result);

    return 0;
}
