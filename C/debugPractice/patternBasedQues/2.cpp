/*
****
*  *
*  *
****
*/
#include <iostream>
int main()
{
    int grid = 4;
    for (int i = 0; i < grid; i++)
    {
        for (int j = 0; j < grid; j++)
        {
            if (i == 0 || j == 0 || i == (grid - 1) || j == (grid - 1))
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