/*
    115.Program to demonstrate input/output operations on a file using getc() and putc()
*/
#include <stdio.h>
int main(){
    FILE *fp;
    char ch;
    fp=fopen("f1.txt","w");
    printf("Enter text :");
    while ((ch = getchar()) != EOF)
    {
        putc(ch,fp);
    }
    fclose(fp);

    fp=fopen("f1.txt","r");
    while ((ch = getc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}