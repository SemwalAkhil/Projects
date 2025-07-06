//            *
//            **
//            ***
//            ****
// Triangle Star Pattern
#include <iostream>
int main()
{
    int grid = 4;
    for (int i = 0; i < grid; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}