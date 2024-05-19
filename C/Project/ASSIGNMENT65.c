/*
    67.Write a program which reads a list of 10 numbers and prints the list in reverse order
*/
#include <stdio.h>
void listReverse(int* ptr,int len){
    for (int i = len; i > 0; i--)
    {
        printf("%d ",*ptr);
        ptr--;
    }
    
}
int main(){
    int list[10];
    for (int i = 0; i < 10; i++)
    {
        printf("ENTER THE NUMBER :");
        scanf("%d",&list[i]);
    }
    listReverse(&list[9],10);
    return 0;
}