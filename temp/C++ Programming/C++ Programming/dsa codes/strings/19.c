#include <stdio.h>
#define maxSize 100
float strToInt(char str[maxSize])
{
    float result = 0;
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
    printf("Sum of ASCII's in string : %f", strToInt(str));
    return 0;
}