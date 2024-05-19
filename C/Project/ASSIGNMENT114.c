/*
114.Program to display contents of a file on a screen
*/
#include<stdio.h>
int main(){
    FILE *f1;
    char ch;
    f1=fopen("f1.txt","r");
    if(f1==NULL){
    printf("Error in opening the file \n");
    return 0;
    }
    printf("Contemt of the file : ");
    while((ch=fgetc(f1))!=EOF){
        printf("%c",ch);
    }      
    fclose(f1);  
    return 0;
}