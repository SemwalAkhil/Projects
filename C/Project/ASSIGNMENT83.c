/*
    83.Program to demonstrate value and original & new address of x, y, z using pointers
*/
#include <stdio.h>
int main(){
    int a,b,c;
    int *x,*y,*z;
    a = 10;
    b = 20;
    c = 30;
    x = &a;
    y = &b;
    z = &c;
    printf("*x = %d *y = %d *z = %d \n",*x,*y,*z); 
    printf("addresses x = %u y = %u z = %u \n",x,y,z);
    x = &b;
    y = &c;
    z = &a;
    printf("*x = %d *y = %d *z = %d \n",*x,*y,*z); 
    printf("addresses x = %u y = %u z = %u \n",x,y,z);
    return 0;
}