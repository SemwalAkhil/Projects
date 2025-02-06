#include <stdio.h>
#include <string.h>

typedef struct {
    char word[50];
    char meaning[100];
} Dictionary;

void createEntry(Dictionary *dict, int *size, char *word, char *meaning) {
    strcpy(dict[*size].word, word);
    strcpy(dict[*size].meaning, meaning);
    (*size)++;
}

void deleteEntry(Dictionary *dict, int *size, char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            for (int j = i; j < *size - 1; j++) {
                dict[j] = dict[j + 1];
            }
            (*size)--;
            break;
        }
    }
}

void searchEntry(Dictionary *dict, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            printf("Meaning of %s: %s\n", word, dict[i].meaning);
            return;
        }
    }
    printf("Word not found\n");
}

int main() {
    Dictionary dict[10];
    int size = 0;
    createEntry(dict, &size, "hello", "A greeting");
    createEntry(dict, &size, "world", "The earth");

    printf("Dictionary created with words:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", dict[i].word, dict[i].meaning);
    }

    deleteEntry(dict, &size, "hello");
    printf("After deleting 'hello':\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", dict[i].word, dict[i].meaning);
    }

    searchEntry(dict, size, "world");

    return 0;
}
