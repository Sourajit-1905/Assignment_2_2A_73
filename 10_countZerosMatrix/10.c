#include <stdio.h>

int countZeroes(int A[][100], int N) {
    int row = 0, col = N - 1, count = 0;

    while (row < N && col >= 0) {
        if (A[row][col] == 0) {
            count += col + 1;
            row++;
        } else {
            col--;
        }
    }

    return count;
}

int main() {
    int matrix[3][100] = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 1}
    };
    int N = 3;

    int result = countZeroes(matrix, N);
    printf("Number of zeroes: %d\n", result);  

    return 0;
}