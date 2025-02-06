#include <stdio.h>
#include <stdlib.h>

void nextGreater(int arr[], int n) {
    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = -1; // Default value
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
}

int main() {
    int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n);

    int arr2[] = {6, 8, 0, 1, 3};
    n = sizeof(arr2) / sizeof(arr2[0]);
    nextGreater(arr2, n);

    return 0;
}
