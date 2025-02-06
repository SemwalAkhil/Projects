#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Helper function to print the array
void printArrayS(int arr[], int start, int size)
{
    for (int i = start; i <= size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Partition function to choose a pivot and partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the pivot as the last element
    int i = low - 1;       // Index of the smaller element

    printf("partition %d & %d\n", low, high);
    for (int j = low; j <= high - 1; j++)
    {
        printf("Array: (arr[%d] = %d, arr[%d] = %d, pivot = %d)\n", i, arr[i], j, arr[j], pivot);
        printArrayS(arr, low, high);
        // If the current element is smaller than the pivot, swap
        if (arr[j] < pivot)
        {
            i++;
            printf("%d < %d swapped %d & %d\n", arr[j], pivot, arr[i], arr[j]);
            swap(&arr[i], &arr[j]);
        }
    }
    printf("swapped %d & %d\n", arr[i + 1], arr[high]);
    swap(&arr[i + 1], &arr[high]); // Swap the pivot to the correct position
    printf("Array:\n");
    printArrayS(arr, low, high);
    return i + 1; // Return the partition index
}

// Iterative function to implement Quick Sort using a stack
void quickSortIterative(int arr[], int low, int high)
{
    // Create a stack to simulate the recursive calls
    int *stack = (int *)malloc(sizeof(int) * (high - low + 1));
    int top = -1;

    // Push initial range of the array
    stack[++top] = low;
    stack[++top] = high;

    // Continue until the stack is empty
    while (top >= 0)
    {
        // Pop the top two elements, low and high
        high = stack[top--];
        low = stack[top--];

        // Partition the array
        int pi = partition(arr, low, high);

        // If there are elements to the left of the pivot, push them onto the stack
        if (pi - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pi - 1;
            printf("Stack:\n");
            printArray(stack, top + 1);
        }

        // If there are elements to the right of the pivot, push them onto the stack
        if (pi + 1 < high)
        {
            stack[++top] = pi + 1;
            stack[++top] = high;
            printf("Stack:\n");
            printArray(stack, top + 1);
        }
    }

    free(stack); // Free the dynamically allocated memory for the stack
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    quickSortIterative(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
