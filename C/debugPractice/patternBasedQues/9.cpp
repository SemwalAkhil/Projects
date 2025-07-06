//               *
//              ***
//             *****
//            *******
// Pyramid Star Pattern
#include <iostream>
int main()
{
    int grid = 4;
    for (size_t i = 0, j = 1; i < grid; i++, j += 2)
    {
        for (size_t k = 0; k < j; k++)
        {
            if (k == 0)
            {
                for (int l = 0; l < (grid - i - 1); l++)
                {
                    printf(" ");
                }
            }
            printf("*");
        }
        printf("\n");
    }
}