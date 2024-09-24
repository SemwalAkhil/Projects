// 4. CONVERT A NUMBER INTO BINARY USING RECURSION
#include <stdio.h>
int binary(int num)
{
    if ((num / 2) > 0)
    {
        return (num % 2) + (binary(num / 2) * 10);
    }
    return 1;
}
int main()
{
    int num;
    printf("ENTER A NUMBER : ");
    scanf("%d", &num);
    printf("BINARY OF %d : %d", num, binary(num));
    return 0;
}