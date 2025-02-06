#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

// Partition function for Quick Sort
int partition(char arr[][MAX], int low, int high) {
    char pivot[MAX];
    strcpy(pivot, arr[high]);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char temp[MAX];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }

    char temp[MAX];
    strcpy(temp, arr[i + 1]);
    strcpy(arr[i + 1], arr[high]);
    strcpy(arr[high], temp);

    return (i + 1);
}

// Recursive Quick Sort
void quickSortRecursive(char arr[][MAX], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
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
    quickSortRecursive(arr, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    printArray(arr, n);
    printf("Time taken: %f seconds\n", time_taken);
    printf("Best case complexity: O(n log n)\n");
    printf("Worst case complexity: O(n^2)\n");

    return 0;
}
