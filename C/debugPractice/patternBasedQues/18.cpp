//            333
//            313
//            323
//            333
// Internal varsity square Pattern
#include <iostream>
int main()
{
    int grid = 10;
    for (size_t i = 0; i < grid; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (i == 0 || j == 0 || i == grid - 1 || j == 2)
            {
                printf("%d", 3);
            }
            else
            {
                printf("%d", i);
            }
        }
        printf("\n");
    }
}
