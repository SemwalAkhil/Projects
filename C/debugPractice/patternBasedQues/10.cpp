//               *
//              * *
//             *   *
//            *******
// Hollow Pyramid Star Pattern
#include <iostream>
int main()
{
    int grid = 4;
    for (size_t i = 0, j = 1; i < grid; i++, j += 2)
    {
        for (int k = 0; k < j; k++)
        {
            if (k == 0)
            {
                for (int l = 0; l < (grid - i); l++)
                {
                    printf(" ");
                }
            }
            if (k == 0 || k == (j - 1) || i == (grid - 1))
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