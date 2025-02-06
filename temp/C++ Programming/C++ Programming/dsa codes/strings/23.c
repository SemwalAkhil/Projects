#include <stdio.h>
#include <string.h>

int countWord(char *sentence, char *word) {
    int count = 0;
    char *ptr = strstr(sentence, word);
    while (ptr != NULL) {
        count++;
        ptr = strstr(ptr + 1, word);
    }
    return count;
}

int main() {
    char sentence[200], word[50];
    printf("Enter a sentence: ");
    gets(sentence);
    printf("Enter a word to count: ");
    gets(word);
    printf("Occurrence of '%s': %d", word, countWord(sentence, word));
    return 0;
}
