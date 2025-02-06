#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

// Iterative Insertion Sort
void insertionSortIterative(char arr[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        char key[MAX];
        strcpy(key, arr[i]);
        int j = i - 1;

        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);
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
    insertionSortIterative(arr, n);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    printArray(arr, n);
    printf("Time taken: %f seconds\n", time_taken);
    printf("Best case complexity: O(n)\n");
    printf("Worst case complexity: O(n^2)\n");

    return 0;
}
