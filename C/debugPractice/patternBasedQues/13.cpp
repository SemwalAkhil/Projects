//            *
//            **
//            ***
//            ****
//            ***
//            **
//            *
// Half Diamond Star Pattern
#include <iostream>
int main()
{
    int width = 4;
    int i = 1, dec = 0;
    do
    {
        for (size_t j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
        if (i == width)
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

    } while (i != 0);
}