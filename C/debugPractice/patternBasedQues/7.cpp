/*
   ****
  ****
 ****
****
*/
#include <iostream>
int main()
{
    int grid = 4;
    for (size_t j = 0; j < grid; j++)
    {
        for (size_t i = 0; i < grid; i++)
        {
            if (i == 0)
            {
                for (size_t k = 4; k > j; k--)
                {
                    printf(" ");
                }
            }
            printf("*");
            
        }
        printf("\n");
    }
}