// Enter the Number of rows - 6
// Butterfly Pattern of 6 rows.
// *                         *
// * *                     * *
// * * *                 * * *
// * * * *             * * * *
// * * * * *         * * * * *
// * * * * * *     * * * * * *
// * * * * * * * * * * * * * *
// * * * * * *     * * * * * *
// * * * * *         * * * * *
// * * * *             * * * *
// * * *                 * * *
// * *                     * *
// *                         *
#include <iostream>
int main()
{
    int rows = 6, count = 1;
    for (size_t i = 0; i <= (2 * rows); i++)
    {
        for (size_t i = 0; i <= (2 * rows + 1); i++)
        {
            if (i < count || i > (2 * rows + 1 - count))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        if (i < rows)
        {
            count++;
        }
        else
        {
            count--;
        }

        printf("\n");
    }
}