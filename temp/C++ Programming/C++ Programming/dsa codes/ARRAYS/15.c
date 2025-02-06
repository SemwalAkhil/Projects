// 15. Enter an array from user and print all the palindrome numbers?
#include <stdio.h>
int palindrome(int num)
{
    int temp = num;
    int res = 0;
    while (temp > 0)
    {
        res = (res * 10) + (temp % 10);
        temp /= 10;
    }
    return (res == num) ? 1 : 0;
}
void getArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", arr + i);
    }
}
int main()
{
    int arr[100];
    int size;
    printf("ENTER SIZE OF ARRAY : ");
    scanf("%d", &size);
    getArr(arr, size);
    for (int i = 0; i < size; i++)
    {
        if (palindrome(arr[i]))
        {
            printf("%d is palindrome\n", arr[i]);
        }
    }

    return 0;
}