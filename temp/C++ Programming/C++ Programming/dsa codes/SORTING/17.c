#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

// Merge function
void merge(char arr[][MAX], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    char L[n1][MAX], R[n2][MAX];

    for (int i = 0; i < n1; i++)
        strcpy(L[i], arr[l + i]);
    for (int j = 0; j < n2; j++)
        strcpy(R[j], arr[m + 1 + j]);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

// Iterative Merge Sort
void mergeSortIterative(char arr[][MAX], int n) {
    int curr_size, left_start;
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < n - 1) ? left_start + 2 * curr_size - 1 : n - 1;
            merge(arr, left_start, mid, right_end);
        }
    }
}

// Function to print string array
void printArray(char arr[][MAX], int size) {
    for (int i = 0; i < size; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    char arr[n][MAX];
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    clock_t start, end;
    double time_taken;

    start = clock();
    mergeSortIterative(arr, n);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    printArray(arr, n);
    printf("Time taken: %f seconds\n", time_taken);
    printf("Best case complexity: O(n log n)\n");
    printf("Worst case complexity: O(n log n)\n");

    return 0;
}
