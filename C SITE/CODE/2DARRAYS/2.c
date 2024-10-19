// 2. Enter two Matrices from user, add the matrices and display the answer?
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
void addMat(int r, int c, int mat1[rows][cols], int mat2[rows][cols])
{
    int result[rows][cols];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printMat(r, c, result);
}
int main()
{
    int mat1[rows][cols], mat2[rows][cols];
    int r, c;
    printf("ENTER DIMENSIONS OF MATRICES\n");
    printf("Enter number of rows : ");
    scanf("%d", &r);
    printf("Enter number of columns : ");
    scanf("%d", &c);
    printf("MATRIX 1 :\n");
    getMat(r, c, mat1);
    printf("MATRIX 2 :\n");
    getMat(r, c, mat2);
    addMat(r, c, mat1, mat2);
    return 0;
}