// reverse an array using pointer
#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);
    int *start = &arr[0];
    int *end = &arr[len - 1];
    int temp;
    for (; start != end; ++start, --end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
    }
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
}