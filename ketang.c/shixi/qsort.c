#include <stdio.h>

void swap(int *a, int *b){ // swap the variables
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *nums, int left, int right) {
    int pivot = nums[right]; // pivot = nums[9]
    int i = left - 1;  // i = -1
    for (int j = left; j <= right - 1; j++) { // j =0 ;j<=8
        if (nums[j] <= pivot) { // nums[0]<=nums[9]
            i++; // i = 0
            swap(&nums[i], &nums[j]); //nums[0] swap with nums[0]
        }
    }
    swap(&nums[i + 1], &nums[right]); // swap=nums[9] and nums[9]
    return i + 1; // return 7;
}
void quicksort(int *nums, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(nums, left, right);
        quicksort(nums, left, pivotIndex - 1);
        quicksort(nums, pivotIndex + 1, right);
    }
}

int main(void) {
    int array[10];
    int len = sizeof(array) / sizeof(int);

    for (int i = 0; i < len; i++) {
        scanf("%d", &array[i]);
    }

    quicksort(array, 0, len - 1);

    printf("Sorted array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
