/*
    73. To find how many of them are positive, negative and zeroes in a given list of numbers.
*/
#include <stdio.h>
void checkSign(int* ptr,int len){
    for (int i = 0; i < len ; i++)
    {
        if (*ptr == 0)
        {
            printf("Zero ");
        }
        else
        {
            if (*ptr > 0)
            {
                printf("Positive ");
            }
            else
            {
                printf("Negative ");
            }
            
        }
        
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
    checkSign(list,len);
    return 0;
}