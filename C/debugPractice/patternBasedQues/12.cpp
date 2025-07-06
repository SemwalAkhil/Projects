//            *******
//             *   *
//              * *
//               *
// Inverted Hollow Pyramid Star Pattern
#include <iostream>
int main()
{
    int grid = 4;
    for (size_t i = 0, j = (2 * grid - 1); i < grid; i++, j -= 2)
    {
        for (size_t k = 0; k < j; k++)
        {
            if (k == 0)
            {
                for (size_t l = 0; l < i; l++)
                {
                    printf(" ");
                }
            }
            if (k == 0 || k == (j - 1) || i == 0)
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