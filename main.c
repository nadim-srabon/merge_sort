#include <stdio.h>
#include <stdlib.h>

void divide_merge(int arr[], int low, int high, int mid);
void merge(int arr[], int low, int high);

int main() {
    int arr[] = {2, 4, 6, 3, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Function to divide and merge
void divide_merge(int arr[], int low, int high, int mid) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Temporary arrays for left and right subarrays
    int left[n1], right[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    // Merge the two temporary arrays back into the original array
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left array, if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining elements of right array, if any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Recursive function to implement merge sort
void merge(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Sort the left and right halves
        merge(arr, low, mid);
        merge(arr, mid + 1, high);

        // Merge the two halves
        divide_merge(arr, low, high, mid);
    }
}
