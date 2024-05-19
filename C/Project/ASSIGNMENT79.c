/*
    79.Program to demonstrate call by value by passing array elements to a function
*/
#include <stdio.h>
void display(int m){
    printf("%d ",m);
}
int main(){
    int arr[]={1,2,3,4,5,6};
    for (int i = 0; i < 6; i++)
    {
        display(arr[i]);
    }
    
    return 0;
}