// 14. Enter an array from user and print all possible combinations of the elements?
#include <stdio.h>

void printCombination(int arr[], int data[], int start, int end, int index, int r)
{
    // If current combination is ready to be printed
    if (index == r)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", data[j]);
        }
        printf("\n");
        return;
    }

    // Replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        printCombination(arr, data, i + 1, end, index + 1, r);
    }
}

void printAllCombinations(int arr[], int n)
{
    // Print combinations of all sizes from 1 to n
    for (int r = 1; r <= n; r++)
    {
        int data[r]; // temporary array to store current combination
        printCombination(arr, data, 0, n - 1, 0, r);
        printf("\n"); // add space between combinations of different sizes
    }
}

int main()
{
    int n;

    // Get array size from user
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Get array elements from user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nAll possible combinations:\n");
    printAllCombinations(arr, n);

    return 0;
}