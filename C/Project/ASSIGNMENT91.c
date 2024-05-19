/*
    91.Demonstration of passing an entire array to a function
*/
#include <stdio.h>
void display(int arr[], int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
int main(){
    int arr[] = {1,2,3,4,5};
    display(arr,5);
    return 0;
}