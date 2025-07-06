//            1
//            23
//            456
//            78910
// Basic Right Triangle Number Pattern
#include <iostream>
int main()
{
    int rows = 4, count = 1;
    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = 0; j < i; j++, count++)
        {
            printf("%d", count);
        }
        printf("\n");
    }
}