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

// Array to store selected files
bool selectedFiles[MAX_FILES];

void solve(int idx, int sum, int remaining) {
    if (idx == n) {
        if (remaining == 0 && abs(targetSizeMB - sum) < abs(targetSizeMB - closestSum)) {
            closestSum = sum;
            // Update any other variables to track the best solution if needed
            // Copy the current selection to the selectedFiles array
            for (int i = 0; i < n; i++) {
                selectedFiles[i] = choose[i];
            }
        }
        return;
    }

    // Choose the current file
    choose[idx] = true;
    solve(idx + 1, sum + size[idx], remaining - 1);
    closestSum=INT_MAX;
    // Don't choose the current file
    choose[idx] = false;
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

    // Display the chosen files
    printf("Chosen files: ");
    for (int i = 0; i < n; i++) {
        if (selectedFiles[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    // After the solve function completes, the closestSum variable will contain
    // the closest sum to the targetSizeMB. You can use the selectedFiles array
    // to know which files are selected.

    return 0;
}
