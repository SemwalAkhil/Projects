// 12. ENTER THE STRING FROM THE USER AND PRINT EACH CHARACTER IN NEW LINE ?
#include <stdio.h>
int main()
{
    char str[100];
    printf("Enter string : ");
    gets(str);
    for (int i = 0; str[i] != 0; i++)
    {
        printf("%c\n", str[i]);
    }

    return 0;
}