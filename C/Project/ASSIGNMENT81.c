/*
    81.Program to demonstrate pointers address and value.
*/
#include <stdio.h>
int main(){
    int a=10;
    long int* i=&a;
    printf("%d is at %ld \n",a,i);
    printf("%d is at %ld \n",*i,&a);
    return 0;
}