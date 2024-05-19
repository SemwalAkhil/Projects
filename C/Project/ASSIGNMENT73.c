/*
    73. Write a program demonstrating deletion of an element from array
*/
#include <stdio.h>
void deletion(int* ptr,int* len,int ele){
    for (int i = 0; i < *len ; i++)
    {
        if (*ptr == ele)
        {
            for (int j = 0; j < *len-i; j++)
            {
                *ptr = *ptr + 1;
                ptr++;
            }
            break;
        }
        
        ptr++;
    }
    (*len)--;
}
void traversal(int* ptr,int len){
    for (int i = 0; i < len ; i++)
    {
        printf("%d ",*ptr);
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
    traversal(list,len);
    printf("Enter number to be deleted : ");
    scanf("%d",&ele);
    deletion(list,&len,ele);
    traversal(list,len);
    return 0;
}