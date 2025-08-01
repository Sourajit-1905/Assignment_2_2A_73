#include <stdio.h>

#define SIZE 3

int checkIdentity(int mat[SIZE][SIZE], int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (row == col && mat[row][col] != 1)
                return 0;
            else if (row != col && mat[row][col] != 0)
                return 0;
        }
    }
    return 1;
}

int main() {
    int matrix[SIZE][SIZE] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    if (checkIdentity(matrix, SIZE))
        printf("Valid Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}