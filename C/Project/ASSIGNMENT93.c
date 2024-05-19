/*
    93.Program demonstrating two dimensional arrays (MATRIX)
*/
#include <stdio.h>
int display(int* matrix,int size_x,int size_y){
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            printf("%d ",*matrix);
            *matrix++;
        }
        printf("\n");
        
    }
    
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
    display(&matrix[0][0],len,len);
    return 0;
}