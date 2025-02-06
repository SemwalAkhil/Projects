// 8. SORT THE STACK IN ASCENDING ORDER USING INTEGER ARRAY.
#include <stdio.h>
#define size __INT16_MAX__

void push(int *stack, int *top, int val)
{
    stack[++(*top)] = val;
}
int pop(int *stack, int *top)
{
    return stack[(*top)--];
}
int peek(int *stack, int *top)
{
    return stack[*top];
}
void insertionSort(int arr[], int arrSize)
{
    int temp;
    int i = 0;
    for (int j = i + 1; j < arrSize; j++)
    {
        temp = arr[j];
        int k = i;
        while ((arr[k] > temp) && (k >= 0))
        {
            arr[k + 1] = arr[k];
            k--;
        }
        arr[k + 1] = temp;
        i++;
    }
}
void sort(int *stack, int *top)
{
    int arr[size];
    int i = 0;
    while ((*top) >= 0)
    {
        arr[i] = peek(stack, top);
        pop(stack, top);
        i++;
    }
    insertionSort(arr, i);
    while (i > 0)
    {
        push(stack, top, arr[i - 1]);
        i--;
    }
}
int main()
{
    int choice, num, top = -1;
    int stack[size];
    while (1)
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Sort\n5.Exit\nChoose an operation: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to push: ");
            scanf("%d", &num);
            (top < (size - 1)) ? push(stack, &top, num) : printf("Stack Full !!!\n");
            break;
        case 2:
            (top >= 0) ? printf("%d\n", pop(stack, &top)) : printf("Stack Empty !!!\n");
            break;
        case 3:
            (top >= 0) ? printf("%d\n", peek(stack, &top)) : printf("Stack Empty !!!\n");
            break;
        case 4:
            sort(stack, &top);
            printf("Stack Sorted\n");
            break;
        case 5:
            return 0;
        }
    }
}