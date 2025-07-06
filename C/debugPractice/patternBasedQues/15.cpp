//              *
//             ***
//            *****
//           *******
//            *****
//             ***
//              *
// Diamond Star Pattern
#include <iostream>
int main()
{
    int width = 4, dec = 0;
    for (size_t i = 0, j = 1; i < (2 * width - 1); i++)
    {
        // point of change
        if (i == width)
        {
            dec = 1;
            j -= 2;
        }
        // increasing pyramid
        if (!dec)
        {
            for (size_t k = 0; k < j; k++)
            {
                if (k == 0)
                {
                    for (size_t l = width - 1; l > i; l--)
                    {
                        printf(" ");
                    }
                }
                printf("*");
            }
            j += 2;
        }
        // decreasing pyramid
        else
        {
            j -= 2;
            for (size_t k = 0; k < j; k++)
            {
                if (k == 0)
                {
                    for (size_t l = width - 1; l < i; l++)
                    {
                        printf(" ");
                    }
                }
                printf("*");
            }
        }
        printf("\n");
    }
}