// 13. ENTER A STRING ARRAY FROM THE USER AND PERFORM BUBBLE SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#include <time.h>
#define maxSize 100
// swaps the adjacent elements
void bubbleSort(char arr[], int size)
{
    char temp;
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < (size - j - 1); i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
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
    bubbleSort(arr, size);
    end = clock();
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\nExecuted in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}