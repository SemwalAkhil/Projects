// 4. Enter two Matrices from user, multiply the matrices and display the answer?
#include <stdio.h>
#define rows 100
#define cols 100
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
void mulMat(int r1, int c1, int mat1[rows][cols], int r2, int c2, int mat2[rows][cols])
{
    if (c1 == r2)
    {
        int result[rows][cols]; // if matrix size mismatch problem
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < c1; k++)
                {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        printMat(r1, c2, result);
    }
    else
    {
        printf("Invalid matrices for multiplication");
    }
}
int main()
{
    int mat1[rows][cols], mat2[rows][cols];
    int r1, c1, r2, c2;
    printf("ENTER DIMENSIONS OF MATRIX 1\n");
    printf("Enter number of rows : ");
    scanf("%d", &r1);
    printf("Enter number of columns : ");
    scanf("%d", &c1);
    printf("ENTER DIMENSIONS OF MATRIX 2\n");
    printf("Enter number of rows : ");
    scanf("%d", &r2);
    printf("Enter number of columns : ");
    scanf("%d", &c2);
    printf("MATRIX 1 :\n");
    getMat(r1, c1, mat1);
    printf("MATRIX 2 :\n");
    getMat(r2, c2, mat2);
    mulMat(r1, c1, mat1, r2, c2, mat2);
    return 0;
}