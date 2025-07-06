//            *******
//             *****
//              ***
//               *
// Inverted Pyramid Star Pattern
#include <iostream>
/*
    1 3 5 7
    tn = a + (n-1)d
        1 + 2n -2
        2n - 1
*/
int main()
{
    int grid = 4;
    for (size_t i = 0, j = (2 * grid - 1); i < grid; i++, j -= 2)
    {
        for (int k = 0; k < j; k++)
        {
            if (k == 0)
            {
                for (size_t l = 0; l < i; l++)
                {
                    printf(" ");
                }
            }
            printf("*");
        }
        printf("\n");
    }
}