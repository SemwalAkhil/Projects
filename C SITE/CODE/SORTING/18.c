// 18. ENTER A STRING ARRAY FROM THE USER AND PERFORM MERGE SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
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
// The array is divided into two halves until each sub-array contains a single element (which is inherently sorted).
void merge(char arr1[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k;
    char *temp = (char *)calloc(sizeof(char), end - start + 1);
    for (k = 0; k <= (end - start); k++)
    {
        if ((i <= mid) && (j <= end))
        {
            if (arr1[i] <= arr1[j])
            {
                temp[k] = arr1[i++];
            }
            else
            {
                temp[k] = arr1[j++];
            }
        }
        else
        {
            if (i <= mid)
            {
                temp[k] = arr1[i++];
            }
            else
            {
                temp[k] = arr1[j++];
            }
        }
    }
    for (i = start; i <= end; i++)
    {
        arr1[i] = temp[i - start];
    }
    free(temp);
}
void mergeSort(char arr[maxSize], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    else
    {
        int mid = start + ((end - start) / 2);
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
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
    mergeSort(arr, 0, size - 1);
    end = clock();
    display(arr, size);
    printf("Executed in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}