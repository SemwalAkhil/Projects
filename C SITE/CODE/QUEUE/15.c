// 15. Find the Next Greater Element
/*
Explanation -
    Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element. If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.
    Example 1:
    Input: N = 4, arr[] = [1 3 2 4]
    Output: 3 4 4 -1
    Explanation: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist, it is -1.
    Example 2:
    Input: N = 5, arr[] [6 8 0 1 3]
    Output: 8 -1 1 3 -1
    Explanation: In the array, the next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.
*/
#include <stdio.h>
#include <stdlib.h>

// STACK BASED APPROACH
void findNextGreaterElement(int arr[], int n)
{
    int *result = (int *)malloc(n * sizeof(int)); // Array to store the next greater elements
    int *stack = (int *)malloc(n * sizeof(int));  // Stack to store indices
    int top = -1;                                 // Stack pointer

    // Initialize result array with -1
    for (int i = 0; i < n; i++)
    {
        result[i] = -1;
    }

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
        // Check if the current element is greater than the element at the index stored in stack
        while (top != -1 && arr[i] > arr[stack[top]])
        {
            result[stack[top]] = arr[i]; // Update the result for the index popped from the stack
            top--;                       // Pop the index from the stack
        }
        // Push current index onto the stack
        stack[++top] = i;
    }

    // Free the stack
    free(stack);

    // Print the result
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the result array
    free(result);
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    findNextGreaterElement(arr, n);

    // Free the input array
    free(arr);
    return 0;
}
