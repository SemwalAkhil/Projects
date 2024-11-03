// todo
// 9. ENTER A INTEGER ARRAY FROM THE USER AND PERFORM QUICK SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxSize 100
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// The quicksort algorithm operates by selecting a pivot element from the array and partitioning the other elements into two sub-arrays: those less than the pivot and those greater than the pivot. This process is repeated recursively for the sub-arrays until they are sorted.
void quickSort(int arr[maxSize], int size)
{
    int i = 0, j = size - 1, k = 1;
    int pivot = arr[i];
    int temp;
    // while (/* condition */)
    // {
    //     if (arr[i + k] < arr[i])
    //     {
    //         temp = arr[i + k];
    //         arr[i + k] = arr[i];
    //         arr[i] = temp;
    //         if (arr[j] < arr[i])
    //         {
    //             temp = arr[j];
    //             arr[j] = arr[i];
    //             arr[i] = temp;
    //         }
    //     }
    //     else
    //     {
    //         k++;
    //     }
    // }
}
int main()
{
    int arr[maxSize];
    int size;
    clock_t start, end;
    printf("ENTER SIZE OF ARRAY : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ARRAY ELEMENT : ");
        scanf("%d", &arr[i]);
    }
    display(arr, size);
    start = clock();
    quickSort(arr, size);
    end = clock();
    display(arr, size);
    printf("Executed in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}