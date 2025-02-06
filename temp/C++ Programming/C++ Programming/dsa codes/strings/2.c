// 2. ENTER THE STRING FROM USER AND CONVERT IN LOWERCASE ?
#include <stdio.h>
void lower(char *arr)
{
    for (int i = 0; arr[i] != 0; i++)
    {
        if ((arr[i] >= 'A') && (arr[i] <= 'Z'))
        {
            arr[i] = arr[i] + 32;
        }
    }
}
int main()
{
    char string[100];
    printf("Enter a string : ");
    gets(string);
    lower(string);
    puts(string);
    return 0;
}