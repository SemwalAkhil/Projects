// TODO
// 7. ENTER A INTEGER ARRAY FROM THE USER AND PERFORM MERGE SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#define maxSize 100
// The array is divided into two halves until each sub-array contains a single element (which is inherently sorted).
void mergeSort(int arr[], int size)
{
    int low = 0, len = 1;
    do
    {
        for (int i = 0; i < size; i += len)
        {
            /* code */
        }

    } while (size > len);
}
int main()
{
    int arr[maxSize];
    int size;
    printf("ENTER SIZE OF ARRAY : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ARRAY ELEMENT : ");
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    mergeSort(arr, size);
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}