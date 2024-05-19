/*
112.Program to count number of words in file
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *f1;
    char ch;
    int wcount=0,chk=0;
    f1=fopen("f1.txt","r");
    if(f1==NULL){
    printf("Error in opening the file \n");
    return 0;
    }
    while((ch=fgetc(f1))!=EOF){
        if(ch==' ' || ch=='\t' || ch=='\n'){
           chk=0;
        }
        else if (chk==0)
        {
           wcount++;
           chk=1;
        }    
    }
printf("Words in file : %d",wcount);  
fclose(f1);  
return 0;
}