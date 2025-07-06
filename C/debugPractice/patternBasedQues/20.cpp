//     10987
//     654
//     32
//     1
// Basic Right Triangle Number Pattern(Inverted)
#include <iostream>
int main()
{
    int rows = 4, count = 1;
    for (size_t i = 2; i <= rows; i++)
    {
        count += i;
    }

    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = rows - i + 1; j > 0; j--)
        {
            printf("%d", count--);
        }
        printf("\n");
    }
}