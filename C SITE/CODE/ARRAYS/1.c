// 1. Enter an array from user and display all the value ?
#include <stdio.h>
int main()
{
    int arr[100];
    int size;
    printf("ENTER SIZE : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}