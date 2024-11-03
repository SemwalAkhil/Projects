// 20. ENTER A STRING ARRAY FROM THE USER AND PERFORM QUICK SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxSize 100
void display(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}
int partition(char arr[], int start, int end)
{
    char pivot = arr[start];
    int ind = start, temp;
    int i = start, j = end;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < pivot)
            ind++;
    }
    temp = arr[ind];
    arr[ind] = arr[start];
    arr[start] = temp;
    while ((i < ind) && (j > ind))
    {
        if (arr[i] > pivot)
        {
            if (arr[j] < pivot)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else
                j--;
        }
        else
            i++;
    }
    return ind;
}
// The quicksort algorithm operates by selecting a pivot element from the array and partitioning the other elements into two sub-arrays: those less than the pivot and those greater than the pivot. This process is repeated recursively for the sub-arrays until they are sorted.
void quickSort(char arr[maxSize], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    else
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
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
    display(arr, size);
    start = clock();
    quickSort(arr, 0, size - 1);
    end = clock();
    display(arr, size);
    printf("Executed in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}