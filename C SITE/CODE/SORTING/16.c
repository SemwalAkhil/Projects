// 16. ENTER A STRING ARRAY FROM THE USER AND PERFORM INSERTION SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#include <time.h>
#define maxSize 100
// Recursive function to perform insertion sort
void insertionSort(char arr[], int n)
{
    // Base case: If array has one element, return
    if (n <= 1)
        return;

    // Sort the first n-1 elements
    insertionSort(arr, n - 1);

    // Insert the last element at its correct position
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements of arr[0..n-2] that are greater than last
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main()
{
    char arr[maxSize];
    int size;
    clock_t start, end;
    printf("ENTER SIZE OF ARRAY : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ARRAY ELEMENT : ");
        fflush(stdin);
        scanf("%c", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    start = clock();
    insertionSort(arr, size);
    end = clock();
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\nExecuted in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}