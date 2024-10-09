// 14. Enter an array from user and print all possible combinations of the elements?
// TODO
#include <stdio.h>
void getArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", arr + i);
    }
}

int main(){
    int arr[100];
    int size;
    printf("ENTER SIZE : ");
    scanf("%d", &size);
    getArr(arr,size);
    return 0;
}