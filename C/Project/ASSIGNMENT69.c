/*
    69.To traverse an array — visit each element exactly once. Create an array, enter values for its
elements and then add each element and print the array.
*/
#include <stdio.h>
void traversal(int* ptr,int len){
    for (int i = 0; i < len ; i++)
    {
        printf("%d ",*ptr);
        ptr++;
    }
}
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
    traversal(list,len);
    return 0;
}