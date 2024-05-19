/*
    95.Program to print the array elements using for loop
*/
#include <stdio.h>
int main(){
    int len=0;
    printf("Enter list size : ");
    scanf("%d",&len);
    int list[len];
    for (int i = 0; i < len; i++)
    {
        printf("Enter number :");
        scanf("%d",&list[i]);
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ",list[i]);
    }
    return 0;
}