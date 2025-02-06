// 3. CALCULATE THE SUM OF NATURAL NUMBERS TILL 10 USING RECURSION.
#include <stdio.h>
int sum(int i)
{
    if (i > 0)
    {
        return i + sum(i - 1);
    }
    return 0;
}
int main()
{
    printf("SUM OF FIRST 10 NATURAL NUMBERS : %d", sum(10));
    return 0;
}