#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

// Recursive Bubble Sort
void bubbleSortRecursive(char arr[][MAX], int n) {
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++) {
        if (strcmp(arr[i], arr[i + 1]) > 0) {
            char temp[MAX];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[i + 1]);
            strcpy(arr[i + 1], temp);
        }
    }

    bubbleSortRecursive(arr, n - 1);
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
    bubbleSortRecursive(arr, n);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    printArray(arr, n);
    printf("Time taken: %f seconds\n", time_taken);

    printf("Best case complexity: O(n)\n");
    printf("Worst case complexity: O(n^2)\n");

    return 0;
}
