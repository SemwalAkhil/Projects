// 4. ENTER A INTEGER ARRAY FROM THE USER AND PERFORM BUBBLE SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#include <time.h>
#define maxSize 100
// swaps the adjacent elements
void bubbleSort(int arr[], int size, int i, int j)
{
    if (i < size)
    {
        if (j < (size - i - 1))
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            bubbleSort(arr, size, i, j + 1);
        }
        bubbleSort(arr, size, i + 1, 0);
    }
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
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    start = clock();
    bubbleSort(arr, size, 0, 0);
    end = clock();
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nExecuted in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}