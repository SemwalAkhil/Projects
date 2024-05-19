/*
    79. Find the largest and smallest element of a matrix
*/
#include <stdio.h>
void largeSmall(int* ptr, int len){
    int small=*ptr;
    int large=*ptr;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            int ele=*(ptr+i*len+j);
            if (small > ele)
            {
                small= ele;
            }
            else if (large < ele)
            {
                large= ele;
            }        
        }
    }
    printf("Largest element %d smallest element %d .",large,small);
}
int main(){
    int len=0;
    printf("Enter matrix size : ");
    scanf("%d",&len);
    int matrix[len][len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("Enter number [%d][%d] :",i,j);
            scanf("%d",&matrix[i][j]);
        }       
    }
    largeSmall(&matrix[0][0],len);
    return 0;
}