//            1111
//            1111
//            1111
//            1111
// Basic Square 1 Pattern
#include <iostream>
int main()
{
    int grid = 4;
    for (size_t i = 0; i < grid; i++)
    {
        for (size_t j = 0; j < grid; j++)
        {
            printf("%d", 1);
        }
        printf("\n");
    }
}