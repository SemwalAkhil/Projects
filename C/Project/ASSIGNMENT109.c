/*
    109. Write a program to check whether entered string is palindrome or not
*/
#include <stdio.h>
int checkPallindrome(char str[]){
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    len--;
    for (int i = 0; i < ((len+1)/2); i++)
    {
        if (str[i] != str[len])
        {
            return 0;                  
        }
        len--;
    }
    return 1;
    
}
int main(){
    int len=0;
    printf("Enter string size : ");
    scanf("%d",&len);
    getchar();
    char str[len];
    printf("Enter String :");
    gets(str);
    printf("%s \n",checkPallindrome(str)?"pallindrome":"not pallindrome");
    return 0;
}