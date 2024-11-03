// 12. ENTER A STRING ARRAY FROM THE USER AND PERFORM SELECTION SORT ALGORITHM THROUGH RECURSION.ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#include <time.h>
#define maxSize 100
// selection sorts looks for smallest element in the sorted array
void selectionSort(char arr[], int size, int i, int j, int min)
{
    if (i < (size - 1))
    {
        if (j == size)
        {
            char temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            i++;
            min = i;
            j = min + 1;
        }
        if (arr[j] < arr[min])
        {
            selectionSort(arr, size, i, j + 1, j);
        }
        else
        {
            selectionSort(arr, size, i, j + 1, min);
        }
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
    selectionSort(arr, size, 0, 1, 0);
    end = clock();
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\nExecuted in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}