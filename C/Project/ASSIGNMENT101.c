/*
    101.Program to demonstrate use of strcpy() function
*/
#include <stdio.h>
#include <string.h>
int main(){
    char str[]="abc\0";
    char strNew[10];
    strcpy(strNew,str);

    printf("%s\n",str);
    printf("%s\n",strNew);

    return 0;
}