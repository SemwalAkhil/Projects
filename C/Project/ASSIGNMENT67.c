/*
    67.Write a program which finds the largest number and its position in a list of n numbers
*/
#include <stdio.h>
void findGrt(int* ptr, int len){
    int grt= *ptr;
    int ind= 0;
    for (int i = 0; i < len; i++)
    {
        if (grt < *ptr)
        {
            grt= *ptr;
            ind=i;
        }
        ptr++;  
    }
    printf("Largest number is %d at index %d",grt,ind);
    
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
    findGrt(list,len);
    
    return 0;
}