/*
    111.Program to copy contents of one file to another
*/
#include <stdio.h>
int main(){
    FILE *fp;
    char ch;
    char str[1000];
    int i = 0;

    // reading content from file 1
    fp=fopen("f1.txt","r");
    while (1)
    {
        ch=fgetc(fp);
        if (ch == EOF)
        {
            break;
        }
        // printing file 1
        printf("%c",ch);
        str[i] = ch;
        i++;
    }
    fclose(fp);

    printf("\n");
    
    // writing content to file 2
    fp=fopen("f2.txt","w");
    for (int j = 0; j < i; j++)
    {
        putc(str[j],fp);
    }
    fclose(fp);

    fp=fopen("f2.txt","r");
    while (1)
    {
        ch=fgetc(fp);
        if (ch == EOF)
        {
            break;
        }
        // printing file 2
        printf("%c",ch);
        str[i] = ch;
        i++;
    }
    fclose(fp);
    
    return 0;
}