#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_FILES 100 // Assuming a maximum number of files

int n; // total number of files
int k; // number of files to delete
int size[MAX_FILES]; // size of each file
bool choose[MAX_FILES]; // whether a file is chosen or not
int closestSum = INT_MAX; // variable to store the closest sum
int targetSizeMB; // target size in megabytes

void solve(int idx, int sum, int remaining) {
    if (idx == n) {
        if (remaining == 0 && abs(targetSizeMB - sum) < abs(targetSizeMB - closestSum)) {
            closestSum = sum;
            // Update any other variables to track the best solution if needed
        }
        return;
    }

    // Choose the current file
    solve(idx + 1, sum + size[idx], remaining - 1);

    // Don't choose the current file
    solve(idx + 1, sum, remaining);
}

int main() {
    // Get user input for n, k, size array, and targetSizeMB
    printf("Enter the total number of files (n): ");
    scanf("%d", &n);

    printf("Enter the number of files to delete (k): ");
    scanf("%d", &k);

    printf("Enter the size of each file:\n");
    for (int i = 0; i < n; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &size[i]);
    }

    printf("Enter the target size in megabytes: ");
    scanf("%d", &targetSizeMB);

    solve(0, 0, k);
    printf("%d", closestSum);

    // After the solve function completes, the closestSum variable will contain
    // the closest sum to the targetSizeMB. You can use the choose array to know
    // which files are selected.

    return 0;
}
