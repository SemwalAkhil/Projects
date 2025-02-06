// 1. Enter a matrix of 4 rows and 2 columns from the user display it in matrix format?
#include <stdio.h>
#define rows 4
#define cols 2
void getMat(int r, int c, int mat[rows][cols])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter array element [%d][%d] : ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void printMat(int r, int c, int mat[rows][cols])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int mat[rows][cols];
    getMat(rows, cols, mat);
    printMat(rows, cols, mat);
    return 0;
}