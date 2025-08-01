#include <stdio.h>

#define N 3  

void rotateCounterClockwise(int mat[N][N]) {
 
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N / 2; i++) {
            int temp = mat[i][j];
            mat[i][j] = mat[N - 1 - i][j];
            mat[N - 1 - i][j] = temp;
        }
    }
}

int main() {
    int mat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    rotateCounterClockwise(mat);

    printf("\nRotated Counter-Clockwise Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}