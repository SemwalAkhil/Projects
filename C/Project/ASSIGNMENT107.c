/*
    107.Write a program that reads a string and counts number of vowels and words present in a string
*/
#include <stdio.h>
int vowelCount(char str[]){
    int i = 0, j = 0, count = 0;
    char vowels[]="aeiouAEIOU\0";
    while (str[i] != '\0'){
        // printf("l1 i = %d\n",i);
        j=0;
        while (vowels[j] != '\0')
        {
            // printf("l2 j = %d\n",j);
            if (str[i] == vowels[j]){
                count++;
                // printf("count = %d\n",count);
                break;
            }
            j++;
        }
        i++;
    }
    return count;
}
int wordCount(char str[]){
    int i = 0, count = 1;
    while (str[i] != '\0'){
        if ((str[i] == ' ') && (str[i+1] != ' ')){
            count++;
        }
        i++;
    }
    return count;
}
int main(){
    int len=0;
    printf("Enter string size : ");
    scanf("%d",&len);
    getchar();
    char str[len];
    printf("Enter String :");
    gets(str);
    printf("Vowel : %d \n",vowelCount(str));
    printf("Word : %d \n",wordCount(str));
    return 0;
}