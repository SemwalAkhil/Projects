// 19. ENTER A STRING ARRAY FROM THE USER AND PERFORM QUICK SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#include <time.h>
#define maxSize 100
// Function to swap two elements
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(char arr[], int low, int high)
{
    char pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Iterative QuickSort function
void quickSort(char arr[], int n)
{
    char stack[n];
    int top = -1;

    // Initialize stack with initial values
    stack[++top] = 0;
    stack[++top] = n - 1;

    // Keep popping elements from the stack until it's empty
    while (top >= 0)
    {
        char high = stack[top--];
        char low = stack[top--];

        int pivot = partition(arr, low, high);

        // If there are elements on the left side of the pivot, push left side to stack
        if (pivot - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pivot - 1;
        }

        // If there are elements on the right side of the pivot, push right side to stack
        if (pivot + 1 < high)
        {
            stack[++top] = pivot + 1;
            stack[++top] = high;
        }
    }
}

// Function to print an array
void display(char arr[], int size)
{
    for (char i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
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
    quickSort(arr, size);
    end = clock();
    display(arr, size);
    printf("Executed in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}