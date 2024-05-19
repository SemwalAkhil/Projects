/*
    127.Demonstration of malloc, realloc, free
*/
#include <stdio.h>
#include <stdlib.h>
int main(){

    // malloc
    int *ptr1 = (int*)malloc(4*(sizeof(int)));

    for (int i = 0; i < 3; i++)
    {
        *(ptr1+i) = i;      // empty value -> garbage value

    }

    for (int i = 0; i < 8; i++)
    {
        printf("%d ",*(ptr1+i));    
    }

    printf("\n");
    
    // realloc
    ptr1 = (int*)realloc(ptr1,8*sizeof(int));

    for (int i = 3; i < 8; i++)
    {
        *(ptr1+i) = i;

    }
    printf("\n");
    
    for (int i = 0; i < 8; i++)
    {
        printf("%d ",*(ptr1+i));
    }
    

    // free
    free(ptr1); // free pointer -> accessing may lead to undefined behaviour
    

    return 0;
}