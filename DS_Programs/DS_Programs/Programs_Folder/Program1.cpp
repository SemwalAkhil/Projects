// Enter a matrix of 4 rows and 2 columns from the user display it in matrix format

#include<stdio.h>

int main()
{
    int a[4][2], i,j;

    printf("Enter 8 elements of the matrix: \n");
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            printf("Enter element a[%d][%d]: ", (1+i), (1+j));
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMatrix is: \n");
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}