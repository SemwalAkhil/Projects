// 11. ENTER A STRING ARRAY FROM THE USER AND PERFORM SELECTION SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#include <time.h>
#define maxSize 100
// selection sorts looks for smallest element in the sorted array
void selectionSort(char arr[], int size)
{
    char temp, min;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    start = clock();
    selectionSort(arr, size);
    end = clock();
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\nExecuted in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}