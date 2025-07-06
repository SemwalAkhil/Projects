/*
******
******
******
******
*/
#include <iostream>
int main()
{
    int row = 4;
    int col = 6;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j == 0)
            {
                for (int k = 0; k < i; k++)
                {
                    printf(" ");
                }
            }
            printf("*");
        }
        printf("\n");
    }
}