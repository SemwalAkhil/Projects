#include <stdio.h>
#include <string.h>

void replaceWord(char *sentence, char *oldWord, char *newWord) {
    char result[200] = "";
    char *ptr = strstr(sentence, oldWord);
    while (ptr != NULL) {
        strncat(result, sentence, ptr - sentence);
        strcat(result, newWord);
        sentence = ptr + strlen(oldWord);
        ptr = strstr(sentence, oldWord);
    }
    strcat(result, sentence);
    strcpy(sentence, result);
}

int main() {
    char sentence[200], oldWord[50], newWord[50];
    printf("Enter a sentence: ");
    gets(sentence);
    printf("Enter word to replace: ");
    gets(oldWord);
    printf("Enter new word: ");
    gets(newWord);
    replaceWord(sentence, oldWord, newWord);
    printf("Updated sentence: %s", sentence);
    return 0;
}
