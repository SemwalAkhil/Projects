#include <stdio.h>
int main()
{
    int x = 10;
    switch (x > 1)
    {
    case 50:
        printf("50\n");
    case 10:
        printf("10\n");
    case 20:
        printf("20\n");
    case 30:
        printf("30\n");
    case 0:
        printf("0\n");
    case 1:
        printf("1\n");
    default:
        printf("default\n");
    }
}