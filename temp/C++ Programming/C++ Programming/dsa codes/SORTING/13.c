#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

// Iterative Bubble Sort
void bubbleSortIterative(char arr[][MAX], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[MAX];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
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
    bubbleSortIterative(arr, n);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    printArray(arr, n);
    printf("Time taken: %f seconds\n", time_taken);

    printf("Best case complexity: O(n)\n");
    printf("Worst case complexity: O(n^2)\n");

    return 0;
}
