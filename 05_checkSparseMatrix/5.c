#include <stdio.h>
#define MAX 100

int isSparseMatrix(int array[][MAX], int m, int n) {
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] == 0) {
                count++;
            }
        }
    }

    return (count > (m * n) / 2);
}

int main() {
    int array[3][MAX] = {
        {1, 0, 3},
        {0, 0, 4},
        {6, 0, 0}
    };
    int m = 3, n = 3;

    if (isSparseMatrix(array, m, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}