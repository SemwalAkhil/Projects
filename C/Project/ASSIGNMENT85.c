/*
    85.Program for Subtraction of a number from a pointer
*/
#include <stdio.h>
int main(){
    int a = 10;
    int *x = &a;
    printf("Address of %d is %d \n",a,x);
    printf("Address of %d - 1 = %u",a,x-1);
    return 0;
}