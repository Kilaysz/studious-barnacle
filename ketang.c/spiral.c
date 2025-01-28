#include <stdio.h>

void SpiralMatrix(int n, int (*matrix)[n]) {
    int value = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = value++;
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = value++;
        }
        right--;

        // Traverse from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }

        // Traverse from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }
}

int main() {
    int n;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = -1;

    SpiralMatrix(n, matrix);

    printf("Spiral Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
