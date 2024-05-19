/*
    99.Program to demonstrate printing of a string
*/
#include <stdio.h>
int main(){
    char str[]="abc\0";
    char *ptr = str;
    for (int i = 0; i < 3; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
    while (*ptr != '\0'){
        printf("%c",*ptr);
        ptr++;
    }
    printf("\n");
    int i =0;
    while (str[i] != '\0'){
        printf("%c",str[i]);
        i++;
    }
    printf("\n%s",str);
    return 0;
}