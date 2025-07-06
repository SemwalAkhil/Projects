/*
******
*    *
*    *
******
*/
#include <iostream>
int main()
{
    int row = 4;
    int col = 5;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || j == 0 || i == (row - 1) || j == (col - 1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}