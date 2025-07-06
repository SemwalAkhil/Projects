//            1111
//            2222
//            3333
//            4444
// Basic Square incrementing Pattern
#include <iostream>
int main()
{
    int grid = 4;
    for (size_t i = 0; i < grid; i++)
    {
        for (size_t j = 0; j < grid; j++)
        {
            printf("%d", i + 1);
        }
        printf("\n");
    }
}