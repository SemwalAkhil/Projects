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
    for (int i = 0; i < grid; i++)
    {
        for (int j = 0; j < grid; j++)
        {
            if (j == 0)
            {
                for (int k = 0; k < i; k++)
                {
                    printf(" ");
                }
            }
            printf("*");
        }
        printf("\n");
    }
}