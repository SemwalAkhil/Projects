/*
    87.Program demonstrating comparison of two pointer variables
*/
#include <stdio.h>
int main(){
    int arr[] = {1,4,3,4,5,6,7,8};
    int *ptr1 = &arr[1];
    int *ptr2 = &arr[3];
    int *ptr3 = &arr[3];
    printf("*ptr1 = %d *ptr2 = %d *ptr3 = %d\n",*ptr1,*ptr2,*ptr3);
    printf("ptr1 == ptr2 = %d\n",ptr1==ptr2);
    printf("ptr3 == ptr2 = %d\n",ptr3==ptr2);
    printf("ptr1 != ptr2 = %d\n",ptr1!=ptr2);
    printf("ptr3 != ptr2 = %d\n",ptr3!=ptr2);
    printf("ptr1 < ptr2 = %d\n",ptr1<ptr2);
    printf("ptr3 < ptr2 = %d\n",ptr3<ptr2);
    printf("ptr1 > ptr2 = %d\n",ptr1>ptr2);
    printf("ptr3 > ptr2 = %d\n",ptr3>ptr2);
    return 0;
}
