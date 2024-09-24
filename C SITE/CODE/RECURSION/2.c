// 2. CALCULATE FIBONACCI OF A NUMBER USING RECURSION
#include <stdio.h>
int fibonacci(int i, int j, int size)
{
    if (size >= 1)
    {
        printf("%d ", i);
        return fibonacci(j, i + j, size - 1);
    }
    return 1;
}
int main()
{
    int i, j, len;
    printf("ENTER LENGTH OF FIBONACCI : ");
    scanf("%d", &len);
    printf("ENTER FIRST NUMBER : ");
    scanf("%d", &i);
    printf("ENTER FIRST NUMBER : ");
    scanf("%d", &j);
    fibonacci(i, j, len);
    return 0;
}