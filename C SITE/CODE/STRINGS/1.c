// 1. ENTER THE STRING FROM USER AND CONVERT IN UPPERCASE ?
#include <stdio.h>
void upper(char *arr)
{
    for (int i = 0; arr[i] != 0; i++)
    {
        if ((arr[i] >= 'a') && (arr[i] <= 'z'))
        {
            arr[i] = arr[i] - 32;
        }
    }
}
int main()
{
    char *string[100];
    printf("Enter a string : ");
    gets(string);
    upper(string);
    puts(string);
    return 0;
}