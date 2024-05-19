/*
    77. Write a program to search a given number from a list of n numbers. Also, print its location detail.
*/
#include <stdio.h>
void search(int* ptr, int len, int ele){
    for (int i = 0; i < len; i++)
    {
        if (*ptr == ele)
        {
            printf("%d at index %d ",*ptr,i);
            break;
        }
        ptr++;
    }
    
    
}
int main(){
    int len=0;
    int ele=0;
    printf("Enter list size : ");
    scanf("%d",&len);
    int list[len];
    for (int i = 0; i < len; i++)
    {
        printf("Enter number :");
        scanf("%d",&list[i]);
    }
    
    printf("Enter number to be searched : ");
    scanf("%d",&ele);
    search(list,len,ele);
    return 0;
}