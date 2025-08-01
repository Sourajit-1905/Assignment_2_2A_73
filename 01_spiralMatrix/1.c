#include <stdio.h>

void spirallyTraverse(int rows, int cols, int mat[rows][cols]) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++) {
            printf("%d ", mat[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            printf("%d ", mat[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", mat[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", mat[i][left]);
            }
            left++;
        }
    }
}

int main() {
    int mat[4][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15,16}
    };

    int rows = 4, cols = 4;

    printf("Spiral Traversal of the matrix:\n");
    spirallyTraverse(rows, cols, mat);

    return 0;
}