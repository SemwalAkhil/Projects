// 16. Find Next Smaller Element
/*
Explanation -

    Given an array, print the Next Smaller Element (NSE) for every element. The NSE for an element x is the first smaller element on the right side of x in the array. Elements for which no smaller element exist (on the right side), consider NSE as -1.
    Examples:
    Input: [4, 8, 5, 2, 25]
    Output: [2, 5, 2, -1, -1]
    Explanation: The first element smaller than 4 having index > 0 is 2. The first element smaller than 8 having index > 1 is 5. The first element smaller than 5 having index > 2 is 2. There are no elements smaller than 4 having index > 3. There are no elements smaller than 4 having index > 4.
    Input: [13, 7, 6, 12]
    Output: [7, 6, -1, -1]
    Explanation: The first element smaller than 13 having index > 0 is 7. The first element smaller than 7 having index > 1 is 6. There are no elements smaller than 6 having index > 2. There are no elements smaller than 12 having index > 3.
*/
// STACK BASED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int top;
} Stack;

// Function to create a stack of given capacity
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->data = (int *)malloc(capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value)
{
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    return stack->data[stack->top--];
}

// Function to find the next smaller elements
void findNextSmallerElement(int arr[], int n)
{
    int *result = (int *)malloc(n * sizeof(int)); // Array to store the next smaller elements
    Stack *stack = createStack(n);                // Create a stack

    // Initialize result array with -1
    for (int i = 0; i < n; i++)
    {
        result[i] = -1;
    }

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
        // Check if the current element is smaller than the element at the index stored at the top of the stack
        while (!isEmpty(stack) && arr[i] < arr[stack->data[stack->top]])
        {
            int index = pop(stack);
            result[index] = arr[i]; // Update the result for the index popped
        }
        // Push the current index onto the stack
        push(stack, i);
    }

    // Print the result
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free allocated memory
    free(result);
    free(stack->data);
    free(stack);
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

    findNextSmallerElement(arr, n);

    // Free the input array
    free(arr);
    return 0;
}
