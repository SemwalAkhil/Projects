#include <stdio.h>
#define maxSize 100
int strToInt(char str[maxSize])
{
    int result = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        result += str[i];
    }
    return result;
}
int main()
{
    char str[maxSize];
    printf("Enter string : ");
    gets(str);
    printf("Sum of ASCII's in string : %d", strToInt(str));
    return 0;
}