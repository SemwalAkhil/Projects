/*
    97.Program to understand difference between pointer to an integer and pointer to an array of integers
*/
#include <stdio.h>
int main(){
    int len=0;
    int *ptr1,(*ptr2)[5];
    printf("Enter list size : ");
    scanf("%d",&len);
    int list[len];
    for (int i = 0; i < len; i++)
    {
        printf("Enter number :");
        scanf("%d",&list[i]);
    }
    ptr1=list;
    ptr2=&list;
    printf("*ptr1 = %d\n*ptr2 = %d\n",*ptr1,**ptr2);
    printf("ptr1 = %u\nptr2 = %u\n",ptr1,ptr2);
    ptr1++;
    ptr2++;
    printf("*ptr1++ = %d\n*ptr2++ = %d\n",*ptr1,**ptr2);
    printf("ptr1++ = %u\nptr2++ = %u\n",ptr1,ptr2);
    return 0;
}