/*
    103.Program to demonstrate use of strcmp() function
*/
#include <stdio.h>
#include <string.h>
int main(){
    char str1[]="abc\0";
    char str2[]="cab\0";
    char str3[]="abc\0";
    printf("ASCII str1 : %d %d %d\n",str1[0],str1[1],str1[2]);
    printf("ASCII str2 : %d %d %d\n",str2[0],str2[1],str2[2]);
    printf("ASCII str3 : %d %d %d\n",str3[0],str3[1],str3[2]);
    printf("str1 and str2 : %d\n",strcmp(str1,str2));
    printf("str2 and str3 : %d\n",strcmp(str2,str3));
    printf("str3 and str1 : %d\n",strcmp(str3,str1));
    return 0;
}