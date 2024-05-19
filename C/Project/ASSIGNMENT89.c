/*
    89.Program to find the value and address of elements using arrays with for loop
*/
#include <stdio.h>
int main(){
    int len=0;
    printf("Enter list size : ");
    scanf("%d",&len);
    int list[len];
    int *ptr = &list[0];
    for (int i = 0; i < len; i++)
    {
        printf("Enter number :");
        scanf("%d",&list[i]);
    }
    for (int i = 0; i < len ; i++)
    {
        printf("%d at index %d and address %u\n",list[i],i,ptr);
        ptr++;
    }
    return 0;
}