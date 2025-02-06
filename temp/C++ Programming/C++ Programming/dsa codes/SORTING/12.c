#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

// Recursive Selection Sort
void selectionSortRecursive(char arr[][MAX], int n, int index) {
    if (index == n)
        return;

    int min_idx = index;
    for (int j = index + 1; j < n; j++) {
        if (strcmp(arr[j], arr[min_idx]) < 0)
            min_idx = j;
    }
    if (min_idx != index) {
        char temp[MAX];
        strcpy(temp, arr[index]);
        strcpy(arr[index], arr[min_idx]);
        strcpy(arr[min_idx], temp);
    }

    selectionSortRecursive(arr, n, index + 1);
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
    selectionSortRecursive(arr, n, 0);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    printArray(arr, n);
    printf("Time taken: %f seconds\n", time_taken);

    printf("Best case complexity: O(n^2)\n");
    printf("Worst case complexity: O(n^2)\n");

    return 0;
}
