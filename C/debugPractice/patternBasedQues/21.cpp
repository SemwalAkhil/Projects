//            6666
//            555
//            44
//            3
// Basic incrementing Triangle Pattern initialised = 3
#include <stdio.h>
int main()
{
    int rows = 4;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = rows - i; j > 0; j--)
        {
            printf("%d", 3 + rows - i - 1);
        }
        printf("\n");
    }
}