//               *
//              **
//             ***
//            ****
//             ***
//              **
//               *
// Half Diamond Star Pattern Inverted
#include <iostream>
int main()
{
    int grid = 4;
    int i = 1, dec = 0;
    do
    {
        for (size_t k = grid - i; k > 0; k--)
        {
            printf(" ");
        }

        for (size_t j = 0; j < i; j++)
        {
            printf("*");
        }
        if (i == grid)
        {
            dec = 1;
        }
        if (dec)
        {
            i--;
        }
        else
        {
            i++;
        }
        printf("\n");
    } while (i != 0);
}