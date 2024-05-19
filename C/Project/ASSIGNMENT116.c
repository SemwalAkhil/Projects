/*
116.Program to represent reading and writing to file using fprintf() and fscanf()
*/
#include<stdio.h>
int main(){
    FILE *f1,*f2;
    char ch[100];
    f1=fopen("f1.txt","w");
    f2=fopen("f1.txt","r");     
    printf("Enter the name : ");
    scanf("%s",ch);
    fprintf(f1,"%s",ch);
    fscanf(f2,"%s",ch);
    printf("Name : %s",ch);
    fclose(f1);  
    fclose(f2);
    return 0;
}